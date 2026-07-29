#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <winsock2.h>

int send_message(SOCKET socket, const char *message);

int receive_message(SOCKET socket,
                    char *buffer,
                    int buffer_size);

int validate_message(const char *message);

#endif