#pragma once

struct Action {
	char	text[255];
	int(*func)();
};

struct Actions {
	struct Action	actions[25];
	int		amount;
};

void printfActions(struct Actions actions);
int getUserChoose(int from, int to);