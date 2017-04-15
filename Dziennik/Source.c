#include <stdio.h>
#include <stdlib.h>
#include "fileConfig.h"
#include "action.h"
#include "user.h"
#include "userAction.h"


int main() {
	struct Actions notLoggedActions = getNotLoggedUserActions();

	printfActions(notLoggedActions);
	int userChoose = getUserChoose(1, notLoggedActions.amount);

	while (notLoggedActions.actions[userChoose - 1].func() != 0) {
		printfActions(notLoggedActions);
		userChoose = getUserChoose(1, notLoggedActions.amount);
	}
}

 
// atoi - zamienia tekst na liczbe
// strtok - dzieli tekst po podanym znaku np: "kot,pies,kon" => strtok(",") => "kot" "pies" "kon". Pierwsze wywołanie przyjmuje tekst, każde kolejne zwraca kolejne słow  