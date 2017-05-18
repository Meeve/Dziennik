#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "wiadomsc.h"


void sendMessage(struct Message message) {

    char buff[64];

    FILE *file;
    file = fopen("messages.txt", "a");

    fputs(message.content, file);
    fputs("$", file);

    itoa(message.sender_id, buff, 10);
    fputs(buff, file);
    fputs("$", file);

    itoa(message.receiver_id, buff, 10);
    fputs(buff, file);
    fputs("$", file);


    message.date = time(NULL);
    itoa(message.date, buff, 10);
    fputs(buff, file);
    fputs("$", file);


    itoa(message.viewed, buff, 10);
    fputs(buff, file);
    fputs("$", file);


    fclose(file);

}

struct Message unserializeMessage(char *buff) {

    struct Message message;

    strcpy(message.content, strtok(buff, "$"));
    message.receiver_id = atoi(strtok(NULL, "$"));
    message.sender_id = atoi(strtok(NULL, "$"));
    message.date = atoi(strtok(NULL, "$"));
    message.viewed = atoi(strtok(NULL, "$"));
    return message;
}

struct Message getUnread(int receiver_id) {
    FILE *fp;
    char buff[1000];
    struct Message message;
    fp = fopen("messages.txt", "r");

    while (fgets(buff, 1000, fp)) {
        message = unserializeMessage(buff);

        if (message.receiver_id == receiver) {
            if (message.viewed == 0) {
                message.viewed = 1;
                fclose(fp);
                return message;
            }
        }

    }
    fclose(fp);
}


struct Messages getAllMessages() {
    FILE *fp;
    char buff[1000];
    struct Messages messages;
    messages.amount = 0;

    fp = fopen("messages.txt", "r");

    while (fgets(buff, 1000, fp)) {
        messages.messages[messages.amount] = unserializeMessage(buff);
        messages.amount++;
    }

    fclose(fp);
    return messages;
}

struct Messages getAllUserMessages(int receiver_id) {
    FILE *fp;
    char buff[255];
    struct Messages messages;
    messages.amount = 0;

    fp = fopen("messages.txt", "r");

    while (fgets(buff, 255, fp)) {
        if (messages.receiver_id == receiver_id) {
            messages.messages[messages.amount] = unserializeMessage(buff);
            messages.amount++;
        }
    }
    fclose(fp);
    return messages;
}

void deleteMessage(struct Message message) {

    struct Messages messages = getAllMessages();
    FILE *file;
    file = fopen("messages.txt", "w");

    for (i = 0; i < messages.amount; i++) {
        if (messages.messages[i].date == message.date)
            continue;

        fputs(messages.messages[i].content, file);
        fputs("$", file);

        itoa(messages.messages[i].sender_id, buffer, 10);
        fputs(buffer, file);
        fputs("$", file);

        itoa(messages.messages[i].receiver_id, buffer, 10);
        fputs(buffer, file);
        fputs("$", file);

        itoa(messages.messages[i].date, buffer, 10);
        fputs(buffer, file);
        fputs("$", file);

        itoa(messages.messages[i].viewed, buffer, 10);
        fputs(buffer, file);


        fputs("\n", file);
    }

    fclose(file);


}