#include <stdio.h>
#include <math.h>

#define MAXPERSONS 240
#define MAXNAME 100
#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 240

struct person_t
{
    char name[MAXNAME];
    float height;
};

int initialise(struct person_t persons[], int nrPersons)
{
    int i;
    printf("Number of persons? ");
    scanf("%i", &nrPersons);
    if (nrPersons >= 1 && nrPersons <= MAXPERSONS)
    {
        for (i = 0; i < nrPersons; i++)
        {
            sprintf(persons[i].name, "person-%d", i);
            persons[i].height = nrPersons - i - 1;
        }
    }
    else
    {
        printf("Number of persons must be from 1 up to %d\n", MAXPERSONS);
    }
    return nrPersons;
}

void printValues(struct person_t persons[], int from, int to)
{
    int i;
    printf("[");
    for (i = from; i <= to; i++)
    {
        printf("(\"%s\",%.2f)", persons[i].name, persons[i].height);
        if (i != to)
        {
            printf(",");
        }
    }
    printf("]\n");
}

float maxValue(struct person_t persons[], int nrPersons)
{
    int i;
    float max = persons[0].height;
    for (i = 1; i < nrPersons; i++)
    {
        if (persons[i].height > max)
        {
            max = persons[i].height;
        }
    }
    return max;
}

float minValue(struct person_t persons[], int nrPersons)
{
    int i;
    float min = persons[0].height;
    for (i = 1; i < nrPersons; i++)
    {
        if (persons[i].height < min)
        {
            min = persons[i].height;
        }
    }
    return min;
}

void replacePerson(struct person_t persons[], int nrPersons)
{
    int index;
    printf("Index? ");
    scanf("%i", &index);
    if (index < 0 || index >= nrPersons)
    {
        printf("Index must be from 0 up to %d\n", nrPersons);
        return;
    }
    printf("Name? ");
    scanf("%s", persons[index].name);
    printf("Height? ");
    scanf("%f", &persons[index].height);
}

void displayValues(/*display_t display,*/ struct person_t persons[], int nrPersons, int from, int to)
{
    float max = maxValue(persons, nrPersons);
    float min = minValue(persons, nrPersons);
    float range = max - min;
    float barWidth = (float)DISPLAY_WIDTH / nrPersons;
    //   displayFillScreen(&display, RGB_BLUE);

    int i;
    for (i = 0; i < nrPersons; i++)
    {
        // int barHeight = (int)((persons[i].height - min)/(range*(DISPLAY_HEIGHT-1)));
        int barHeight = round(((persons[i].height - min) / range) * (DISPLAY_HEIGHT - 1));

        int x1 = i * barWidth;
        int x2 = x1 + barWidth - 1;
        int y1 = DISPLAY_HEIGHT - barHeight - 1;
        int y2 = DISPLAY_HEIGHT - 1;

        printf("Height: %f", persons[i].height);
        printf("Min: %f", min);
        printf("Range: %f", range);
        printf("y1: %i y2: %i\n", y1, y2);
        printf("x1: %i x2: %i\n", x1, x2);
        printf("barheight: %i\n", barHeight);
        // if (i >= from && i <= to){
        //   displayDrawFillRect(&display, x1, y1, x2, y2, RGB_RED);
        // }
        // else {
        //   displayDrawFillRect(&display, x1, y1, x2, y2, RGB_GREEN);
        // }
    }
}

void bubbleSort(/*display_t display,*/ struct person_t persons[], int nrPersons)
{
    int swap;
    int i;
    do
    {
        swap = 0;
        for (i = 1; i < nrPersons; i++)
        {
            int flag = 0;
            if (persons[i - 1].height > persons[i].height)
            {
                flag = 1;
            }
            else if (persons[i - 1].height == persons[i].height)
            {
                if (strcmp(persons[i - 1].name, persons[i].name) > 0)
                {
                    flag = 1;
                }
            }
            if (flag)
            {
                struct person_t tempPerson = persons[i - 1];
                persons[i - 1] = persons[i];
                persons[i] = tempPerson;

                printf("after swapping: ");
                printValues(persons, 0, nrPersons - 1);
                // displayValues(display, persons, nrPersons, i-1, i);
                swap = 1;
            }
        }
    } while (swap);
    // displayValues(display, persons, nrPersons, 0, 0);
}

void mrg(struct person_t persons[], int left, int mid, int right)
{
    int i, j;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct person_t leftperson[n1], rightperson[n2];

    for (i = 0; i < n1; i++)
    {
        leftperson[i] = persons[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightperson[j] = persons[mid + 1 + j];
    }
    i = 0;
    j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (leftperson[i].height <= rightperson[j].height)
        {
            persons[k] = leftperson[i];
            i++;
        }
        else
        {
            persons[k] = rightperson[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        persons[k] = leftperson[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        persons[k] = rightperson[j];
        j++;
        k++;
    }
    int swap;
    int i;
    do
    {
        swap = 0;
        for (i = 1; i < right-left; i++)
        {
            int flag = 0;
            if (persons[i - 1].height > persons[i].height)
            {
                flag = 1;
            }
            else if (persons[i - 1].height == persons[i].height)
            {
                if (strcmp(persons[i - 1].name, persons[i].name) > 0)
                {
                    flag = 1;
                }
            }
            if (flag)
            {
                struct person_t tempPerson = persons[i - 1];
                persons[i - 1] = persons[i];
                persons[i] = tempPerson;
                swap = 1;
            }
        }
    } while (swap);
}

void mrgeSort(struct person_t persons[], int nrPersons, int left, int right /*, display_t display*/)
{
    if (left >= right)
    {
        return;
    }
    printf("need to sort      ");
    printValues(persons, left, right);
    int mid = left + (right - left) / 2;

    mrgeSort(persons, nrPersons, left, mid /*, display*/);
    printf("after sorting lhs ");
    printValues(persons, left, mid);

    mrgeSort(persons, nrPersons, mid + 1, right /*, display*/);
    printf("after sorting rhs ");
    printValues(persons, mid + 1, right);

    mrg(persons, left, mid, right);
    printf("after merging     ");
    printValues(persons, left, right);
    // displayValues(display, persons, right-left+1, left, right);
}

int main(void)
{
    // pynq_init();
    // display_t display;
    // display_init(&display);
    // displayFillScreen(&display, RGB_BLACK);
    char cmd;
    float max, min;
    int nrPersons = 0;
    struct person_t persons[MAXPERSONS];
    do
    {

        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case 'q':
            printf("Bye!\n");
            break;
        case 'i':
            nrPersons = initialise(persons, nrPersons);
            break;
        case 'p':
            printValues(persons, 0, nrPersons - 1);
            break;
        case 'h':
            max = maxValue(persons, nrPersons);
            min = minValue(persons, nrPersons);
            printf("Min: %.3f\nMax: %.3f\nRange: %.3f\n", min, max, max - min);
            break;
        case 'r':
            replacePerson(persons, nrPersons);
            break;
        case 'd':
            displayValues(/*display,*/ persons, nrPersons, 1, 2);
            break;
        case 'b':
            bubbleSort(/*display,*/ persons, nrPersons);
            break;
        case 'm':
            mrgeSort(persons, nrPersons, 0, nrPersons - 1 /*, display*/);
            break;
        default:
            printf("Unknown command \'%c\'\n", cmd);
        }
    } while (cmd != 'q');
    return 0;
}
