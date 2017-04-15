#pragma once

struct User {
	char     name[255];
	char     login[255];
	char     password[255];
	int     privilage;
	int     id;
};
struct Users {
	struct User	users[25];
	int		amount;
};

void addUser(struct User user);

struct User getUserByAuthData(char * login, char  * password);

struct User unserializeUser(char * buff);

struct Users getAllUsers();