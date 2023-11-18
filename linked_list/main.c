#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "predefined.h"

// a helper function to print formatted complex number
void print_complex_number(node_t *complex_number)
{
    printf("%.2f", complex_number->re);

    // print imaginary part
    if (complex_number->im < 0)
    {
        // minus sign comes with the number, no need to insert minus symbol
        printf("%.2fi", complex_number->im);
    }
    else if (complex_number->im > 0)
    {
        // add plus sign before the number
        printf("+%.2fi", complex_number->im);
    }
    else // if imaginary part is zero
    {
        // avoid negative zero
        printf("+0.00i");
    }
}

void get_complex_number(float *re, float *im)
{
    printf("re, im? ");
    scanf("%f %f", re, im);
}

// q quit
// q command
void quit_program(node_t *head)
{
    while (head != NULL)
    {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }
    printf("Bye!\n");
    exit(0);
}

// h insert at head
// Function to insert a new node at the head of the list
node_t *insertHead(node_t *head, float re, float im)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->re = re;
    newNode->im = im;
    newNode->next = head;
    return newNode;
}

// f remove first
// remve the first node from the linked list
node_t *removeFirst(node_t *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    node_t *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// p print list
void printList(node_t *head)
{
    // open the list with bracket
    printf("[");

    // repeat until the end of the list
    while (head != NULL)
    {
        print_complex_number(head);

        // before getting the next complex number, add a comma between two complex  numbers
        if (head->next != NULL)
        {
            printf(",");
        }

        // skip to next node
        head = head->next;
    }

    // close the list with bracket
    printf("]\n");
}

// t insert at tail
node_t *insertTail(node_t *head, float re, float im)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->re = re;
    newNode->im = im;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// l remove last
node_t *removeLast(node_t *head)
{
    if (head == NULL || head->next == NULL)
    {
        // If the list is empty or has only one element free head and return NULL
        free(head);
        return NULL;
    }

    node_t *prev = NULL;
    node_t *currentNode = head;

    while (currentNode->next != NULL)
    {
        prev = currentNode;
        currentNode = currentNode->next;
    }

    free(currentNode);
    if (prev != NULL)
    {
        prev->next = NULL;
        return head;
    }
    else
    {
        return NULL;
    }
}

// c find closest
node_t *findClosest(node_t *head, float re, float im)
{

    if (head == NULL)
    {
        return NULL;
    }

    float current_distance, min_distance;
    node_t *closest_element = head;

    min_distance = sqrt(pow(head->re - re, 2) + pow(head->im - im, 2));

    while (head != NULL)
    {
        current_distance = sqrt(pow(head->re - re, 2) + pow(head->im - im, 2));

        if (current_distance < min_distance)
        {
            min_distance = current_distance;
            closest_element = head;
        }
        head = head->next;
    }

    return closest_element;
}

// a insert after closest
node_t *insertAfterClosest(node_t *head, float re, float im)
{
    node_t *closest = findClosest(head, re, im);

    // if there is no closest number just add the number into the head of the list
    if (closest == NULL)
    {
        return insertHead(head, re, im);
    }

    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->re = re;
    newNode->im = im;
    newNode->next = closest->next;
    closest->next = newNode;

    return head;
}

// b insert before closest
node_t *insertBeforeClosest(node_t *head, float re, float im)
{
    node_t *closest = findClosest(head, re, im);
    if (closest == NULL)
    {
        return insertHead(head, re, im);
    }

    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->re = re;
    newNode->im = im;

    if (head == closest)
    {
        newNode->next = head;
        return newNode;
    }

    node_t *temp = head;
    while (temp->next != closest)
    {
        temp = temp->next;
    }

    newNode->next = closest;
    temp->next = newNode;

    return head;
}

// v print reverse list
void printListReverse(node_t *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next != NULL)
    {
        printListReverse(head->next);
        printf(",");
    }

    print_complex_number(head);
}

// r remove closest
node_t *removeClosest(node_t *head, float re, float im)
{
    node_t *closest = findClosest(head, re, im);
    if (closest == NULL)
    {
        return head;
    }

    if (head == closest)
    {
        head = head->next;
        free(closest);
        return head;
    }

    node_t *prev = head;
    while (prev->next != closest)
    {
        prev = prev->next;
    }
    prev->next = closest->next;
    free(closest);
    return head;
}

int main()
{
    node_t *list = NULL;
    char cmd;
    float re, im;
    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {

        case 'q': // quit program
            // empty all non-null list items
            while (list != NULL)
            {
                list = removeFirst(list);
            }
            quit_program(list);
            break;

        case 'p': // print list
            printList(list);
            break;

        case 'h': // insert complex  number to the head

            get_complex_number(&re, &im);
            list = insertHead(list, re, im);
            break;

        case 't': // insert complex  number to the tail
            get_complex_number(&re, &im);
            list = insertTail(list, re, im);
            break;

        case 'f': // remove first item from the list
            list = removeFirst(list);
            break;

        case 'l': // remove last item from the list
            list = removeLast(list);
            break;

        case 'c': // find closest complex number
            get_complex_number(&re, &im);
            node_t *closest = findClosest(list, re, im);
            if (closest != NULL)
            {
                printf("Closest number is ");
                print_complex_number(closest);
                printf("\n");
            }
            else
            {
                printf("No closest number found\n");
            }
            break;

        case 'a':
            get_complex_number(&re, &im);
            list = insertAfterClosest(list, re, im);
            break;

        case 'b':
            get_complex_number(&re, &im);
            list = insertBeforeClosest(list, re, im);
            break;

        case 'v':
            printf("[");
            printListReverse(list);
            printf("]\n");
            break;

        case 'r':
            get_complex_number(&re, &im);
            list = removeClosest(list, re, im);
            break;

        default:
            printf("Unknown command '%c'\n", cmd);
            break;
        }
    } while (cmd != 'q');

    return 0;
}
