#include <stdio.h>
#include <string.h>
//Uncomment
//#include <libpynq.h>

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 240

// Maze characters
#define START 'S'       /* starting position */
#define DESTINATION 'D' /* destination */
#define WALL '#'        /* wall */
#define NOT_VISITED '.' /* corridor */

#define PATH '+'    /* part of the current path */
#define VISITED '~' /* corridor; part of a past path */

//Bu silinecek
enum colors
{
    RGB_RED = 0xf800,
    RGB_GREEN = 0x07e0,
    RGB_BLUE = 0x001f,
    RGB_BLACK = 0x0000,
    RGB_WHITE = 0xffff,
    RGB_GRAY = 0x8c51,
    RGB_YELLOW = 0xFFE0,
    RGB_CYAN = 0x07FF,
    RGB_PURPLE = 0xF81F
};


//Bu silinecek
typedef struct
{
    int _width;
    int _height;
    int _offsetx;
    int _offsety;
    int _font_direction;
    int _font_fill;
    int _font_fill_color;
    int _font_underline;
    int _font_underline_color;
    int _dc;
    int _bl;
} display_t;

typedef struct
{
    int x;
    int y;
} coordinate_t;

typedef struct
{
    char grid[DISPLAY_WIDTH][DISPLAY_HEIGHT];
    coordinate_t size;
} maze_t;

//calisiyor
void inputMaze(maze_t *maze)
{
    int rows, cols, i, j;
    int countOfS = 0;

    printf("Number of rows? ");
    scanf("%d", &rows);

    printf("Number of columns? ");
    scanf("%d", &cols);

    if (rows < 2 || cols < 2)
    {
        printf("Rows and column count cannot be less than 2\n");
        maze->size.x = -1;
        maze->size.y = -1;
        return;
    }

    maze->size.x = cols;
    maze->size.y = rows;

    for (i = 0; i < rows; i++)
    {
        printf("Input row %2d: ", i);
        scanf("%s", &maze->grid[i][0]);

        for (j = 0; j < cols; j++)
        {
            if (maze->grid[i][j] == START)
            {
                if (countOfS == 0)
                {
                    countOfS++;
                }
                else
                {
                    printf("Dropping extra starting point\n");
                    maze->grid[i][j] = WALL;
                }
            }
        }
    }
}

//calisiyor
void printMaze(const maze_t *maze)
{
    int i, j;

    // maze size is valid?
    if (maze->size.x <= 0 || maze->size.y <= 0)
    {
        return;
    }

    for (i = 0; i < maze->size.y; i++)
    {
        for (j = 0; j < maze->size.x; j++)
        {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

//test edilecek
void displayMaze(display_t *display, maze_t *maze)
{
    if (maze->size.x <= 0 || maze->size.y <= 0)
    {
        return;
    }

    int rectWidth = DISPLAY_WIDTH / maze->size.x;
    int rectHeight = DISPLAY_HEIGHT / maze->size.y;
    int i, j;
    // displayFillScreen(display, RGB_BLACK); // Clear display

    for (i = 0; i < maze->size.y; i++)
    {
        for (j = 0; j < maze->size.x; j++)
        {
            int color;
            int x1 = j * rectWidth;
            int y1 = i * rectHeight;
            int x2 = x1 + rectWidth - 1;
            int y2 = y1 + rectHeight - 1;

            switch (maze->grid[i][j])
            {
            case WALL:
                color = RGB_RED;
                break;
            case PATH:
                color = RGB_YELLOW;
                break;
            case START:
                color = RGB_BLUE;
                break;
            case DESTINATION:
                color = RGB_GREEN;
                break;
            case VISITED:
                color = RGB_GRAY; // rgb_conv(100,100,100);
                break;
            case NOT_VISITED:
            default:
                color = RGB_BLACK;
                break;
            }

            // displayDrawFillRect(display, j * rectWidth, i * rectHeight, rectWidth, rectHeight, color);
            printf("dfr %d %d %d %d %d\n", x1, y1, x2, y2, color);
        }
    }
}

coordinate_t findStartDestination(maze_t *maze, coordinate_t *destination)
{
    int x, y, z = 0;
    coordinate_t start = {-1, -1};

    destination->x = -1;
    destination->y = -1;

    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            if (maze->grid[y][x] == START)
            {
                if (start.y == -1 || start.x == -1)
                {
                    start.x = x;
                    start.y = y;
                }
            }

            if (maze->grid[y][x] == DESTINATION)
            {
                if (destination->y == -1 || destination->x == -1)
                {
                    // break;
                    destination->x = x;
                    destination->y = y;
                }
            }
        }
    }

    return start;
}



//calisiyor
void swapStartDestination(maze_t *maze, coordinate_t *start, coordinate_t *destination)
{
    // Are there really start and destination points?
    if (start->x == -1 || destination->x == -1)
    {
        return; // quit function if not
    }

    int foundStart = 0, foundDestination = 0;
    int x, y;

    // Find START and replace a temporary character '!'
    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            if (maze->grid[y][x] == START)
            {
                maze->grid[y][x] = '!';
                foundStart = 1;
                break;
            }
        }
        if (foundStart)
            break;
    }

    // Find DESTINATION and replace with START
    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            if (maze->grid[y][x] == DESTINATION)
            {
                maze->grid[y][x] = START;
                destination->y = y;
                destination->x = y;
                foundDestination = 1;
                break;
            }
        }
        if (foundDestination)
            break;
    }

    // Find '!' and replace it with DESTINATION
    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            if (maze->grid[y][x] == '!')
            {
                maze->grid[y][x] = DESTINATION;
                start->x = x;
                start->y = y;
                break;
            }
        }
    }
}

