#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
 {

    // check for 2 arguments only
    if (argc != 2)
    {
        printf(" ./substitution key\n");
        return 1;
    }

    // once I check for correct argv put key into an int k
    string key = (argv[1]);

    // check if the keylength is 26
    if (strlen(key)!=26)
    {
        printf("Nope only 26 letters\n");
        return 1;
    }
//Check for duplicate characters (case-insensitive)
    int matches = 0;

    for (int i = 0; i<26; i++)
    {
        for (int j = 0; argv[1][j] != '\0'; j++)
        {

            if (argv[1][j] == argv[1][i])
            {
                matches++;
            }
        }
    }
if (matches!= 26)
    {
        printf("do not repeat letters in key\n");
        return 1;
    }
    

        // prompt user for a code to encrypt
        string plaintext= get_string("enter text:");
        
// print ciphertext

printf("ciphertext: ");



 // alternate: can initialize two strings of lowercase and uppercase alphabets
 // string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   //      string a = "abcdefghijklmnopqrstuvwxyz";
//Convert plaintext to ciphertext

    for (int i = 0; i<strlen(plaintext); i++) // loop thru plaintext
    {
        for (int j = 0; j < 26; j++) // loop through 26 letters of  key
        {
            if (islower(plaintext[i])) // if PT is lower then we check the position of letter in key in coherance to our alphabets and store the value in j which we use to print as key[j] but making sure the key is in lowercase as the PT is in lowercase
            {
                if (plaintext[i] == 'a' + j) // alternate: a[0]+j
                {
                    printf("%c", tolower(key[j]));
                }

            }
            else if (isupper(plaintext[i])) // similar explanation as above except here we take PT if it is in uppercase and make sure key is in uppercase for the jth position of letter
            {
                if (plaintext[i] == 'A' + j) // alternate: A[0]+j
                {
                    printf("%c", toupper(key[j]));
                }
            }
        }
        if (!isalpha(plaintext[i])) // if not an alphabet do not change
        {
            printf("%c", plaintext[i]);
        }
    }
//print newline - end of the program
    printf("\n");
}
