#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "message.h"
#include "fileConfig.h"


void sendMessage(struct Message message) {
	struct ConfStruct confStuct = getConfUserStruct("messagesConf.txt");
	confStuct.lastId++;
	confStuct.amount++;
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

	itoa(confStuct.lastId, buff, 10);
	fputs(buff, file);
	fputs("$", file);
	fputs("\n", file);

    fclose(file);

	updateConfUserStruct(confStuct, "messagesConf.txt");
}

struct Message unserializeMessage(char *buff) {

    struct Message message;

    strcpy(message.content, strtok(buff, "$"));
    message.sender_id = atoi(strtok(NULL, "$"));
	message.receiver_id = atoi(strtok(NULL, "$"));
    message.date = atoi(strtok(NULL, "$"));
	message.viewed = atoi(strtok(NULL, "$"));
	message.id = atoi(strtok(NULL, "$"));

    return message;
}

int getUnread(int receiver_id) {
    FILE *fp;
    char buff[1000];
    struct Message message;
	int amount = 0;
    fp = fopen("messages.txt", "r");

    while (fgets(buff, 1000, fp)) {
        message = unserializeMessage(buff);

        if (message.receiver_id == receiver_id) {
            if (message.viewed == 0) {
				amount += 1;
            }
        }

    }
    fclose(fp);

	return amount;
}


struct Messages getAllMessages(int receiver_id) {
    FILE *fp;
    char buff[1000];
    struct Messages messages;
    messages.amount = 0;

    fp = fopen("messages.txt", "r");

    while (fgets(buff, 1000, fp)) {
		struct Message mess = unserializeMessage(buff);

		if (mess.receiver_id == receiver_id || receiver_id == 0) {
			messages.messages[messages.amount] = mess;
			messages.amount++;
		}
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
		struct Message mess = unserializeMessage(buff);
        if (mess.receiver_id == receiver_id) {
			messages.messages[messages.amount] = mess;
            messages.amount++;
        }
    }
    fclose(fp);
    return messages;
}

void deleteMessage(struct Message message) {

    struct Messages messages = getAllMessages(0);
    FILE *file;
    file = fopen("messages.txt", "w");
	char buff[255];

    for (int i = 0; i < messages.amount; i++) {
		if (messages.messages[i].date == message.date) {
            continue;
		}

        fputs(messages.messages[i].content, file);
        fputs("$", file);

        itoa(messages.messages[i].sender_id, buff, 10);
        fputs(buff, file);
        fputs("$", file);

        itoa(messages.messages[i].receiver_id, buff, 10);
        fputs(buff, file);
        fputs("$", file);

        itoa(messages.messages[i].date, buff, 10);
        fputs(buff, file);
        fputs("$", file);

        itoa(messages.messages[i].viewed, buff, 10);
        fputs(buff, file);

        fputs("\n", file);
    }

    fclose(file);


}