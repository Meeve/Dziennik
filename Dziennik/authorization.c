#include "user.h";
#include "action.h";
#include "teacherAction.h";
#include "pupilAction.h";
#include "adminAction.h"
#include "log.h"

struct User loggedUser;

struct User getLoggedUser() {
	return loggedUser;
}

int finish() {
	return 0;
}

char * finishText() {
	return "Zakoncz";
}

int login() {
	struct Actions accessLayers[3];

	accessLayers[0] = getAdminActions(); 
	accessLayers[1] = getTeacherActions();
	accessLayers[2] = getPupilActions();

	struct User inputData;
	inputData.id = 0;

	printf("Podaj login\n");
	scanf("%s", &inputData.login);

	printf("Podaj haslo\n");
	scanf("%s", &inputData.password);

	loggedUser = getUserByAuthData(inputData.login, inputData.password);

	if (loggedUser.id != 0) {
		struct Log log;
		log.user_id = loggedUser.id;
		strcpy(log.action, "Poprawnie sie zalogowano");
		saveLog(log);
		
		printf("Udalo sie zalogowac \n \n");

		while (giveControlToAction(accessLayers[loggedUser.privilage]) != 0) {}
	}
	else {
		struct Log log;
		log.user_id = 0;
		strcpy(log.action, "Nie udalo sie zalogowac");
		saveLog(log);

		printf("Nie udalo sie zalogowac \n");
	}
	return 1;
}

char * loginText() {
	return "Zaloguj sie";
}


char * logoutText() {
	return "Wyloguj sie";
}

int logout() {
	return 0;
}

char * goBackText() {
	return "Wroc";
}
