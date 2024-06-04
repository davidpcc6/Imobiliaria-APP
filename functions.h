#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "datatypes.h"

int login(User users[], int numUsers); // LOGIN
void signup(User users[], int *numUsers); // SIGNUP
void saveUsersToFile(User users[], int numUsers); // SALVAR OS USERS PARA O FICHEIRO
int loadUsersFromFile(User users[]); // CARREGAR OS USERS DO FICHEIRO
void agentMenu();
void adminMenu();
void clientMenu();
void listUsers(User users[], int numUsers);
int generateAgentId(User users[], int numUsers); // New function

#endif // FUNCTIONS_H
