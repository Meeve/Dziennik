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

void editClass(struct Class class)
{
	struct Classes classes = GetAllClasses()
	FILE *file;
	file = fopen("classes.txt", "w")
	int i;
	char buffer[64];
	for (i = 0; i<classes.amount; i++)
	{
		if (classes.classes[i].id = class.id)
			{	strcpy(classes.classes[i].name, class.name);
				strcpy(classes.classes[i].year, class.year);



		}
		fputs(classes.classes[i].name, file);
		fputs(",", file);
		fputs(classes.classes[i].year, file);
		fputs(",", file);
		itoa(classes.classes[i].id, buffer, 10);
		fputs(buffer, file);
		fputs("\n", file);


	}


	fclose(file);
 
	
}


void removeClass(struct Class class)
{
	struct Classes classes = GetAllClasses()
	FILE *file;
	file = fopen("classes.txt", "w")

	for (i = 0; i<classes.amount; i++)
	{
		if (classes.classes[i].id = class.id)
			continue;


		fputs(classes.classes[i].name, file);
		fputs(",", file);
		fputs(classes.classes[i].year, file);
		fputs(",", file);
		itoa(classes.classes[i].id, buffer, 10);
		fputs(buffer, file);
		fputs("\n", file);
	}

	fclose(file);
}
