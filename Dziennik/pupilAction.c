#include "teacherAction.h";
#include "user.h";
#include "action.h";
#include "elementsListing.h";
#include "authorization.h";


struct Actions getPupilActions() {
	struct Actions pupilActions;
	pupilActions.amount = 0;

	pupilActions.actions[0].getText = getTeachersText;
	pupilActions.actions[0].func = getTeachers;
	pupilActions.amount++;

	pupilActions.actions[1].getText = getPupilsText;
	pupilActions.actions[1].func = getPupils;
	pupilActions.amount++;

	pupilActions.actions[2].getText = getGradesText;
	pupilActions.actions[2].func = getGrades;
	pupilActions.amount++;

	pupilActions.actions[3].getText = logoutText;
	pupilActions.actions[3].func = logout;
	pupilActions.amount++;

	return pupilActions;
}