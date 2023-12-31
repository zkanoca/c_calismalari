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

// Task 1: get command and "q" command
void getCommand(char *cmd);
void quit(page_t *web);
// Task 2: get new url and "p" command
void getURL(char *url);
void addPage(page_t **web, char *url);
// Task 3: print web and "w" command
void printWeb(page_t *web);
// Task 4: find page and "f" command
page_t *findPage(page_t *web, char *url);
page_t *printSearchResult(page_t *searchResult, char *targetURL);
// Task 5:  add a link to a page and "a" command
void askURLs(char *source, char *destination);
void addLink(page_t *web, char *source_url, char *dest_url);
// Task 6: remove a page and "P" command
void removePage(page_t **web, char *url);
// task 7: remove page fucntion (extended)
void removePageExtended(page_t **web, char *url);
void updateLinks(page_t **web, page_t *current);

int main()
{
    char cmd;
    page_t *web = NULL;
    char newURL[MAXLEN];
    char targetURL[MAXLEN];
    char source[MAXLEN];
    char destination[MAXLEN];
    page_t *searchResult;

    do
    {
        getCommand(&cmd);

        switch (cmd)
        {
        case 'q':
            quit(web);
            break;
        case 'p':
            getURL(newURL);
            addPage(&web, newURL);
            break;
        case 'w':
            printWeb(web);
            break;
        case 'f':
            getURL(targetURL);
            searchResult = findPage(web, targetURL);
            printSearchResult(searchResult, targetURL);
            break;
        case 'l':
            askURLs(source, destination);
            // printf("Source: %s\n", source);
            // printf("Destination: %s\n", destination);
            addLink(web, source, destination);
            break;
        case 'P':
        {
            getURL(targetURL);
            // removePage(&web, targetURL); //Task 6
            removePageExtended(&web, targetURL); // Task 7
            break;
        }
        default:
            printf("Unknown command '%c'\n", cmd);
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

void quit(page_t *web)
{

    while (web != NULL)
    {
        page_t *temp = web;
        web = web->next;
        free(temp->url);
        free(temp);
    }
    printf("Bye!\n");
    exit(0);
}

void addPage(page_t **web, char *url)
{
    // Check if URL already in the list
    page_t *current = *web;
    while (current != NULL)
    {
        // if so, print the error message
        if (strcmp(current->url, url) == 0)
        {
            // if so, print the error message
            printf("URL \"%s\" is already on the web\n", url);
            return;
        }
        // otherwise, move to the next page
        current = current->next;
    }

    // Create a new page
    page_t *newPage = (page_t *)malloc(sizeof(page_t));
    // duplicate url string and store it in the new page
    newPage->url = strdup(url);
    // initially visited value is -1
    newPage->visited = -1;

    // empty all page URLs list
    for (int i = 0; i < MAXLINKS; ++i)
    {
        newPage->links[i] = NULL;
    }
    newPage->next = NULL;

    // Insert the new page at the correct position in the linked list
    // in order to have an alphabetically ordered list
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
        // for (int i = 0; i < MAXLINKS; ++i)
        {
            printf("\"%s\" ", current->links[i]->url);
        }

        printf("\n");
        current = current->next;
    }
}

void getURL(char *url)
{
    printf("Page URL? ");
    scanf("%s", url);
}

page_t *findPage(page_t *web, char *url)
{
    // page_t *current = web;
    while (web != NULL)
    {
        // if there is a match, return the current page and exit the loop
        if (strcmp(web->url, url) == 0)
        {
            return web;
        }
        // if there is no match, move to the next page
        web = web->next;
    }

    // if url is not found then return NULL
    return NULL;
}

page_t *printSearchResult(page_t *searchResult, char *targetURL)
{
    printf("URL \"%s\" is ", targetURL);
    if (searchResult != NULL)
    {
        printf("not ");
    }
    printf("on the web\n");
}

void askURLs(char *source, char *destination)
{
    // Source & destination URL? no-page twotter.bu

    printf("Source & destination URL? ");
    scanf("%s %s", source, destination);
    // printf("Source URL: %s\n", source);
    // printf("Destination URL: %s\n", destination);
}

void addLink(page_t *web, char *source_url, char *dest_url)
{
    // Check if source and destination URLs exist
    page_t *sourcePage = findPage(web, source_url);
    page_t *destPage = findPage(web, dest_url);

    // if source url is not a member of the list then print the error message and return
    if (sourcePage == NULL)
    {
        printf("Source URL \"%s\" is not on the web\n", source_url);
        return;
    }

    // if destination url is not a member of the list then print the error message and return
    if (destPage == NULL)
    {
        printf("Destination URL \"%s\" is not on the web\n", dest_url);
        return;
    }

    // a page cannot be linked to itself, so check if the source and destination URLs are the same
    if (sourcePage == destPage)
    {
        printf("Source and destination URL cannot be the same\n");
        return;
    }

    // if  source and destination urls exist and are not the same, add the link from source to destination

    int index = -1;
    int i = 0;
    // Check if the link already exists
    while (i < MAXLINKS)
    {
        if (sourcePage->links[i] == destPage)
        {
            printf("\"%s\" is already a destination for \"%s\"\n", dest_url, source_url);
            return;
        }
        i++;
    }

    // Find the first available NULL position in the links array of the source page
    i = 0;
    while (i < MAXLINKS)
    {
        if (sourcePage->links[i] == NULL)
        {
            index = i;
            break;
        }
        i++;
    }

    // if index is still -1 which means there is no available NULL position in the links array,
    // print the error message and return.
    if (index == -1)
    {
        printf("Maximum number of links reached\n");
        return;
    }

    // if everything is fine, add the link from source to destination and print the success message.
    sourcePage->links[index] = destPage;
}

// Task 6: remove a page and "P" command
void removePage(page_t **web, char *url)
{
    page_t *current = *web;
    page_t *prev = NULL;
    int i;
    int hasLinks = 0;

    while (current != NULL)
    {
        if (strcmp(current->url, url) == 0)
        {
            hasLinks = 0;
            for (i = 0; i < MAXLINKS; ++i)
            {
                if (current->links[i] != NULL)
                {
                    hasLinks = 1;
                    break;
                }
            }

            if (!hasLinks)
            {
                if (prev == NULL)
                {
                    *web = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                free(current->url);
                free(current);
                return;
            }
        }
        prev = current;
        current = current->next;
    }

    printf("URL \"%s\" is not on the web\n", url);
}

// Task 7: remove page fucntion (extended)
void removePageExtended(page_t **web, char *url)
{
    page_t *current = *web;
    page_t *prev = NULL;
    int i, j;

    while (current != NULL)
    {
        if (strcmp(current->url, url) == 0)
        {
            if (prev == NULL)
            {
                *web = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Update links array in other pages
            updateLinks(web, current);

            free(current->url);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("URL \"%s\" is not on the web\n", url);
}

// helping function for task 7: remove page fucntion (extended)
void updateLinks(page_t **web, page_t *current)
{
    int i, j;
    page_t *temp = *web;

    while (temp != NULL)
    {
        for (i = 0; i < MAXLINKS; ++i)
        {
            if (temp->links[i] == current)
            {
                // Shift links to the left onto the NULL slots
                for (j = i; j < MAXLINKS - 1; ++j)
                {
                    temp->links[j] = temp->links[j + 1];
                }
                // Set the last link to NULL
                temp->links[MAXLINKS - 1] = NULL;
            }
        }
        temp = temp->next;
    }
}
