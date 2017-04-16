#include <stdio.h>
#include <stdlib.h>
#include "fileConfig.h"
#include "user.h"

void addUser(struct User user) {
	struct ConfStruct confStuct = getConfUserStruct("usersConf.txt");
	confStuct.lastId++;
	confStuct.amount++;

	char buff[64];

	FILE *fp;
	fp = fopen("users.txt", "a");

	fputs(user.name, fp);
	fputs(",", fp);

	fputs(user.login, fp);
	fputs(",", fp);

	fputs(user.password, fp);
	fputs(",", fp);

	itoa(user.privilage, buff, 10);
	fputs(buff, fp);
	fputs(",", fp);

	itoa(confStuct.lastId, buff, 10);
	fputs(buff, fp);
	fputs("\n", fp);

	fclose(fp);

	updateConfUserStruct(confStuct, "usersConf.txt");
}

struct User getUserByAuthData(char * login, char  * password) {
	FILE *fp;
	char buff[255];
	struct User user;
	fp = fopen("users.txt", "r");

	while (fgets(buff, 255, fp)) {
		user = unserializeUser(buff);

		if (strcmp(user.login, login) == 0 && strcmp(user.password, password) == 0) {
			fclose(fp);
			return user;
		}
	}

	fclose(fp);
	user.id = 0;
	return user;
}

struct User unserializeUser(char * buff) {
	struct User user;

	strcpy(user.name, strtok(buff, ","));
	strcpy(user.login, strtok(NULL, ","));
	strcpy(user.password, strtok(NULL, ","));
	user.privilage = atoi(strtok(NULL, ","));
	user.id = atoi(strtok(NULL, ","));
	return user;
}

struct Users getAllUsers() {
	FILE *fp;
	char buff[255];
	struct Users users;
	users.amount = 0;

	fp = fopen("users.txt", "r");

	while (fgets(buff, 255, fp)) {
		users.users[users.amount] = unserializeUser(buff);
		users.amount++;
	}

	fclose(fp);
	return users;
}

void editUser(struct User user) {
	struct Users users = getAllUsers();
	char buff[64];

	FILE *fp;
	fp = fopen("users.txt", "w");

	for (int i = 0; i < users.amount; i++) {
		if (users.users[i].id == user.id) {
			strcpy(users.users[i].name, user.name);
			strcpy(users.users[i].login, user.login);
			strcpy(users.users[i].password, user.password);
			users.users[i].privilage = user.privilage;
		}

		fputs(users.users[i].name, fp);
		fputs(",", fp);

		fputs(users.users[i].login, fp);
		fputs(",", fp);

		fputs(users.users[i].password, fp);
		fputs(",", fp);

		itoa(users.users[i].privilage, buff, 10);
		fputs(buff, fp);
		fputs(",", fp);

		itoa(users.users[i].id, buff, 10);
		fputs(buff, fp);
		fputs("\n", fp);
	}

	fclose(fp);
}