#include <stdio.h> //henter bibliotek/filer fra root der C er blitt installert

#include "common.h" // " *" henter filer der du lager filer i en mappe

void printer(char *msg)
{
    printf("%s %s", "this is your message:", msg);
}