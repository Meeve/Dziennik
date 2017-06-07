#include <stdio.h>
#include "action.h"
#include "user.h"

void printfActions(struct Actions actions) {
	printf("Podaj numer akcji, aby kontynuowac \n");
	for (int i = 0; i < actions.amount; i++) {
		printf("%d. %s \n", i + 1, actions.actions[i].getText());
	}
}


int getUserChoose(int from, int to) {
	int userChoose = from - 1;
	while (userChoose < from || userChoose > to) {
		scanf("%d", &userChoose);
		if (userChoose < from || userChoose > to) {
			printf("Zly numer akcji, podaj go raz jeszcze \n");
		}
	}
	return userChoose;
}

int giveControlToAction(struct Actions actions) {
	printfActions(actions);
	int userChoose = getUserChoose(1, actions.amount);

	return actions.actions[userChoose - 1].func();
}


char * getUserName(struct Users users, int id) {
	for (int i = 0; i < users.amount; i++) {
		if (users.users[i].id == id) {
			return users.users[i].name;
		}
	}
	return "Brak uzytkownika o podanym id";
}