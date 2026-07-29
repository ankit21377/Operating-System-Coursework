#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <pthread.h>
#include "authentication.h"
#include "protocol.h"

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
void *handle_client(void *arg)
{
    SOCKET client_socket = *(SOCKET *)arg;
    free(arg);

    char username[100];
    char password[50];
    int bytes;

    // Receive Username
    bytes = receive_message(client_socket,
                        username,
                        sizeof(username));

    if (bytes <= 0)
    {
        closesocket(client_socket);
        return NULL;
    }

    username[bytes] = '\0';

    printf("Username: %s\n", username);

   send_message(client_socket,
             "Username Received");

    // Receive Password
   bytes = receive_message(client_socket,
                        password,
                        sizeof(password));

    if (bytes <= 0)
    {
        closesocket(client_socket);
        return NULL;
    }

    password[bytes] = '\0';

    printf("Password: %s\n", password);

   if (authenticate(username, password))
{
    send_message(client_socket,
                 "Authentication Successful");

    printf("Authentication Successful\n");
}
else
{
    send_message(client_socket,
                 "Authentication Failed");

    printf("Authentication Failed\n");
}

    closesocket(client_socket);

    return NULL;
}

int main()
{
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);

    char username[100];
    char password[50];
    int bytes;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup failed!\n");
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == INVALID_SOCKET)
    {
        printf("Socket creation failed!\n");
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) == SOCKET_ERROR)
    {
        printf("Bind failed!\n");

        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    if (listen(server_socket, 5) == SOCKET_ERROR)
    {
        printf("Listen failed!\n");

        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("=====================================\n");
    printf("Server started on port %d\n", PORT);
    printf("Waiting for client connection...\n");
    printf("=====================================\n");

    while (1)
{
    client_socket = accept(server_socket,
                           (struct sockaddr *)&client_addr,
                           &client_len);

    if (client_socket == INVALID_SOCKET)
    {
        continue;
    }

    printf("Client Connected.\n");

    SOCKET *new_socket = malloc(sizeof(SOCKET));
    *new_socket = client_socket;

    pthread_t thread;

    if (pthread_create(&thread, NULL, handle_client, new_socket) == 0)
    {
    pthread_detach(thread);
    }
    else
    {
    printf("Thread creation failed!\n");
    closesocket(client_socket);
    free(new_socket);
    }
}

    closesocket(server_socket);

    WSACleanup();

    return 0;
}