#pragma once
#include <stdbool.h>


struct Message {
    char content[500];
    int receiver_id;
    int sender_id;
    int date;
    bool viewed;

};

struct Messages {
    struct Message messages[300];
    int receiver_id;
    int amount;
};


void sendMessage(struct Message messages);
void deleteMessage(struct Message message);
struct Message getUnread(int receiver);
void getAllUserMessages(int receiver);
void getAllMessages();
struct Message unserializeMessage(char * buff);

