#include "user.h";

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
}

int getGrades() {
	printf("TODO Grades \n");
	return 1;
}
