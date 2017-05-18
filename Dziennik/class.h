#pragma once

struct Class{

	int id;
	char name[255];
	char year[5];

};

struct Classes{

	struct Class classes[25];
	int amount;

};


void addClass(struct Class class);
struct Class UnserializeClass(char * buff);
void GetAllClasses();
void removeClass(struct Class class);
void editClass(struct Class class);
void classActions(); //wyświetla dostępne akcje dotyczące klas

