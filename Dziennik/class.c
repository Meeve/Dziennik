#include <stdio.h>
#include <stdlib.h>
#include "class.h"
#include "fileConfig.h"


void addClass(struct Class class)
{
	struct ConfStruct confStruct = getConfClassStruct("classesConf.txt");

	confStruct.lastId++;
	confStruct.amount++;

	FILE *file;
	file = fopen("classes.txt", "a");

	fputs(class.name, file);
	fputs(",", file);


	fputs(class.year, file);
	fputs(",", file);

	char buffer[20]; 
	itoa(confStruct.lastId, buffer, 10);

	fputs(buffer, file);
	fputs("\n", file);
	fclose(file);

	updateConfClassStruct(confStruct, "classesConf.txt");
	
}

void removeClass(struct Class class)
{
	struct Classes classes = GetAllClasses()

	

 
	
}

struct Class unserializeClass(char * buff) {
	struct Class class;

	strcpy(class.name, strtok(buff, ","));
	strcpy(class.year, strtok(NULL, ","));
	class.id = atoi(strtok(NULL, ","));
	return class;
}


void GetAllClasses()
{
	FILE * file
	char buffer[255];
	struct Classes classes;
	classes.amount = 0;
	file = fopen("classes.txt", "r");

	while(fgets(buffer,255,file)){
			classes.classes[classes.amount] = unserializeClass(buffer);
			classes.amount++;
	}
	fclose(file)
	return classes;

}
