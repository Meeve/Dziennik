#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct User {
    char     name[255];
    char     login[255];
    char     password[255];
    int     privilage;
    int     id;
};
struct Action {
	char	text[255];
	void	(*func)();
};
struct Actions {
	struct Action	actions[25];
	int		amount;
};

struct User inputData;

struct Actions getNotLoggedUserActions();

void login();
void exit();

struct User unserializeUser(char  * buff);
void addUser(char *, char *);
char* getUsers();
struct User getUserByAuthData(char *, char *);

int main() {
	struct Actions notLoggedActions = getNotLoggedUserActions();
	printf("Podaj numer akcji, aby kontynuowac \n");

	for (int i = 0; i < notLoggedActions.amount; i++) {
		printf("%d. %s \n",i + 1 ,notLoggedActions.actions[i].text);
	}

	int userChoose;
	scanf("%d", &userChoose);
	notLoggedActions.actions[userChoose - 1].func();
}

struct Actions getNotLoggedUserActions() {
	struct Actions notLoggedActions;
	notLoggedActions.amount = 0;

	strcpy(notLoggedActions.actions[0].text, "Zaloguj sie");
	notLoggedActions.actions[0].func = login;
	notLoggedActions.amount++;

	strcpy(notLoggedActions.actions[1].text, "Zakoncz");
	notLoggedActions.actions[1].func = exit;
	notLoggedActions.amount++;

	return notLoggedActions;
}

void exit() {

}

void login() {
	struct User loggedUser;
	inputData.id = 0;

	while (inputData.id == 0) {
		printf("Podaj login\n");
		scanf("%s", &inputData.login);

		printf("Podaj haslo\n");
		scanf("%s", &inputData.password);

		loggedUser = getUserByAuthData(inputData.login, inputData.password);

		if (loggedUser.id != 0) {
			printf("Udalo sie zalogowac \n");
			printf(loggedUser.name);
		}
		else {
			printf("Nie udalo sie zalogowac \n");
		}
	}
}


void addUser(char * name, char  * surname) {
    FILE *fp;
    fp = fopen("users.txt", "a");

    fputs(name, fp);
    fputs(",", fp);
    fputs(surname, fp);
    fputs("\n", fp);

    fclose(fp);
} // TODO

struct User getUserByAuthData(char * login, char  * password) {
    FILE *fp;
    char buff[255];
    struct User user;
    fp = fopen("users.txt", "r");

    while(fgets(buff, 255, fp)) {
        user = unserializeUser(buff);

        if(strcmp(user.login, login) == 0 && strcmp(user.password, password) == 0) {
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
 


// atoi - zamienia tekst na liczbe
// strtok - dzieli tekst po podanym znaku np: "kot,pies,kon" => strtok(",") => "kot" "pies" "kon". Pierwsze wywołanie przyjmuje tekst, każde kolejne zwraca kolejne słow  