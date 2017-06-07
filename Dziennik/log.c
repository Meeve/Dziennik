#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileConfig.h"

void saveLog(struct Log log) {
	struct ConfStruct confStuct = getConfUserStruct("logsConf.txt");
	confStuct.lastId++;
	confStuct.amount++;
	char buff[64];

	FILE *file;
	file = fopen("logs.txt", "a");

	fputs(log.action, file);
	fputs("$", file);

	itoa(log.user_id, buff, 10);
	fputs(buff, file);
	fputs("$", file);

	itoa(confStuct.lastId, buff, 10);
	fputs(buff, file);

	fputs("\n", file);

	fclose(file);

	updateConfUserStruct(confStuct, "logsConf.txt");
}

struct Log unserializeLog(char *buff) {

	struct Log log;


	strcpy(log.action, strtok(buff, "$"));
	log.user_id = atoi(strtok(NULL, "$"));
	log.id = atoi(strtok(NULL, "$"));

	return log;
}

struct Logs getAllLogs() {
	FILE *fp;
	char buff[1000];
	struct Logs logs;
	logs.amount = 0;

	fp = fopen("logs.txt", "r");

	while (fgets(buff, 1000, fp)) {
		logs.logs[logs.amount] = unserializeLog(buff);
		logs.amount++;
	}

	fclose(fp);
	return logs;
}