void mirrorMaze(maze_t *maze)
{
    int x,y;
    char mirror[DISPLAY_WIDTH][DISPLAY_HEIGHT];

    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            mirror[y][x] = maze->grid[x][y];
        }
    }

    // Rotate the maze
    int tmpSize = maze->size.y;
    maze->size.y = maze->size.x;
    maze->size.x = tmpSize;

    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            maze->grid[y][x] = mirror[y][x];
        }
    }
}


int findPath(display_t *display, maze_t *maze, coordinate_t c, int length)
{
    //  printf("x:%d, y:%d\nlength: %d\n", c.x, c.y, length);
    if (c.x < 0 || c.x >= maze->size.x || c.y < 0 || c.y >= maze->size.y)
    {
        return 0; // if ((x,y) outside maze) return 0
    }
    if (maze->grid[c.y][c.x] == WALL || maze->grid[c.y][c.x] == PATH || maze->grid[c.y][c.x] == VISITED) // wall or visited
    {
        return 0; // if ((x,y) is blocked or already visited) return 0
    }
    if (maze->grid[c.y][c.x] == DESTINATION) // destination
    {
        return length; // if ((x,y) is the destination) return length
    }

    // if we get here we didn’t find a solution in N,E,S, or W directions
    // mark (x,y) as visited (if (x,y) isn’t the start)
    if (maze->grid[c.y][c.x] != START)
    {
        maze->grid[c.y][c.x] = PATH;
    }

    coordinate_t cN, cE, cS, cW;
    int N, E, S, W;

    // try to find a path in North, East, South, and West directions
    cN.x = c.x;
    cN.y = c.y - 1;
    N = findPath(display, maze, cN, length + 1); // North
    if (N > 0)
    {
        // printf("\nThere is a path to N");
        return N;
    }

    cE.x = c.x + 1;
    cE.y = c.y;
    E = findPath(display, maze, cE, length + 1); // East
    if (E > 0)
    {
        // printf("\nThere is a path to E");
        return E;
    }

    cS.x = c.x;
    cS.y = c.y + 1;
    S = findPath(display, maze, cS, length + 1); // South
    if (S > 0)
    {
        // printf("\nThere is a path to S");
        return S;
    }

    cW.x = c.x - 1;
    cW.y = c.y;
    W = findPath(display, maze, cW, length + 1); // West
    if (W > 0)
    {
        // printf("\nThere is a path to W");
        return W;
    }

    //  if no path is found from this point then go back
    if (maze->grid[c.y][c.x] != START)
    {
        maze->grid[c.y][c.x] = VISITED;
    }

    return 0;
}

