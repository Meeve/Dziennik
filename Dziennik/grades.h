#pragma once


struct Grade {
	int user_id;
	int value;
	int id;
};

struct Grades {
	struct Grade grades[300];
	int amount;
};

struct Grades getGradesFromUser(int user_id);