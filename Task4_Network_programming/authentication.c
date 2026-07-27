#include <string.h>
#include "authentication.h"

int authenticate(const char *username, const char *password)
{
    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "1234") == 0)
    {
        return 1;
    }

    return 0;
}