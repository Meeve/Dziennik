#pragma once

struct User getLoggedUser();

int finish();
char * finishText();

int login();
char * loginText();

char * logoutText();
int logout();

char * goBackText();