#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

/* This program takes an argument and piece of text
from the user, and uses Caeser's cypher to encript
the text according to the argument. */

// Cipher formula:  C = (P + k) % 26

int main(int argc, char *argv[])
{

    // Check how many arguements have been entered,
    // and print a prompt if argc != 2

    if (argc != 2)
    {
        printf("%d numbers entered. Enter one number to determine the cipher.\n", argc - 1);
        return 1;
    }

    else if (argc == 2)
    {

        // Convert argv into an int and define as cipher key

        int key = atoi(argv[1]);

        // Loop through all the characters of input

        string s = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (isalpha(s[i]) != 0)
            {

                // Use ascii chart to convert alphabet to 0 through 25,
                // use cipher formula, then convert back.

                if (islower(s[i]))
                {
                    s[i] = s[i] - 97;
                    printf("%c", ((s[i] + key) % 26) + 97);
                }
                else
                {
                    s[i] = s[i] - 65;
                    printf("%c", ((s[i] + key) % 26) + 65);
                }
            }

            // If character is not in the alphabet, print as normal.

            else if (isalpha(s[i]) == 0)
            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
        return 0;
    }
}