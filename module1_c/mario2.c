#include <cs50.h>
#include <stdio.h>

void piramid(int n)
{
    int length = (n * 2) + 1;

    for(int i = 0; i < n; i++)
    {
	    for(int j = 0; j < length; j++)
    	{
                if (j == length/2)
                {
                    printf(" ");
                }
                else if (j < ( (length/2) - (i + 1)) || j > (length/2) + (i + 1) )
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
        height = get_int("Select your mario piramid height (1 - 50):");
    }
    while ( height < 0 || height > 51 );

    if ( height > 0 && height < 51 )
    {
        piramid(height);
    }

};