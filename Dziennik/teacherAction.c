#include "teacherAction.h";
#include "user.h";
#include "action.h";
#include "messagesActions.h";
#include "elementsListing.h";

struct Actions getTeacherActions() {
	struct Actions teacherActions;
	teacherActions.amount = 0;

	teacherActions.actions[0].getText = getTeachersText;
	teacherActions.actions[0].func = getTeachers;
	teacherActions.amount++;

	teacherActions.actions[1].getText = getPupilsText;
	teacherActions.actions[1].func = getPupils;
	teacherActions.amount++;

	teacherActions.actions[2].getText = getMessageText;
	teacherActions.actions[2].func = getMessage;
	teacherActions.amount++;

	teacherActions.actions[3].getText = logoutText;
	teacherActions.actions[3].func = logout;
	teacherActions.amount++;

	return teacherActions;
}