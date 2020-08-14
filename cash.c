#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int change;  // initializing 'change' to be used later
    
    /* do while loop that promts the user to provide a cash amount in float 
         which is then converted into all change */ 
    do  
    {
        float cash_owed = get_float("Change Owed: $ ");
        change = round(cash_owed * 100);
    }
    while (change <= 0); /* do while conditions only proceding if the value is 
                            is a non-negitive float */

    int coins = 0; // initializing 'coins'

    int coin_amount[] = {25, 10, 5, 1}; // creating a set of value for each coin
    int size = 4; // size of the set
    
    /* this for loop thru each value of 'coin_amount' and add the quotient
    of change & coin_amount to 'coins' (initially 0). then it will take the
    modulo division of change and coin_amount */
    for (int i = 0; i < size; i++) 
    {
        coins += change / coin_amount[i];
        change %= coin_amount[i];
    }
    
    // print the minimum amount of coins
    printf("%i\n", coins);
}
