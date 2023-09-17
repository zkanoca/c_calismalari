#include <stdio.h>
#include <math.h>

int main()
{
    system("cls");
    char cmd;
    float curr_re = 0.0, curr_im = 0.0, new_re, new_im, temp_re, temp_im;
    int i, no;
    // Task 1
    printf("** Complex Calculator **\n");

    do
    {
        printf("Operation [0+-*crpq]? ");
        scanf(" %c", &cmd);

        if (cmd == '+' || cmd == '-' || cmd == '*' || cmd == 'r' || cmd == 'p')
        {
            if (cmd == 'r')
            {
                printf("Natural operand: ");
                scanf("%d", &no);

                if (no == 0)
                {
                    if (curr_re == 0)
                        printf("Undefined\n");
                    else
                    {
                        curr_im = 0;
                        curr_re = 1;
                    }
                }
                else
                {
                    for (i = 1; i <= no; i++)
                    {
                        // (a+bi)(a+bi) = a*a + a*bi + a*bi - b*b
                        temp_re = 1;
                        temp_im = 1;
                        temp_re *= curr_re * curr_re - curr_im * curr_im;
                        temp_im *= curr_re * curr_im + curr_re * curr_im;
                    }
                    curr_re = temp_re;
                    curr_im = temp_im;
                }
            }
            else
            {
                printf("Complex operand: ");
                scanf("%f %f", &new_re, &new_im);
            }
        }
        else if (cmd == '0')
        {
            curr_re = 0;
            curr_im = 0;
        }
        else if (cmd == 'c')
        {
            curr_im *= -1;
        }
        else if (cmd != 'q')
        {
            printf("Invalid command '%c'\n", cmd);
        }

        if (cmd == '+')
        {
            curr_re += new_re;
            curr_im += new_im;
        }
        else if (cmd == '-')
        {
            curr_re -= new_re;
            curr_im -= new_im;
        }
        else if (cmd == '*')
        {
            //(a + bi) * (c + di) = a*c + a*di + bi*c -bd
            // multiply
            temp_re = curr_re * new_re - curr_im * new_im;
            temp_im = curr_re * new_im + curr_im * new_re;

            curr_re = temp_re;
            curr_im = temp_im;
        }

        if (curr_im < 0)
        {
            printf("Current value is %f-%fi\n", curr_re, curr_im);
        }
        else
        {
            printf("Current value is %f+%fi\n", curr_re, curr_im);
        }
    } while (cmd != 'q');

    printf("Bye!");
    return 0;
}
