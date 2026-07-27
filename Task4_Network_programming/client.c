#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {

    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;

    char buffer[1024];

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("WSAStartup failed!\n");
        return 1;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket == INVALID_SOCKET){

        printf("Socket creation failed!\n");
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if(connect(client_socket,
               (struct sockaddr*)&server_addr,
               sizeof(server_addr)) == SOCKET_ERROR){

        printf("Connection failed!\n");

        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    printf("Connected to server!\n");

char username[100];
char password[50];

printf("Enter Username: ");
scanf("%99s", username);

printf("Enter Password: ");
scanf("%49s", password);

send(client_socket, username, strlen(username), 0);

int bytes;

bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
if (bytes > 0) {
    buffer[bytes] = '\0';
}

send(client_socket, password, strlen(password), 0);

bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
if (bytes > 0) {
    buffer[bytes] = '\0';
}

printf("%s\n", buffer);

    closesocket(client_socket);

    WSACleanup();

    return 0;
}