#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
//karmaşık sayı kütüphanesi kullanacaksan burayı yorum satırı yapma.
 #include <complex.h>
*/
int main()
{
    system("cls");
    char cmd, temp_dot;
    float curr_re = 0.0, curr_im = 0.0;
    float new_re = 0.0, new_im = 0.0;
    float temp_re = 0.0, temp_im = 0.0;
    float temp_temp_re = 0.0, temp_temp_im = 0.0;

    int i, j, no, x, y;
    char plane[21][21] = {
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"----------+----------"},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."},
        {"..........|.........."}};

    /* //complex.h kullanarak yapacaksan bu satırları kullan.
      float complex z1 = 0.0 + 0.0 * I;
      float complex raised = 1.0;
    */

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
                printf("Natural operand? ");
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
                    /*
                        //istersen complex.h kütüphanesiyle
                        //daha sancısız yapabilirsin.

                    z1 = curr_re + curr_im*I;
                    raised = cpow(z1, no);
                    curr_re = creal(raised);
                    curr_im = cimag(raised);
                    */
                    /*
                    YA DA
                    bildigimiz yoldan
                    */
                    temp_re = curr_re;
                    temp_im = curr_im;

                    for (i = 1; i < no; i++)
                    {
                        temp_temp_re = temp_re;
                        temp_temp_im = temp_im;
                        temp_re = temp_re * curr_re - temp_im * curr_im;
                        temp_im = temp_temp_re * curr_im + curr_re * temp_im;
                    }
                    curr_re = temp_re;
                    curr_im = temp_im;
                }
            }
            else if (cmd == 'p')
            {
                // plot
                if (curr_re < 0)
                {
                    x = 10 - round(abs(curr_re));
                }
                else
                {
                    x = (int)curr_re + 10;
                }
                if (curr_im < 0)
                {
                    y = 10 + round(abs(curr_im));
                }
                else
                {
                    y = 10 - (int)curr_im;
                }
                temp_dot = plane[y][x];
                plane[y][x] = '*';
                for (i = 0; i < 21; i++)
                {
                    for (j = 0; j < 21; j++)
                    {
                        printf("%c", plane[i][j]);
                    }
                    printf("\n");
                }
                plane[y][x] = temp_dot;
            }
            else
            {
                printf("Complex operand? ");
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
            printf("Current value is %f%fi\n", curr_re, curr_im);
        }
        else
        {
            printf("Current value is %f+%fi\n", curr_re, curr_im);
        }
    } while (cmd != 'q');

    printf("Bye!\n");
    return 0;
}
