#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _pos_t
{
    int x;
    int y;
    struct _pos_t *next;
} pos_t;

void get_command(char *cmd)
{
    printf("Command? ");
    scanf(" %c", cmd);
}

void insertPos(pos_t **list, int x, int y)
{
    pos_t *new_pos = (pos_t *)malloc(sizeof(pos_t));
    if (new_pos == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_pos->x = x;
    new_pos->y = y;
    new_pos->next = NULL;

    // If the list is empty, make this the first node
    if (*list == NULL)
    {
        *list = new_pos;
        return;
    }

    // Find the end and insert new position
    pos_t *current = *list;
    while (current->next != NULL)
    {
        // Check if the position already exists in the list
        if (current->x == x && current->y == y)
        {
            printf("Position (%d,%d) already exists in the list.\n", x, y);
            free(new_pos);
            return;
        }
        current = current->next;
    }
    current->next = new_pos;
}

void printPos(pos_t *list)
{
    printf("[");
    while (list != NULL)
    {
        printf("(%d,%d)", list->x, list->y);
        list = list->next;
        if (list != NULL)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void quitProgram(pos_t *snake)
{
    printf("Bye!");
    // free all malloc'd memory at exit
    pos_t *current = snake;
    pos_t *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

void getNewPosition(int *x, int *y)
{
    printf("Position (x y)? ");
    scanf("%d %d", x, y);
}

pos_t removeFirstPos(pos_t **list)
{
    pos_t removed_pos = {
        NULL,
    }; // fill with NULL initially
    if (*list == NULL)
    {
        printf("List is empty\n");
        return removed_pos;
    }

    pos_t *temp = *list;
    removed_pos.x = temp->x;
    removed_pos.y = temp->y;
    removed_pos.next = NULL;

    *list = (*list)->next;
    free(temp);

    return removed_pos;
}

int main()
{
    char cmd;
    pos_t *snake = NULL;

    do
    {
        get_command(&cmd);
        switch (cmd)
        {
            // quit program
        case 'q':
            quitProgram(snake);
            break;

        case 's': // Print the positions list
            printPos(snake);
            break;
        // Add new position to the end of the positions list
        case 'e':
        {
            int x, y;
            getNewPosition(&x, &y);

            insertPos(&snake, x, y);

            break;
        }
        // Remove the first element from the positions list
        case 'f':
        {
            pos_t removed_position = removeFirstPos(&snake);
            if (snake != NULL)
            {
                printf("Removed (%d,%d)\n", removed_position.x, removed_position.y);
            }
            break;
        }
        // deault unkown command
        default:
            printf("Unknown command '%c'\n", cmd);
        }

    } while (cmd != 'q');

    return 0;
}
