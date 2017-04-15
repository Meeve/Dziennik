#include <stdio.h>
#include "fileConfig.h"

struct ConfStruct getConfUserStruct(char * fileName) {
	FILE *fp;
	struct ConfStruct confStuct;

	fp = fopen(fileName, "r");
	char buff[255];

	fgets(buff, 255, fp);

	confStuct.lastId = atoi(strtok(buff, ","));
	confStuct.amount = atoi(strtok(NULL, ","));

	fclose(fp);

	return confStuct;
}

void updateConfUserStruct(struct ConfStruct conf, char * fileName) {
	FILE *fp;
	fp = fopen(fileName, "w");

	char buff[64];

	itoa(conf.lastId, buff, 10);
	fputs(buff, fp);
	fputs(",", fp);

	itoa(conf.amount, buff, 10);
	fputs(buff, fp);

	fclose(fp);
}