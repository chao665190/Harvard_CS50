# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (n < 1 || n > 8);


    if (n > 0 || n < 9)
    {
        int counter = 0;
        for (int row = 0; row < n; row++)
        {
            if (counter != n)
            {
                for (int spaces = (n - 1) - counter; spaces > 0; --spaces)
                {
                    printf(" "); // spaces part 1
                }
                for (int hashes = 0; hashes <= counter; ++hashes)
                {
                    printf("#"); // hash part 1
                }

                printf("  "); //space in the middle part 2

                for (int hashes = 0; hashes <= counter; ++hashes)
                {
                    printf("#"); // hash part 2
                }

                printf("\n");
                counter++; // comes the new caculation
            }
        }
    }
}