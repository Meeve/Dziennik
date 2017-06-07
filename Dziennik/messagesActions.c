#include "message.h"
#include "user.h"
#include "authorization.h"
#include "action.h"


int activeMessageId = 0;


char * replyMessageText() {
	return "Odpowiedz na wiadomosc";
}

int replyMessage() {
	if (activeMessageId == 0) {
		printf("Podaj numer wiadomosci: \n");
		scanf("%d", &activeMessageId);
	}

	struct Message mess = getMessageById(activeMessageId);
	struct User loggedUser = getLoggedUser();

	struct Message newMessage;
	printf("Podaj tresc wiadomosci \n");
	scanf("%s", &newMessage.content);

	newMessage.sender_id = loggedUser.id;
	newMessage.receiver_id = mess.sender_id;

	sendMessage(newMessage);

	return 1;
}

struct Actions getMessageViewActions() {
	struct Actions messageViewActions;
	messageViewActions.amount = 0;

	messageViewActions.actions[0].getText = replyMessageText;
	messageViewActions.actions[0].func = replyMessage;
	messageViewActions.amount++;

	messageViewActions.actions[1].getText = goBackText;
	messageViewActions.actions[1].func = logout;
	messageViewActions.amount++;

	return messageViewActions;
}

char * showMessageText() {
	return "Wyswietl wiadomosc";
}

int showMesage() {
	struct Actions messageViewActions = getMessageViewActions();

	printf("Podaj numer wiadomosci \n");
	scanf("%d", &activeMessageId);

	struct Message mess = getMessageById(activeMessageId);
	markRead(mess.id);
	printf("%s \n", mess.content);

	while (giveControlToAction(messageViewActions) != 0) {}
}


struct Actions getMessageBaseActions() {
	activeMessageId = 0;
	struct Actions messageBaseActions;
	messageBaseActions.amount = 0;

	messageBaseActions.actions[0].getText = showMessageText;
	messageBaseActions.actions[0].func = showMesage;
	messageBaseActions.amount++;

	messageBaseActions.actions[1].getText = replyMessageText;
	messageBaseActions.actions[1].func = replyMessage;
	messageBaseActions.amount++;

	messageBaseActions.actions[2].getText = goBackText;
	messageBaseActions.actions[2].func = logout;
	messageBaseActions.amount++;

	return messageBaseActions;
}


char * getMessageText() {
	struct User loggedUser = getLoggedUser();
	int amount = getUnread(loggedUser.id);
	char outputMessage[255] = "Sprawdz wiadomosci ";
	char buff[10];

	if (amount != 0) {
		itoa(amount, buff, 10);

		strcat(outputMessage, " - nieprzeczytanych ( ");
		strcat(outputMessage, buff);
		strcat(outputMessage, " )");
	}
	else {
		strcat(outputMessage, " - brak nieprzeczytanych");
	}

	return outputMessage;
}

int getMessage() {
	struct User loggedUser = getLoggedUser();
	struct Messages messages = getAllMessages(loggedUser.id);
	struct Users users = getAllUsers();
	struct Actions messageViewActions = getMessageBaseActions();

	for (int i = 0; i < messages.amount; i++) {
		printf("%d. %s", messages.messages[i].id, getUserName(users, messages.messages[i].sender_id));

		if (messages.messages[i].viewed == 0) {
			printf(" - ( Nowa )");
		}

		printf(" \n");
	}

	while (giveControlToAction(messageViewActions) != 0) {}

	return 1;
}
