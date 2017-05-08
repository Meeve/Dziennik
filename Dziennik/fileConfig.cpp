#include <stdio.h>
#include "fileConfig.h"
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


struct ConfStruct getConfClassStruct(char * fileName) {
	FILE *fp;
	struct ConfStruct confStruct;

	if (fp = fopen(fileName, "r") == NULL)
	printf("Nie udało się otworzyć pliku");
	
	char buff[255];

	fgets(buff, 255, fp);

	confStruct.lastId = atoi(strtok(buff, ","));
	confStruct.amount = atoi(strtok(NULL, ","));

	fclose(fp);

	return confStruct;
}

void updateConfClassStruct(struct ConfStruct conf, char * fileName) {
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

