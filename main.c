#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "datatypes.h"
#include "functions.h"
#include "utils.h"

#ifdef _WIN32
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() system("clear")
#endif

void mainMenu(User users[], int *numUsers);
void agentMenu(); // Forward declaration of agent menu function

int main() {
    setlocale(LC_ALL, "Portuguese");

    User users[MAX_USERS];
    int numUsers = loadUsersFromFile(users); // Load users from file
    mainMenu(users, &numUsers); // Start with the main menu

    return 0;
}

void mainMenu(User users[], int *numUsers) {
    int choice, currentUserIndex = -1;

    do {
        printf("\n--- MENU INICIAL ---\n");
        printf("1. Login\n");
        printf("2. Criar conta\n");
        printf("3. Listar usuários\n"); // New option to list users
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                currentUserIndex = login(users, *numUsers);
                if (currentUserIndex >= 0) {
                    if (users[currentUserIndex].type == AGENTE) {
                        agentMenu();
                    }else if(users[currentUserIndex].type == ADMIN){
	                    adminMenu();
                    }else if(users[currentUserIndex].type == CLIENTE){
	                    clientMenu();
   
                }
                    // Add more menus for other user types if needed
                } else if (currentUserIndex == -2) {
                    signup(users, numUsers);
                }
                break;
            case 2:
                signup(users, numUsers);
                break;
            case 3:
                listUsers(users, *numUsers); // Call the function to list users
                break;
            case 4:
                saveUsersToFile(users, *numUsers);
                printf("A sair...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 4);
}
