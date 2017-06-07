#pragma once

struct Log {
	char action[500]; 
	int user_id;
	int id;
};

struct Logs {
	struct Log logs[300];
	int amount;
};

void saveLog(struct Log log);
struct Logs getAllLogs();