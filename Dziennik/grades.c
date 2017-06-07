#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileConfig.h"
#include "grades.h"
#include "user.h"

void addGrade(struct Grade grade) {
	struct ConfStruct confStuct = getConfUserStruct("gradesConf.txt");
	confStuct.lastId++;
	confStuct.amount++;

	char buff[64];

	FILE *fp;
	fp = fopen("grades.txt", "a");

	itoa(grade.user_id, buff, 10);
	fputs(buff, fp);
	fputs("$", fp);

	itoa(grade.value, buff, 10);
	fputs(buff, fp);
	fputs("$", fp);

	itoa(confStuct.lastId, buff, 10);
	fputs(buff, fp);
	fputs("\n", fp);

	fclose(fp);

	updateConfUserStruct(confStuct, "gradesConf.txt");
}

struct Grade unserializeGrade(char * buff) {
	struct Grade grade;

	grade.user_id = atoi(strtok(buff, "$"));
	grade.value = atoi(strtok(NULL, "$"));
	grade.id = atoi(strtok(NULL, "$"));

	return grade;
}

struct Grades getGradesFromUser(int user_id) {
	FILE *fp;
	char buff[255];
	struct Grades grades;
	grades.amount = 0;

	fp = fopen("grades.txt", "r");

	while (fgets(buff, 255, fp)) {
		struct Grade grade = unserializeGrade(buff);
		if (grade.user_id == user_id) {
			grades.grades[grades.amount] = grade;
			grades.amount++;
		}
	}

	fclose(fp);
	return grades;
}

struct Grades getAllGrades() {
	FILE *fp;
	char buff[255];
	struct Grades grades;
	grades.amount = 0;

	fp = fopen("grades.txt", "r");

	while (fgets(buff, 255, fp)) {
		grades.grades[grades.amount] = unserializeGrade(buff);
		grades.amount++;
	}

	fclose(fp);
	return grades;
}

void deleteGrade(int id) {
	struct Grades grades = getAllGrades();
	char buff[64];

	FILE *fp;
	fp = fopen("grades.txt", "w");

	for (int i = 0; i < grades.amount; i++) {
		if (grades.grades[i].id == id) {
			continue;
		}

		itoa(grades.grades[i].user_id, buff, 10);
		fputs(buff, fp);
		fputs("$", fp);

		itoa(grades.grades[i].value, buff, 10);
		fputs(buff, fp);
		fputs("$", fp);

		itoa(grades.grades[i].id, buff, 10);
		fputs(buff, fp);
		fputs("\n", fp);
	}

	fclose(fp);
}