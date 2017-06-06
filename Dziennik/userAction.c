#include <stdio.h>
#include <string.h>
#include "teacherAction.h"
#include "action.h"
#include "user.h"
#include "authorization.h";


struct Actions getNotLoggedUserActions() {
	struct Actions notLoggedActions;
	notLoggedActions.amount = 0;

	notLoggedActions.actions[0].getText = loginText;
	notLoggedActions.actions[0].func = login;
	notLoggedActions.amount++;

	notLoggedActions.actions[1].getText = finishText;
	notLoggedActions.actions[1].func = finish;
	notLoggedActions.amount++;

	return notLoggedActions;
}