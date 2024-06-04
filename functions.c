#include "functions.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Esta função escreve para o ficheiro o array Users

void saveUsersToFile(User users[], int numUsers) {
    FILE *file = fopen("C:\\Users\\divad\\Documents\\users.dat", "wb");
    if (!file) {
        perror("Erro ao abrir o ficheiro");
        return;
    }
    fwrite(users, sizeof(User), numUsers, file);
    fclose(file);
    printf("Os usuários foram salvos com sucesso.\n");
}

//Esta função lê 

int loadUsersFromFile(User users[]) {                                   
    FILE *file = fopen("C:\\Users\\divad\\Documents\\users.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o ficheiro.\n");
        return 0;
    }
    int numUsers = fread(users, sizeof(User), MAX_USERS, file);
    fclose(file);
    return numUsers;
}

int login(User users[], int numUsers) {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    char buffer[200];
    int i;

    printf("Digite seu username: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49s", username);

    printf("Digite sua senha: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49s", password);

    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            CLEAR_SCREEN();
            printf("Login bem sucedido!\n");
            return i;
        }
    }
    printf("Username ou senha incorretos. Deseja registrar-se? (S/N): ");
    fgets(buffer, sizeof(buffer), stdin);
    char choice = buffer[0];
    return (choice == 'S' || choice == 's') ? -2 : -1;
}

int generateAgentId(User users[], int numUsers) {
    int maxId = 0;
    int i;
    for (i = 0; i < numUsers; i++) {
        if (users[i].type == AGENTE && users[i].agentInfo.id > maxId) {
            maxId = users[i].agentInfo.id;
        }
    }
    return maxId + 1;
}

void signup(User users[], int *numUsers) {
    if (*numUsers >= MAX_USERS) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    char buffer[200];
    int userType;

    printf("Digite um novo username: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49s", users[*numUsers].username);

    printf("Digite uma palavra-passe: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49s", users[*numUsers].password);

    printf("Digite o tipo de usuário (0 - ADMIN, 1 - AGENTE, 2 - CLIENTE): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &userType);
    users[*numUsers].type = (UserType)userType;

    if (users[*numUsers].type == AGENTE) {
        printf("Digite seu nome: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%99[^\n]", users[*numUsers].agentInfo.name);

        printf("Digite seu NIF: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%19s", users[*numUsers].agentInfo.nif);

        printf("Digite sua morada: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%199[^\n]", users[*numUsers].agentInfo.address);

        printf("Digite seu contato telefônico: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%19s", users[*numUsers].agentInfo.phone);

        users[*numUsers].agentInfo.id = generateAgentId(users, *numUsers);

        printf("Digite sua data de nascimento (DD/MM/AAAA): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%10s", users[*numUsers].agentInfo.birthdate);
    }

    (*numUsers)++;
    printf("Conta criada com sucesso!\n");
}

void agentMenu() {
    int choice;
    do {
        printf("\n--- MENU DO AGENTE ---\n");
        printf("1. Gerir propriedades\n");
        printf("2. Agendar visitas\n");
        printf("3. Listar visitas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                // Implementar função de gerir propriedades
                printf("Gerir propriedades.\n");
                break;
            case 2:
                // Implementar função de agendar visitas
                printf("Agendar visitas.\n");
                break;
            case 3:
                // Implementar função de listar visitas
                printf("Listar visitas.\n");
                break;
            case 4:
                printf("Saindo do menu do agente...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 4);
}

void adminMenu() {
    int choice;
    do {
        printf("\n--- MENU DO ADMIN ---\n");
        printf("1. Gerir agentes\n");
        printf("2. Gerir clients\n");
        printf("3. Listar agentes\n");
        printf("4. Listar clientes\n");
        printf("5. Colocar agente como indisponivel\n");
        printf("6. Gerar relatório\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                // Implementar função de gerir propriedades
                printf("Gerir propriedades.\n");
                break;
            case 2:
                // Implementar função de agendar visitas
                printf("Agendar visitas.\n");
                break;
            case 3:
                // Implementar função de listar visitas
                printf("Listar visitas.\n");
                break;
            case 4:
                printf("Saindo do menu do agente...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 4);
}

void clientMenu() {
    int choice;
    do {
        printf("\n--- MENU DO CLIENTE ---\n"); 
        printf("1. Gerir propriedades\n");
        printf("2. Agendar visitas\n");
        printf("3. Listar visitas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                // Implementar função de gerir propriedades
                printf("Gerir propriedades.\n");
                break;
            case 2:
                // Implementar função de agendar visitas
                printf("Agendar visitas.\n");
                break;
            case 3:
                // Implementar função de listar visitas
                printf("Listar visitas.\n");
                break;
            case 4:
                printf("Saindo do menu do agente...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 4);
}

void listUsers(User users[], int numUsers) {
    int i; // Declare the variable outside the for loop
    printf("\n--- Lista de Usuários ---\n");
    for (i = 0; i < numUsers; i++) {
        printf("Usuário %d:\n", i + 1);
        printf("  Username: %s\n", users[i].username);
        printf("  Tipo: %s\n", (users[i].type == ADMIN) ? "ADMIN" :
                                (users[i].type == AGENTE) ? "AGENTE" : "CLIENTE");
        if (users[i].type == AGENTE) {
            printf("  Nome: %s\n", users[i].agentInfo.name);
            printf("  NIF: %s\n", users[i].agentInfo.nif);
            printf("  Morada: %s\n", users[i].agentInfo.address);
            printf("  Contato Telefônico: %s\n", users[i].agentInfo.phone);
            printf("  Identificador: %d\n", users[i].agentInfo.id);
            printf("  Data de Nascimento: %s\n", users[i].agentInfo.birthdate);
        }
    }
    printf("--------------------------\n");
}