//calisiyor
void resetPath(maze_t *maze)
{
    int x,y;
    
    for (y = 0; y < maze->size.y; y++)
    {
        for (x = 0; x < maze->size.x; x++)
        {
            if (maze->grid[y][x] == PATH || maze->grid[y][x] == VISITED)
            {
                maze->grid[y][x] = NOT_VISITED;
            }
        }
    }
}

int longestPath(maze_t *maze, coordinate_t c, int length)
{
    int x = c.x;
    int y = c.y;

    // Are we in the maze?
    if (x < 0 || x >= maze->size.x || y < 0 || y >= maze->size.y)
    {
        return 0;
    }

    // Is the current cell a WALL or VISITED or PATH
    if (maze->grid[y][x] == WALL || maze->grid[y][x] == PATH /*|| maze->grid[y][x] == START*/)
    {
        return 0;
    }

    // Have we got to the destination point
    if (maze->grid[y][x] == DESTINATION)
    {
        printf("Found a path of length %d\n", length);
        return length;
    }

    // Mark the current point as visited
    if (maze->grid[y][x] != START)
    {
        maze->grid[y][x] = PATH;
    }

    // Recursively search in all four directions: N, E, S, W
    int longest = 0;

    int N, E, S, W;
    coordinate_t cN, cE, cS, cW;

    cN.x = c.x;
    cN.y = c.y - 1;
    N = longestPath(maze, cN, length + 1);
    longest = (N > longest) ? N : longest;

    cE.x = c.x + 1;
    cE.y = c.y;
    E = longestPath(maze, cE, length + 1);
    longest = (E > longest) ? E : longest;

    cS.x = c.x;
    cS.y = c.y + 1;
    S = longestPath(maze, cS, length + 1);
    longest = (S > longest) ? S : longest;

    cW.x = c.x - 1;
    cW.y = c.y;
    W = longestPath(maze, cW, length + 1);
    longest = (W > longest) ? W : longest;

    // Unmark the current point to revisit if not START
    if (maze->grid[y][x] != START)
    {
        maze->grid[y][x] = NOT_VISITED;
    }

    return longest;
}

int main()
{
    //uncomment edilecek
    // pynq_init();
    // color_leds_init_pwm();
    display_t *display;
    // display_init(&display);
    // displayFillScreen(&display, RGB_BLACK);

    char cmd;
    /*
    command operation
    f       find a path
    
    l       find the longest path

    */
    maze_t maze;
    maze.size.x = -1;
    maze.size.y = -1;
    coordinate_t start;
    coordinate_t destination;
    int length;

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
            inputMaze(&maze);
            break;
        case 'p':
            printMaze(&maze);
            break;
        case 'd':
            displayMaze(display, &maze);
            break;
        case 's':
            start = findStartDestination(&maze, &destination);
            if (start.x == -1)
            {
                printf("Maze contains no start\n");
            }
            else
            {
                printf("The start is at     (%3d,%3d)\n", start.x, start.y);
            }
            if (destination.x == -1)
            {
                printf("Maze contains no destination\n");
            }
            else
            {
                printf("The first destination is at (%3d,%3d)\n", destination.x, destination.y);
            }
            break;
        case 'S':
            swapStartDestination(&maze, &start, &destination);

            break;
        case 'm':
            mirrorMaze(&maze);
            break;
        case 'f':

            start = findStartDestination(&maze, &destination);

            length = findPath(display, &maze, start, 0);
            
            if (length > 0)
            {
                printf("Found a path of length %d\n", length);
            }
            else
            {
                printf("No path found\n");
            }
            printMaze(&maze);
            break;
        case 'r':
            resetPath(&maze);
            break;
        case 'l':
            start = findStartDestination(&maze, &destination);

            longest = longestPath(&maze, start, 0);

            printf("The length of the longest path is %d\n", longest);
            break;
        default:
            printf("Unknown command '%c'\n", cmd);
        }
    } while (cmd != 'q');

    //uncomment edilecek
    // display_destroy();
    return 0;
}
