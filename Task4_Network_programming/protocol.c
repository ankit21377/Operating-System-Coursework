#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include "protocol.h"

int send_message(SOCKET socket, const char *message)
{
    if (message == NULL)
        return -1;

    return send(socket, message, strlen(message), 0);
}

int receive_message(SOCKET socket,
                    char *buffer,
                    int buffer_size)
{
    int bytes;

    bytes = recv(socket, buffer, buffer_size - 1, 0);

    if (bytes <= 0)
        return bytes;

    buffer[bytes] = '\0';

    return bytes;
}

int validate_message(const char *message)
{
    if (message == NULL)
        return 0;

    if (strlen(message) == 0)
        return 0;

    if (strlen(message) > 100)
        return 0;

    return 1;
}