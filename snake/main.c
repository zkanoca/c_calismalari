#include <stdio.h>
#include <stdlib.h>

typedef struct _pos_t
{
    int x;
    int y;
    struct _pos_t *next;
} pos_t;

// The TTL structure for bonus and killer pop-ups
typedef struct _ttl_t
{
    int x;
    int y;
    int startTTL;
    int ttl;
    struct _ttl_t *next;
} ttl_t;

void get_command(char *cmd)
{
    printf("Command? ");
    scanf(" %c", cmd);
}

void insertPos(pos_t **list, int x, int y)
{
    pos_t *new_pos = (pos_t *)malloc(sizeof(pos_t));

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
    pos_t removed_pos;
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

// Task 5: look up a position in the list
pos_t *lookupPos(pos_t *list, int x, int y)
{

    while (list != NULL)
    {
        if (list->x == x && list->y == y)
        {
            // Found the position
            return list;
        }
        list = list->next;
    }

    // Position not found
    return NULL;
}

// Task 6: insert a TTL into the list
void printTTL(ttl_t *list)
{
    printf("[");
    while (list != NULL)
    {
        printf("(%d,%d,%d,%d)", list->x, list->y, list->startTTL, list->ttl);
        list = list->next;
        if (list != NULL)
        {
            printf(",");
        }
    }
    printf("]\n");
}

// Task7: get bonus/killer input values
void getBonusInput(int *x, int *y, int *ttl)
{
    printf("Position (x y ttl)? ");
    scanf("%d %d %d", x, y, ttl);
}

// Task 8: Lookup TTL in the list
ttl_t *lookupTTL(ttl_t *list, int x, int y)
{
    while (list != NULL)
    {
        if (list->x == x && list->y == y)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

// Task 7: insert a TTL into the list.
ttl_t *insertTTL(ttl_t *list, int x, int y, int startTTL)
{
    ttl_t *alreadyExists = lookupTTL(list, x, y);

    if (alreadyExists != NULL)
    {
        printf("Position (%d,%d) is already in the list\n", x, y);
        return list;
    }

    ttl_t *new_ttl = (ttl_t *)malloc(sizeof(ttl_t));

    new_ttl->x = x;
    new_ttl->y = y;
    new_ttl->startTTL = startTTL;
    new_ttl->ttl = startTTL;
    new_ttl->next = NULL;

    // If the list is empty or new_ttl has smallest TTL, insert at the start
    if (list == NULL || list->ttl >= startTTL)
    {
        new_ttl->next = list;
        return new_ttl;
    }

    ttl_t *current = list;
    while (current->next != NULL && current->next->ttl < startTTL)
    {
        current = current->next;
    }

    new_ttl->next = current->next;
    current->next = new_ttl;

    return list;
}

int updateTTL(ttl_t *list)
{
    while (list != NULL)
    {
        if (list->ttl > 0)
        {
            list->ttl--;
        }
        list = list->next;
    }
    return 0;
}

// Task 10. Removing bonus/killer pop-ups that have expired
int removeTTL(ttl_t **list)
{
    int removed = 0;
    while (*list != NULL && (*list)->ttl == 0)
    {
        ttl_t *tmp = *list;
        *list = (*list)->next;
        free(tmp);
        removed++;
    }

    // return removed count when reached end of the list
    if (*list == NULL)
    {
        return removed;
    }

    ttl_t *current = *list;
    while (current->next != NULL)
    {
        //if the next element has expired, remove it
        if (current->next->ttl == 0)
        {
            ttl_t *tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            // add 1 to removed count 
            removed++;
        }
        // else switch to next element
        else
        {
            current = current->next;
        }
    }

    // Return removed elements count
    return removed;
}

void removeMiddleTTL(ttl_t **list, int x, int y)
{
    //create an instance of *list
    ttl_t *current = *list;
    //*prev for keeping track of the previous element
    ttl_t *prev = NULL;
    //found flag, 0 in the beginning
    int found = 0;

    // if the list is not empty, traverse the list to find the position
    while (current != NULL)
    {
        // if the position is found, set found flag to 1 and break the loop
        if (current->x == x && current->y == y)
        {
            found = 1;
            break;
        }
        // update prev and current pointers
        prev = current;
        current = current->next;
    }

    // if position does not exist in the list print error message
    // then exit the function
    if (!found)
    {
        printf("Position (%d,%d) is not in the list\n", x, y);
        return;
    }

    // if prev is still NULL, this means that the position is the first element's position.
    if (prev == NULL)
    {
        // update addresses
        *list = current->next;
    }
    else
    {
        // update addresses
        prev->next = current->next;
    }

    // free the memory allocated for the "current"
    free(current);
}

int main()
{

    char cmd;
    // sanake
    pos_t *snake = NULL;
    // x, y  positions and time to live value
    int x, y, ttl;
    // bonus list
    ttl_t *bonus = NULL;
    // TTL update counts
    int updatedTTL;

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
        // Lookup position (x,y) in the list
        case 'l':
        {
            getNewPosition(&x, &y);
            pos_t *found = lookupPos(snake, x, y);
            printf("Position (%d,%d) is ", x, y);
            if (found == NULL)
            {
                printf("not ");
            }
            printf("in the list\n");
            break;
        }
        // Print the bonus list
        case 'b':
        {
            printTTL(bonus);
            break;
        }
        // Task 7: new bonus (killer) pop-up
        case 'i':
        {
            getBonusInput(&x, &y, &ttl);
            bonus = insertTTL(bonus, x, y, ttl);
            break;
        }
        // Task9: DEcrement TTL values of  all bonus/killer pop-ups by one
        case 'u':
        {
            updatedTTL = updateTTL(bonus);
            break;
        }
        // Task10: Remove expired bonus/killer pop-ups (TTL value is equal to 0)
        case 'r':
        {
            int count = removeTTL(&bonus);
            printf("Removed %d nodes\n", count);
            break;
        }
        // Task11. Remove from middle
        case 'm':
        {
            getNewPosition(&x, &y);
            removeMiddleTTL(&bonus, x, y);
            break;
        }
        // deault unkown command
        default:
            printf("Unknown command '%c'\n", cmd);
        }
    } while (cmd != 'q');

    return 0;
}
