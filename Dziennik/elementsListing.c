#include "user.h"
#include "grades.h"
#include "log.h"
#include "authorization.h"
#include "action.h"

char * getTeachersText() {
	return "Wyswietl liste nauczycieli";
}

int getTeachers() {
	struct Users users = getAllUsers();
	for (int i = 0; i < users.amount; i++) {
		if (users.users[i].privilage == 1) {
			printf("%d. %s \n", (i + 1), users.users[i].name);
		}
	}
	return 1;
}

char * getPupilsText() {
	return "Wyswietl liste uczniow";
}

int getPupils() {
	struct Users users = getAllUsers();
	for (int i = 0; i < users.amount; i++) {
		if (users.users[i].privilage == 2) {
			printf("%d. %s \n", (i + 1), users.users[i].name);
		}
	}
	return 1;
}

char * getGradesText() {
	return "Wyswietl oceny";

	struct User user = getLoggedUser();
	struct Log log;
	log.user_id = user.id;
	strcpy(log.action, "Poprawnie sie zalogowano");
	saveLog(log);

}



int getGrades() {
	struct User user = getLoggedUser();
	printfGrades(user.id);

	return 1;
}

int printfGrades(user_id) {
	struct Grades grades = getGradesFromUser(user_id);
	float sum = 0;

	if (grades.amount > 0) {
		printf("Oceny ucznia to: ");
	}
	
	for (int i = 0; i < grades.amount; i++) {
		printf("%d", grades.grades[i].value);
		sum += grades.grades[i].value;

		if (i + 1 != grades.amount) {
			printf(", ", sum);
		}
	}
	printf("\n", sum);

	if(grades.amount > 0) {
		
		printf("Srednia ucznia to: %f \n", sum / grades.amount);
	} else {
		printf("Uczen niema ocen \n");
	}

	return 1;
}

char * printfLogsText() {
	return "Wyswietl logi systemowe";
}

int printfLogs() {
	struct Logs logs = getAllLogs();
	struct Users users = getAllUsers();

	for (int i = logs.amount - 1; i >= 0; i--) {
		if (logs.logs[i].user_id != 0) {
			printf("%s. %s \n", getUserName(users, logs.logs[i].user_id), logs.logs[i].action);
		} else {
			//printf("Uzytkownik nie byl zalogowany. %s \n", logs.logs[i].action);
		}
	}
	return 1;
}