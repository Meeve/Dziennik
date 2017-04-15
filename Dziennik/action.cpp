#include <stdio.h>
#include "action.h"

void printfActions(struct Actions actions) {
	printf("Podaj numer akcji, aby kontynuowac \n");
	for (int i = 0; i < actions.amount; i++) {
		printf("%d. %s \n", i + 1, actions.actions[i].text);
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
}