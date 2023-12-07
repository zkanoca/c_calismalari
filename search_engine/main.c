#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define MAXLINKS 10

typedef struct _page_t
{
    char *url;
    int visited;
    struct _page_t *links[MAXLINKS];
    struct _page_t *next;
} page_t;

// Task 1: get command and q command
void getCommand(char *cmd);
void quit();
// Task 2: get new url and p command
void getNewURL(char *newURL);
void addPage(page_t **web, char *url);
// Task 3: print web and w command
void printWeb(page_t *web);
// Task 4: find page and f command
void getTargetURL(char *targetURL);
page_t *findPage(page_t *web, char *url);

int main()
{
    char cmd;
    page_t *web = NULL;
    char newURL[MAXLEN];
    char targetURL[MAXLEN];

    do
    {
        getCommand(&cmd);

        switch (cmd)
        {
        case 'q':
            quit();
            break;
        case 'p':
            getNewURL(newURL);
            addPage(&web, newURL);
            break;
        case 'w':
            printWeb(web);
            break;
        default:
            printf("Unknown command '%c'\n", cmd);
            break;
        case 'f':
            getTargetURL(targetURL);
            findPage(web, targetURL);
            break;
        }
    } while (cmd != 'q');

    return 0;
}

void getCommand(char *cmd)
{
    printf("Command?: ");
    scanf(" %c", cmd);
}

void quit()
{
    printf("Bye!\n");
    exit(0);
}

void getNewURL(char *newURL)
{
    printf("Page URL? ");
    scanf("%s", newURL);
}

void addPage(page_t **web, char *url)
{
    // Check if URL already in the list
    page_t *current = *web;
    while (current != NULL)
    {
        if (strcmp(current->url, url) == 0)
        {
            // if so, print the error message
            printf("URL \"%s\" is already on the web\n", url);
            return;
        }
        current = current->next;
    }

    // Create a new page
    page_t *newPage = (page_t *)malloc(sizeof(page_t));
    newPage->url = strdup(url); // Allocate memory for URL and copy the string
    //
    newPage->visited = -1;

    // empty all page URLs list
    for (int i = 0; i < MAXLINKS; ++i)
    {
        newPage->links[i] = NULL;
    }
    newPage->next = NULL;

    // Insert the new page at the correct position in the linked list
    if (*web == NULL || strcmp((*web)->url, url) > 0)
    {
        newPage->next = *web;
        *web = newPage;
    }
    else
    {
        current = *web;

        while (current->next != NULL && strcmp(current->next->url, url) < 0)
        {
            current = current->next;
        }

        newPage->next = current->next;
        current->next = newPage;
    }
}

void printWeb(page_t *web)
{
    page_t *current = web;
    while (current != NULL)
    {
        printf("{URL=\"%s\",visited=%d} -> ", current->url, current->visited);

        // Print links
        for (int i = 0; i < MAXLINKS && current->links[i] != NULL; ++i)
        {
            printf("\"%s\" ", current->links[i]->url);
        }

        printf("\n");
        current = current->next;
    }
}

void getTargetURL(char *targetURL)
{
    printf("Page URL? ");
    scanf("%s", targetURL);
}

page_t *findPage(page_t *web, char *url)
{
    page_t *current = web;
    while (current != NULL)
    {
        if (strcmp(current->url, url) == 0)
        {
            printf("URL \"%s\" is on the web\n", url);
            return current;
        }
        current = current->next;
    }
    printf("URL \"%s\" is not on the web\n", url);
    return NULL;
}
