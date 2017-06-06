#include "message.h"
#include "user.h";
#include "authorization.h"

char * getUserName(struct Users users, int id) {
	for (int i = 0; i < users.amount; i++) {
		if (users.users[i].id == id) {
			return users.users[i].name;
		}
	}
	return "Brak uzytkownika o podanym id";
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
	} else {
		strcat(outputMessage, " - brak nieprzeczytanych");
	}

	return outputMessage;
}

int getMessage() {
	struct User loggedUser = getLoggedUser();
	struct Messages messages = getAllMessages(loggedUser.id);
	struct Users users = getAllUsers();

	for (int i = 0; i < messages.amount; i++) {
		printf("%d. %s \n", loggedUser.id, getUserName(users, messages.messages[i].sender_id));
	}
	return 1;
}
