/*
Restart with an empty program.  As the final program we now implement a counter that
increments by pushing button 0.  Decrement the value of the counter by pushing button 1.
Print x+1 = y when button 0 is pushed and x-1 = y when button 1 is pushed. x is the
current value of the counter and y is the new value of the counter. LED 0 is switched
on when the value of the counter is 0, LED 1 is switched on when the value of the
counter is 1, LED 2 is switched on when the value of the counter is 2, and LED 3 is
switched on when the value of the counter is 3.
*/

#include <stdio.h>

int main(void)
{
    pynq_init();
    leds_init_onoff();
    buttons_init();
    // declare your variables
    int counter, init_num, button, i;

    // turn off all LEDs
    for (i = 0; i < 4; i++)
    {
        green_led_onoff(1, LED_OFF);
    }

    // ask for initial value of counter
    while (1)
    {
        printf("Enter a  number: ");
        scanf("%d", &init_num);

        if (init_num < 0)
        {
            printf("the number must be positive");
        }
        else
        {
            // determine coutner number between [0 3]
            counter = init_num % 4;
            // turn on the corresponding LED
            green_led_onoff(counter, LED_ON);
            // exit while loop
            break;
        }
    }

    // init buttons
    buttons_init();

    while (1)
    {
        button = wait_until_any_button_released();
        if (button == 0) // increment
        {
            // turn off the current LED
            green_led_onoff(counter, LED_OFF);

            // update counter
            // printf("\n%d+1 = ", counter);
            counter = (counter + 1) % 4;
            // printf("%d", counter);
        }
        else if (button == 1) // decrement
        {
            // turn off the current LED
            green_led_onoff(counter, LED_OFF);

            // update the counter
            //  printf("\n%d-1 = ", counter);
            counter = (counter + 3) % 4;
            // printf("%d", counter);
        }
        // switch on the right LED
        green_led_onoff(counter, LED_ON);
    }

    buttons_destroy();
    leds_destroy();
    pynq_destroy();
}

/*
enter a number? -1
the number must be positive
enter a number? 10
2+1 = 3
3+1 = 0
0+1 = 1
1-1 = 0
0-1 = 3
^C
*/