#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
// promt user to enter credit card number

    long card_number = get_long("Number: ");
// initialize the first digit of the number, second digit of the number, and the two sums required for Luhn’s Algorithm
    int digit = 0, digit2 = 0, digit_counter = 0, even_sum = 0, sum_2x_odd = 0;
    
//while loop as long as the card number is greater than 0. 
    while (card_number > 0)
    {
        digit2 = digit;
        digit = card_number % 10;
  // if conditions where if the remainder of the digit counter / 2 is 0 then add the even_sum to first digit other wise mutply
  //the odd digits by 2 and add the, together by single digits.        
        if (digit_counter % 2 == 0)
        {
            even_sum += digit;
        }
        else
        {
            int times_two = 2 * digit;
            sum_2x_odd += (times_two / 10) + (times_two % 10);
        }
        
        card_number = card_number / 10;
        digit_counter++;
    }
// this bool determins if Luhn’s Algorithm is true, if the sums ends in a 0 
    bool is_valid = (even_sum + sum_2x_odd) % 10 == 0;
// this int is the first two number of the credit card number. 
    int inital_digits = digit * 10 + digit2;
    
    if ((inital_digits == 34 || inital_digits == 37) && digit_counter == 15 && is_valid)
    {
        printf("AMEX\n");
    }
    else if ((inital_digits >= 51 && inital_digits <= 55) && digit_counter == 16 && is_valid)
    {
        printf("MASTERCARD\n");
    }
    else if (digit == 4 && (digit_counter == 13 || digit_counter == 16 ) && is_valid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
