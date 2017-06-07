#include "action.h"
#include "adminAction.h"
#include "authorization.h"
#include "elementsListing.h"

struct Actions getAdminActions() {
	struct Actions adminActions;
	adminActions.amount = 0;

	adminActions.actions[0].getText = printfLogsText;
	adminActions.actions[0].func = printfLogs;
	adminActions.amount++;

	adminActions.actions[1].getText = logoutText;
	adminActions.actions[1].func = logout;
	adminActions.amount++;

	return adminActions;
}