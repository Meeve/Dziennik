#pragma once

struct ConfStruct {
	int     amount;
	int     lastId;
};

struct ConfStruct getConfUserStruct(char * fileName);

void updateConfUserStruct(struct ConfStruct conf, char * fileName);

struct ConfStruct getConfClassStruct(char * fileName);

void updateConfClassStruct(struct ConfStruct conf, char * fileName);