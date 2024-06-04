
#ifndef DATATYPES_H
#define DATATYPES_H

#define MAX_USERS 100
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50
#define NAME_LENGTH 100
#define NIF_LENGTH 20
#define ADDRESS_LENGTH 200
#define PHONE_LENGTH 20
#define DATE_LENGTH 11

typedef enum { ADMIN, AGENTE, CLIENTE } UserType;

typedef struct {
    char name[NAME_LENGTH];
    char nif[NIF_LENGTH];
    char address[ADDRESS_LENGTH];
    char phone[PHONE_LENGTH];
    int id;  // Sequential identifier
    char birthdate[DATE_LENGTH];
} AgentInfo;

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    UserType type;
    AgentInfo agentInfo; // Only filled if type is AGENTE
} User;

#endif // DATATYPES_H
