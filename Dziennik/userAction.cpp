#include "action.h"
#include "user.h"


struct User inputData;

int finish() {
	return 0;
}

int login() {
	struct User loggedUser;
	inputData.id = 0;

	printf("Podaj login\n");
	scanf("%s", &inputData.login);

	printf("Podaj haslo\n");
	scanf("%s", &inputData.password);

	loggedUser = getUserByAuthData(inputData.login, inputData.password);

	if (loggedUser.id != 0) {
		printf("Udalo sie zalogowac \n");
		printf(loggedUser.name);
	}
	else {
		printf("Nie udalo sie zalogowac \n");
	}
	return 1;
}

struct Actions getNotLoggedUserActions() {
	struct Actions notLoggedActions;
	notLoggedActions.amount = 0;

	strcpy(notLoggedActions.actions[0].text, "Zaloguj sie");
	notLoggedActions.actions[0].func = login;
	notLoggedActions.amount++;

	strcpy(notLoggedActions.actions[1].text, "Zakoncz");
	notLoggedActions.actions[1].func = finish;
	notLoggedActions.amount++;

	return notLoggedActions;
}