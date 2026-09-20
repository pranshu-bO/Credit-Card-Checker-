#include <cs50.h>
#include <stdio.h>
#include <string.h>

int find_sum(long long int digit);
int find_final(long long int digit);
string check_express(long long int number);
string check_master(long long int number);
string check_visa(long long int number);

int main(void)
{
    long long int digit;
    do
    {
        digit = get_long("Number: ");
    }
    while (digit <= 0);
    int result = find_sum(digit);
    int result_ = find_final(digit);
    int final = result + result_;
    string type = "INVALID";
    if (final % 10 == 0)
    {
        type = check_express(digit);
        if (strcmp(type, "INVALID") == 0)
        {
            type = check_master(digit);
            if (strcmp(type, "INVALID") == 0)
            {
                type = check_visa(digit);
                if (strcmp(type, "INVALID") == 0)
                {
                    printf("%s\n", type);
                }
                else
                {
                    printf("%s\n", type);
                }
            }
            else
            {
                printf("%s\n", type);
            }
        }
        else
        {
            printf("%s\n", type);
        }

    }
    else
    {
        printf("INVALID\n");
    }
}


string check_visa(long long int number)
{
    int total = 0;
    int count = 0;
    long long int num = number;
    while (number > 0)
    {
        int last = number % 10;
        if (count % 2 == 1)
        {
            total += last;
        }

        number = number / 10;
        count++;
    }
    string type = "INVALID";
    if (count == 16 || count == 13)
    {
        if (count == 16)
        {
            num = num / 1000000000000000;
            if (num == 4)
            {
                type ="VISA";
            }
            else
            {
                type ="INVALID";
            }
        }
        else if (count == 13)
        {
            num = num / 1000000000000;
            if (num == 4)
            {
                type ="VISA";
            }
            else
            {
                type ="INVALID";
            }
        }
        else
        {
            type ="INVALID";
        }
    }
    else
    {
        type = "INVALID";
    }
    return type;
}


string check_master(long long int number)
{
    int total = 0;
    int count = 0;
    long long int num = number;
    while (number > 0)
    {
        int last = number % 10;
        if (count % 2 == 1)
        {
            total += last;
        }

        number = number / 10;
        count++;
    }
    string type = "INVALID";
    if (count == 16)
    {
        int n = num / 100000000000000;
        if (n == 51 || n == 52 || n == 53 || n == 54 || n == 55)
        {
            type = "MASTERCARD";
        }
        else
        {
            type = "INVALID";
        }
    }
    else
    {
        type = "INVALID";
    }
    return type;
}

string check_express(long long int number)
{
    int total = 0;
    int count = 0;
    long long int num = number;
    while (number > 0)
    {
        int last = number % 10;
        if (count % 2 == 1)
        {
            total += last;
        }

        number = number / 10;
        count++;
    }
    string type = "INVALID";
    if (count == 15)
    {
        int n = num / 10000000000000;
        printf("count=%i n=%i\n", count, n);
        if (n == 34 || n == 37)
        {
            type = "AMEX";
        }
        else
        {
            type = "INVALID";
        }
    }
    else
    {
        type = "INVALID";
    }
    return type;
}

int find_final(long long int number)
{
    int total = 0;
    int count = 1;
    while (number > 0)
    {
        int last = number % 10;
        if (count % 2 == 1)
        {
            total += last;
        }

        number = number / 10;
        count++;
    }
    return total;
}

int find_sum(long long int number)
{
    int total = 0;
    int count = 1;
    while (number > 0)
    {
        int last = number % 10;
        if (count % 2 == 0)
        {
            last *= 2;
            if (last / 10 != 0)
            {
                last = last % 10;
                last++;
            }
            total += last;
        }

        number = number / 10;
        count++;
    }
    return total;
}
