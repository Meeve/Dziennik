#include "elementsListing.h"
#include "grades.h"

char * addGradeToUserText() {
	return "Dodaj ocene";
}

int addGradeToUser() {
	struct Grade grade;
	
	printf("Prosze wybrac ucznia: \n");
	getPupils();
	scanf("%d", &grade.user_id);

	printf("Podaj ocene \n");
	scanf("%d", &grade.value);

	addGrade(grade);

	return 1;
}

char * getUserGradesText() {
	return "Wyswietl oceny";
}

int getUserGrades() {
	int user_id;

	printf("Prosze wybrac ucznia: \n");
	getPupils();
	scanf("%d", &user_id);

	printfGrades(user_id);
}