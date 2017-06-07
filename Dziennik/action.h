#pragma once

struct Action {
	char* (*getText)();
	int (*func)();
};

struct Actions {
	struct Action	actions[25];
	int		amount;
};

void printfActions(struct Actions actions);
int getUserChoose(int from, int to);
char * getUserName(struct Users users, int id);