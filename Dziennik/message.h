#pragma once
#include <stdbool.h>


struct Message {
	int id;
    char content[500];
    int receiver_id;
    int sender_id;
    int date;
    int viewed;
};

struct Messages {
    struct Message messages[300];
    int amount;
};


void sendMessage(struct Message messages);
void deleteMessage(struct Message message);
int getUnread(int receiver);
struct Messages getAllUserMessages(int receiver);
struct Messages getAllMessages(int receiver_id);
struct Message unserializeMessage(char * buff);
struct Message getMessageById(int id);