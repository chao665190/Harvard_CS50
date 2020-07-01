# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    int count = 0;
    int sum = 0;
    int sum_1 = 0;
    int sum_2 = 0;
    long long result = 0;
    int digit_even = 0;
    long long n = 0; // n is cardnumber

    do
    {
        n = get_long("Please write your credit card number: "); // ask for credit number input
    }
    while (n < 0);

    long long digits = n;
    long long result_1 = pow(10, 16);
    int digit_16 = (n % result_1) / (result_1 / 10);

    while (digits > 0)
    {
        digits = digits / 10;
        printf("digits is %lli.\n", digits);
        count++;
        //printf("count is %i.\n", count);
        result = pow(10, count);
        if (count % 2 == 1)
        {
            sum_1 = sum_1 + (n % result) / (result / 10) ;
            //printf("sum_1 %i. \n", sum_1);
        }
        else
        {
            digit_even = (n % result) / (result / 10) * 2;

            if ((digit_even % 10 > 0) || (digit_even % 10 == 0))
            {
                digit_even = digit_even % 10 + digit_even / 10;
                //printf("digit_even %i. \n", digit_even);
                sum_2 = sum_2 + digit_even;
            }
        }

        sum = sum_1 + sum_2;
        //printf("sum %i.\n", sum);
    }

// sum ends in 0
    if (sum % 10 == 0)
    {
//Validation for AMEX
        long long amex = (n / 10000000000000);
        if (count == 15)
        {
            if (amex != 34 && amex != 37)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("AMEX\n");
            }
            return 0;
        }
//First validation for VISA
        long long visa = (n / 1000000000000);
        if (count == 13)
        {
            if (visa != 4)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("VISA\n");
            }
            return 0;
        }
//Validation for CC numbers of 16 digits
        if (count == 16)
        {
//Second validation for VISA
            if (digit_16 == 4)
            {
                printf("VISA\n");
            }
            else
            {
//Validation for MASTERCARD
                long long mastercard = (n / 100000000000000);
                if (mastercard != 51 && mastercard != 52 && mastercard != 53 && mastercard != 54
                    && mastercard != 55)
                {
                    printf("INVALID\n");
                }
                else
                {
                    printf("MASTERCARD\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
