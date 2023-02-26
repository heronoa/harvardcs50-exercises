#include <cs50.h>
#include <math.h>
#include <stdio.h>

int length(long long n)
{
    if (n == 0) {
        return 1;
    }

    long number = n;
    int length = 0;
    do
    {
        number = number / 10;
        length++;
    }
    while (number > 0);

    return length;
}

bool checkValid(long long cn)
{

    int even, odd, res = 0;
    int l = length(cn);
    for(int i = 0; i < l; i++)
    {
        long long cn_slice = (cn / pow(10, i));
        // printf("slice: %lli\n", cn_slice);
        int n_pos = cn_slice % 10;
        if (i % 2 == 0)
        {
            even = n_pos;
            res += even;
        }
        else
        {
            odd = (2*n_pos);
            if (odd > 9) {
                res += odd % 10;
                res += (odd/10) % 10;
            }
            else
            {
                res += odd;
            }
        }
    }
    if (res % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char* checkCompany(long long cn, int l)
{
    if (l == 15 && (cn == 34 || cn == 37))
    {
        return "AMEX";
    } else if (l == 13 && cn >= 40 && cn < 50)
    {
        return "VISA";
    }
    else if (l == 14)
    {
        return "INVALID";
    }
    else if (l == 16) {
        if (cn >= 40 && cn < 50) {
            return "VISA";
        }
        else if (cn > 50 && cn < 56) {
            return "MASTERCARD";
        }
        else
        {
            return "INVALID";
        }
    }
    else {
        return "INVALID";
    }


}

void credit(long long credit_number)
{
    int l = length(credit_number);
    int initials = credit_number / pow(10,l - 2);
    char* company = checkCompany(initials, l);
    bool verifier = checkValid(credit_number);
    if(verifier)
    {
        printf("%s\n", company);
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{

    long long credit_number;
    int l;
    credit_number = get_long("credit card number (at least 13 numbers):");
    l = length(credit_number);

    if (l < 13 || l > 16)
    {
        printf("INVALID\n");
    } else {

    credit(credit_number);
    }
};