#include <cs50.h>
#include <stdio.h>

void piramid(int n)
{
    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < n; j++)
    	{
                if (j < (n - (i + 1)))
                {
                    printf(" ");
                } else {
         		    printf("#");
                }
    	}
    	printf("\n");
    }
};

int main(void)
{
    int height;
    do
    {
        height = get_int("Select your mario piramid height (1 - 8):");
    }
    while ( height < 0 || height > 9 );

    if ( height > 0 && height < 9 )
    {
        piramid(height);
    }

};