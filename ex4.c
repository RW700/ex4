/******************
Name: #TODO: ADD AFTER PUSHED TO GITHUB
ID: #TODO: ADD AFTER PUSHED TO GITHUB
Assignment: ex4
*******************/
#include <stdio.h>
#include <string.h>

#define ROBOT_PATHS 1
#define HUMAN_PYRAMID 2
#define PARENTHESIS_VALIDATOR 3
#define QUEENS_BATTLE 4
#define CROSSWORD_GENERATOR 5
#define EXIT 6
#define PYRAMID_MAX_DIMENSION 5
#define QUEENS_MAX_SIZE 20
#define CROSSWORD_MAX_GRID 30
#define CROSSWORD_MAX_SLOTS 100
#define CROSSWORD_MAX_WORDS 100
#define CROSSWORD_MAX_WORD_LENGTH 15
#define CROSSWORD_SLOT_DATA 4

int task1RobotPaths();
float task2HumanPyramid();
char task3ParenthesisValidator(char parenthesisInput);
int task4QueensBattle();
int task5CrosswordGenerator();
void putSlotsInGrid(char grid[CROSSWORD_MAX_GRID][CROSSWORD_MAX_GRID], int row, int col, int length, char direction);

int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            switch (task)
            {
            case ROBOT_PATHS:
                int row, column;
                printf("Please enter the coordinates of the robot (column, row):\n");
                scanf("\n%d %d", &column, &row);
                printf("The total number of paths the robot can take to reach home is: %d\n", task1RobotPaths(column, row, 0));
                break;
            case HUMAN_PYRAMID:
                float weights[PYRAMID_MAX_DIMENSION][PYRAMID_MAX_DIMENSION] = {0};

                printf("Please enter the weights of the cheerleaders:\n");
                scanf("\n%f", &weights[0][0]);
                scanf("\n%f %f", &weights[1][0], &weights[1][1]);
                scanf("\n%f %f %f", &weights[2][0], &weights[2][1], &weights[2][2]);
                scanf("\n%f %f %f %f", &weights[3][0], &weights[3][1], &weights[3][2], &weights[3][3]);
                scanf("\n%f %f %f %f %f", &weights[4][0], &weights[4][1], &weights[4][2], &weights[4][3], &weights[4][4]);

                // loop through 15 places, and feed location as well as weights to recursive function
                // which will sum up the weights and return weight at location
                // so print recursive functions return directly
                for (int i = 0; i < PYRAMID_MAX_DIMENSION; i++) {
                    for (int j = 0; j <= i; j++) {
                        printf("%.2f ", task2HumanPyramid(i, j, weights));
                    }
                    printf("\n");
                }

                break;
            case PARENTHESIS_VALIDATOR:

                char parenInput;
                int balanced = 0;
                int end = 0;

                //clear buffer
                scanf("%*[\n]");

                while (!end) {
                    scanf("%c", &parenInput);
                    if (parenInput == '\n') {
                        balanced = 1;
                        end = 1;
                    }
                    if (parenInput == '>' || parenInput == ')' || parenInput == ']' || parenInput == '}') {
                        balanced = 0;
                        while (parenInput != '\n') {
                            scanf("%c", &parenInput);
                        }
                        end = 1;
                    }
                    if (parenInput == '<' || parenInput == '(' || parenInput == '[' || parenInput == '{') {
                        switch (task3ParenthesisValidator(parenInput)) {
                            case '-': //unbalanced unended
                                balanced = 0;
                                while (parenInput != '\n') {
                                    scanf("%c", &parenInput);
                                }
                                end = 1;
                                break;
                            case '!': //unbalanced ended
                                balanced = 0;
                                end = 1;
                                break;
                            case '+': //balanced ended - technically never happens
                                balanced = 1;
                                end = 1;
                                break;
                            case '=': //balanced unended
                                balanced = 1;
                                break;
                        }
                    }
                }

                if (balanced) {
                    printf("The parentheses are balanced correctly.\n");
                }
                else {
                    printf("The parentheses are not balanced correctly.\n");
                }
                break;
            case QUEENS_BATTLE:

                int boardSize;
                printf("Please enter the board dimensions:\n");
                scanf("\n%d", &boardSize);
                printf("Please enter the %d*%d puzzle board:\n", boardSize, boardSize);
                char board[QUEENS_MAX_SIZE][QUEENS_MAX_SIZE];
                for (int i = 0; i < boardSize; i++)
                {
                    for (int j = 0; j < boardSize; j++)
                    {
                        scanf(" %c", &board[i][j]);
                    }
                }
                if (task4QueensBattle(board, boardSize, 0, 0, "", "", 0) == 1) {
                    printf("Solution:\n");
                    for (int i = 0; i < boardSize; i++)
                    {
                        for (int j = 0; j < boardSize; j++)
                        {
                            if (board[i][j] != 'X') {
                                printf("* ");
                            }
                            else {
                                printf("%c ", board[i][j]);
                            }
                        }
                        printf("\n");
                    }
                } else {
                    printf("This puzzle cannot be solved.\n");
                }

                break;
            case CROSSWORD_GENERATOR:

                // get grid size
                int gridSize;
                printf("Please enter the dimensions of the crossword grid:\n");
                scanf("\n%d", &gridSize);

                // get number of slots
                int numSlots;
                printf("Please enter the number of slots in the crossword:\n");
                scanf("\n%d", &numSlots);

                // set up grid
                char crossWord[CROSSWORD_MAX_GRID][CROSSWORD_MAX_GRID];
                // initialize grid to blank
                for (int i = 0; i < gridSize; i++)
                {
                    for (int j = 0; j < gridSize; j++)
                    {
                        crossWord[i][j] = '#';
                    }
                }

                // get slot details
                char slotData[CROSSWORD_MAX_SLOTS][CROSSWORD_SLOT_DATA];
                printf("Please enter the details for each slot (Row, Column, Length, Direction):\n");
                for (int i = 0; i < numSlots; i++) {
                    scanf("\n%c %c %c %c", &slotData[i][0], &slotData[i][1], &slotData[i][2], &slotData[i][3]);
                    putSlotsInGrid(crossWord, slotData[i][0] - '0', slotData[i][1] - '0', slotData[i][2] - '0', slotData[i][3]);
                }

                // get number of words
                int numWords = 0;
                printf("Please enter the number of words in the dictionary:\n");
                scanf("\n%d", &numWords);
                while (numWords < numSlots) {
                    scanf("%*[^\n]");
                    printf("The dictionary must contain at least %d words. Please enter a valid dictionary size:\n", numSlots);
                    scanf("\n%d", &numWords);
                }

                // get words
                printf("Please enter the words for the dictionary:\n");
                char words[CROSSWORD_MAX_WORDS][CROSSWORD_MAX_WORD_LENGTH];
                for (int i = 0; i < numWords; i++) {
                    scanf("\n%s", words[i]);
                }

                int indexesUsed[CROSSWORD_MAX_WORDS] = {0};
                int wordAtSlot[CROSSWORD_MAX_SLOTS] = {-1};

                if (task5CrosswordGenerator(crossWord, words, slotData, indexesUsed, wordAtSlot, gridSize, numSlots, numWords, 0, 0) == 1) {
                    printf("Solution:\n");
                    for (int i = 0; i < gridSize; i++)
                    {
                        printf("| ");
                        for (int j = 0; j < gridSize; j++)
                        {
                            printf("%c | ", crossWord[i][j]);
                        }
                        printf("\n");
                    }

                }
                else {
                    printf("This puzzle cannot be solved.\n");
                }

                break;
            case EXIT:
                printf("Goodbye!\n");
                break;
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != EXIT);
}

int task1RobotPaths(int row, int column, int numPaths) {
    //if negative coordinates, return 0
    if (row < 0 || column < 0) {
        return 0;
    }
    //base case - hit wall, only one way left back to base
    if (row == 0 || column == 0) {
        return 1;
    }
    // recursive property: move down + move left, num of paths if move left + if move down
    return task1RobotPaths(row-1, column, numPaths) + task1RobotPaths(row, column-1, numPaths);
}

float task2HumanPyramid(int row, int column, float weights[PYRAMID_MAX_DIMENSION][PYRAMID_MAX_DIMENSION]) {
    // get location and weight
    // if row = 0, return weight
    if (row == 0) {
        return weights[0][0];
    }
    // if location is 0 or equal to row number -1, return weight + 1/2 row above first or last respectively
    if (column == 0) {
        return weights[row][column] + (0.5 * task2HumanPyramid(row-1, column, weights));
    }
    if (column == row) {
        return weights[row][column] + (0.5 * task2HumanPyramid(row-1, column-1, weights));
    }
    // else return weight + 1/2 row above left 1/2 row above left right
    return weights[row][column] + (0.5 * task2HumanPyramid(row-1, column-1, weights)) +
        (0.5 * task2HumanPyramid(row-1, column, weights));

}

char task3ParenthesisValidator(char parenthesisInput) {

    char endChar;
    char newInput;
    switch (parenthesisInput) {
        case '(':
            endChar = ')';
            break;
        case '[':
            endChar = ']';
            break;
        case '{':
            endChar = '}';
            break;
        case '<':
            endChar = '>';
            break;
    }

    int end = 0;

    while (!end) {
        scanf("%c", &newInput);
        if (newInput == '\n') {
            return '!'; //unbalanced ended
        }
        if (newInput == ')' || newInput == ']' || newInput == '}' || newInput == '>') {
            if (newInput != endChar) {
                return '-'; //unbalanced unended
            }
            return '='; //balanced unended
        }
        if (newInput == '(' || newInput == '[' || newInput == '{' || newInput == '<') {
            switch (task3ParenthesisValidator(newInput)) {
                case '!':
                    return '!'; //unbalanced ended
                case '-':
                    return '-'; //unbalanced unended
                case '=':
                    break;
            }
        }
    }
}

int task4QueensBattle(char board[QUEENS_MAX_SIZE][QUEENS_MAX_SIZE], int boardSize, int row, int col,
                        char colorsDone[QUEENS_MAX_SIZE], char columnsDone[QUEENS_MAX_SIZE], int numDone) {
    //base case: slotted in all queens or broke past end of board
    if (numDone == boardSize) {
        return 1;
    }
    if (row == boardSize) {
        return 0;
    }

    // if color in list - next cell
    char currentColor = board[row][col];
    if (strchr(colorsDone, currentColor) != NULL) {
        //next cell
        if (col + 1 == boardSize) {
            return task4QueensBattle(board, boardSize, row + 1, 0, colorsDone, columnsDone, numDone);
        }
        return task4QueensBattle(board, boardSize, row, col + 1, colorsDone, columnsDone, numDone);
    }
    // if column in list - next cell
    if (strchr(columnsDone, col + '0') != NULL) {
        //next cell
        if (col + 1 == boardSize) {
            return task4QueensBattle(board, boardSize, row + 1, 0, colorsDone, columnsDone, numDone);
        }
        return task4QueensBattle(board, boardSize, row, col + 1, colorsDone, columnsDone, numDone);

    }

    // if touching - next cell
    int touchingX = 0;
    // if corner - check 3 adj. cells
    // if not corner but side check adj. 5 cells
    // if not side or corner check all 8 adj cells
    if (row == 0) {
        if (col == 0) {
            //check 3 adj cells
            if (board[row][col+1] == 'X' || board[row+1][col] == 'X' || board[row+1][col+1] == 'X') {
                touchingX=1;
            }
        } else if (col == boardSize - 1) {
            // check 3 adj cells
            if (board[row][col-1] == 'X' || board[row+1][col-1] == 'X' || board[row+1][col] == 'X') {
                touchingX=1;
            }
        } else {
            // check 5 adj cells
            if (board[row][col-1] == 'X' || board[row+1][col-1] == 'X' || board[row+1][col] == 'X' ||
                board[row+1][col+1] == 'X' || board[row][col+1] == 'X') {
                touchingX=1;
            }
        }
    } else if (row == boardSize - 1) {
        if (col == 0) {
            // chcek 3 adj
            if (board[row-1][col] == 'X' || board[row-1][col+1] == 'X' || board[row][col+1] == 'X') {
                touchingX=1;
            }
        } else if (col == boardSize -1 ) {
            // check 3 adj
            if (board[row-1][col] == 'X' || board[row-1][col-1] == 'X' || board[row][col-1] == 'X') {
                touchingX=1;
            }
        } else {
            // check 5 adj cells
            if (board[row][col-1] == 'X' || board[row-1][col-1] == 'X' || board[row-1][col] == 'X' ||
                board[row-1][col+1] == 'X' || board[row][col+1] == 'X') {
                touchingX=1;
            }
        }
    } else if (col == 0) {
        //check 5 adj cells
        if (board[row-1][col] == 'X' || board[row-1][col+1] == 'X' || board[row][col+1] == 'X' ||
            board[row+1][col+1] == 'X' || board[row+1][col] == 'X') {
            touchingX=1;
        }
    } else if (col == boardSize -1) {
        // check 5 adj
        if (board[row-1][col] == 'X' || board[row-1][col-1] == 'X' ||
            board[row][col-1] == 'X' || board[row+1][col-1] == 'X' || board[row+1][col] == 'X') {
            touchingX=1;
        }
    } else {
        // check all 8
        if ( board[row-1][col-1] == 'X' || board[row-1][col] == 'X' || board[row-1][col+1] == 'X' ||
             board[row][col-1] == 'X' || board[row][col+1] == 'X' ||
             board[row+1][col-1] == 'X' || board[row+1][col] == 'X' || board[row+1][col+1] == 'X') {
            touchingX=1;
        }
    }

    if (touchingX == 1) {
        //next cell
        if (col + 1 == boardSize) {
            return task4QueensBattle(board, boardSize, row + 1, 0, colorsDone, columnsDone, numDone);
        }
        return task4QueensBattle(board, boardSize, row, col + 1, colorsDone, columnsDone, numDone);
    }
    // otherwise - put X and if recursion doesn't work undo and try next cell:
    board[row][col] = 'X';

    char newColumns[QUEENS_MAX_SIZE];
    strncpy(newColumns, columnsDone, QUEENS_MAX_SIZE);
    strcat(newColumns, (char[]){(char)(col + '0'), '\0'});
    char newColors[QUEENS_MAX_SIZE];
    strncpy(newColors, colorsDone, QUEENS_MAX_SIZE);
    strcat(newColors, &currentColor);

    if (task4QueensBattle(board, boardSize, row+1, 0, newColors, newColumns, numDone+1) == 1) {
        return 1;
    }


    board[row][col] = currentColor;
    if (col + 1 == boardSize) {
        return task4QueensBattle(board, boardSize, row + 1, 0, colorsDone, columnsDone, numDone);
    }
    return task4QueensBattle(board, boardSize, row, col + 1, colorsDone, columnsDone, numDone);


    // create separate function to check if valid by checking diagonals and touching and one queen per color/letter
    // if valid, place queen and move on to next row
    // resultsBoard[row][col] == '*';

}

void putSlotsInGrid(char grid[CROSSWORD_MAX_GRID][CROSSWORD_MAX_GRID], int row, int col, int length, char direction) {
    switch (direction) {
        case 'H':
            for (int i = 0; i < length; i++) {
                grid[row][col+i] = '_';
            }
            break;
        case 'V':
            for (int i = 0; i < length; i++) {
                grid[row+i][col] = '_';
            }
            break;
    }
}

void putWordInGrid(char grid[CROSSWORD_MAX_GRID][CROSSWORD_MAX_GRID], int row, int col, int length, char direction, char word[CROSSWORD_MAX_WORD_LENGTH]) {
    switch (direction) {
        case 'H':
            for (int i = 0; i < length; i++) {
                // if (grid[row][col+i] == '_' || grid[row][col+i] == word[i]) {
                grid[row][col+i] = word[i];
                // } else {
                    // return 0;
                // }
            }
        break;
        case 'V':
            for (int i = 0; i < length; i++) {
                // if (grid[row+i][col] == '_' || grid[row+i][col] == word[i]) {
                grid[row+i][col] = word[i];
                // } else {
                    // return 0;
                // }
            }
        break;
    }
    // return 1;
}

void checkConflict(int indexesUsed[CROSSWORD_MAX_WORDS], char slotData[CROSSWORD_MAX_SLOTS][CROSSWORD_SLOT_DATA],
                    char conflicts[CROSSWORD_MAX_SLOTS], int wordIndex, int slotToCheck, int currentSlot) {

    // return when checked everything, conflicts will be empty if no conflicts

    // WHILE AT SLOT < CURRENT - CAUSE SLOTS WE DO IN ORDER:
    if (currentSlot == slotToCheck) {
        return;
    }

    // currentSlot < slotToCheck, so:
    //do 4 cases of conflict
    // case 1: both Horizontal:
    if (slotData[slotToCheck][3] == 'H' && slotData[currentSlot][3] == 'H') {
        // only potential conflict in same row
        if (slotData[slotToCheck][0] == slotData[currentSlot][0]) {
            // whichever col is lower - add length and see if surpasses other

            // if ((slotData[slotToCheck][1] < slotData[currentSlot][1] &&
            //     slotData[slotToCheck][1] + slotData[slotToCheck][2] > slotData[currentSlot][1]) ||
            //     (slotData[currentSlot][1] < slotData[slotToCheck][1] &&
            //         slotData[currentSlot][1] + slotData[currentSlot][2] > slotData[slotToCheck][1])) {
            //     strcat(conflicts, (char[]){(char)(currentSlot + '0'), '\0'});
            // }

            if (slotData[slotToCheck][1] < slotData[currentSlot][1]) {
                if (slotData[slotToCheck][1] + slotData[slotToCheck][2] > slotData[currentSlot][1]) {
                    // strcat(conflicts, (char[]){(char)(currentSlot + '0')});
                    // return 1;sprintf(conflicts, "%d", currentSlot);
                    char temp[5];
                    sprintf(temp, "%d", currentSlot);
                    strcat(conflicts, temp);
                }
            } else {
                if (slotData[currentSlot][1] + slotData[currentSlot][2] > slotData[slotToCheck][1]) {
                    // strcat(conflicts, (char[]){(char)(currentSlot + '0')});
                    // return 1;
                    char temp[5];
                    sprintf(temp, "%d", currentSlot);
                    strcat(conflicts, temp);
                }
            }
        }
    }
    // case 2: both Vertical:
    else if (slotData[slotToCheck][3] == 'V' && slotData[currentSlot][3] == 'V') {
        // only potential conflict in same col
        if (slotData[slotToCheck][1] == slotData[currentSlot][1]) {
            // whichever row is lower - add length and see if surpasses other
            // if ((slotData[slotToCheck][0] < slotData[currentSlot][0] &&
            //     slotData[slotToCheck][0] + slotData[slotToCheck][2] > slotData[currentSlot][0]) ||
            //     (slotData[currentSlot][0] < slotData[slotToCheck][0] &&
            //         slotData[currentSlot][0] + slotData[currentSlot][2] > slotData[slotToCheck][0])) {
            //     strcat(conflicts, (char[]){(char)(currentSlot + '0'), '\0'});
            // }
            if (slotData[slotToCheck][0] < slotData[currentSlot][0]) {
                if (slotData[slotToCheck][0] + slotData[slotToCheck][2] > slotData[currentSlot][0]) {
                    // strcat(conflicts, (char[]){(char)(currentSlot + '0')});
                    // return 1;
                    char temp[5];
                    sprintf(temp, "%d", currentSlot);
                    strcat(conflicts, temp);
                }
            } else {
                if (slotData[currentSlot][0] + slotData[currentSlot][2] > slotData[slotToCheck][0]) {
                    // strcat(conflicts, (char[]){(char)(currentSlot + '0')});
                    char temp[5];
                    sprintf(temp, "%d", currentSlot);
                    strcat(conflicts, temp);
                    // return 1;
                }
            }
        }
    }
    // case 3: toCheck vertical, current horizontal:
    else if (slotData[slotToCheck][3] == 'V' && slotData[currentSlot][3] == 'H') {
        // potential conflict if toCheck row is between current row and current row + length
        // if (slotData[slotToCheck][0] >= slotData[currentSlot][0] &&
        //     slotData[slotToCheck][0] < slotData[currentSlot][0] + slotData[currentSlot][2] &&
        //     slotData[currentSlot][1] >= slotData[slotToCheck][1] &&
        //     slotData[currentSlot][1] < slotData[slotToCheck][1] + slotData[slotToCheck][2]) {
        //     strcat(conflicts, (char[]){(char)(currentSlot + '0'), '\0'});
        // }
        if (slotData[slotToCheck][0] <= slotData[currentSlot][0] &&
            slotData[slotToCheck][0] + slotData[slotToCheck][2] >= slotData[currentSlot][0]) {
            // slotData[slotToCheck][0] >= slotData[currentSlot][0] - slotData[currentSlot][2]) {            // slotData[slotToCheck][0] <= slotData[currentSlot][0] + slotData[currentSlot][2]) {
            // conflict if current col is between toCheck col and toCheck col + length
            if (slotData[currentSlot][1] <= slotData[slotToCheck][1] &&
                slotData[currentSlot][1] + slotData[currentSlot][2] >= slotData[slotToCheck][1]) {
                // strcat(conflicts, (char[]){(char)(currentSlot)});
                char temp[5];
                sprintf(temp, "%d", currentSlot);
                strcat(conflicts, temp);
                // char currSlotToAdd = (char)(currentSlot) + '0';
                // strcat(conflicts, &currSlotToAdd);
                // return 1;
            }
        }
    }
    // case 4: current vertical, toCheck horizontal:
    else if (slotData[currentSlot][3] == 'V' && slotData[slotToCheck][3] == 'H') {
        // potential conflict if toCheck row is between current row and current row + length
        // if (slotData[currentSlot][0] >= slotData[slotToCheck][0] &&
        //     slotData[currentSlot][0] < slotData[slotToCheck][0] + slotData[slotToCheck][2] &&
        //     slotData[slotToCheck][1] >= slotData[currentSlot][1] &&
        //     slotData[slotToCheck][1] < slotData[currentSlot][1] + slotData[currentSlot][2]) {
        //     strcat(conflicts, (char[]){(char)(currentSlot + '0'), '\0'});
        // }
        if (slotData[currentSlot][0] <= slotData[slotToCheck][0] &&
            slotData[currentSlot][0] + slotData[currentSlot][2] >= slotData[slotToCheck][0]) {
            // slotData[currentSlot][0] <= slotData[slotToCheck][0] + slotData[slotToCheck][2]) {
            // conflict if current col is between toCheck col and toCheck col + length
            if (slotData[slotToCheck][1] <= slotData[currentSlot][1] &&
                slotData[slotToCheck][1] + slotData[slotToCheck][2] >= slotData[currentSlot][1]) {
                // strcat(conflicts, (char[]){(char)(currentSlot)});
                char temp[5];
                sprintf(temp, "%d", currentSlot);
                strcat(conflicts, temp);
                // char currSlotToAdd = (char)(currentSlot) + '0';
                // strcat(conflicts, &currSlotToAdd);
                // return 1;
                }
            }
    }



    // check for all conflicts - next slot
    return checkConflict(indexesUsed, slotData, conflicts, wordIndex, slotToCheck, currentSlot+1);




    // 4 case: both vertical or both horizontal - check if overlap based on index and length
    // OR: they are opposites vert and horizontal - also check if overlap based on index and length - but slightly more calculation

}


int findWordRightSize(char words[CROSSWORD_MAX_WORDS][CROSSWORD_MAX_WORD_LENGTH], int indexesUsed[CROSSWORD_MAX_WORDS],
                        int numWords, int length, int wordUpTo) {
    if (wordUpTo >= numWords) {
        return -1;
    }
    int len = (int)strlen(words[wordUpTo]);

    if (indexesUsed[wordUpTo] == 1) {
        return findWordRightSize(words, indexesUsed, numWords, length, wordUpTo + 1);
    }

    if (len == length) {
        return wordUpTo;
    }

    // if (indexesUsed[wordUpTo] == 0 && len == length) {
    //     return wordUpTo;
    // }
    return findWordRightSize(words, indexesUsed, numWords, length, wordUpTo + 1);

    // if (wordUpTo == numWords) {
    //     return -1;
    // }
    // if (indexesUsed[wordUpTo] == 1) {
    //     return findWordRightSize(words, indexesUsed, numWords, length, wordUpTo+1);
    // }
    // // char currentWord[CROSSWORD_MAX_WORD_LENGTH] = "";
    // // strcpy(currentWord, words[wordUpTo]);// int stringLength = strlen(words[wordUpTo]);
    // if ((int)(strlen(words[wordUpTo])) == length) {
    //     return wordUpTo;
    // }
    // return findWordRightSize(words, indexesUsed, numWords, length, wordUpTo+1);

}

int compareConflictLetters(char conflicts[CROSSWORD_MAX_SLOTS], char slotData[CROSSWORD_MAX_SLOTS][CROSSWORD_SLOT_DATA],
                            int wordAtSlot[CROSSWORD_MAX_SLOTS], int conflictIndex, int slotUpTo,
                            int wordForNewSlot,
                            char words[CROSSWORD_MAX_WORDS][CROSSWORD_MAX_WORD_LENGTH]) {
    if (conflictIndex == strlen(conflicts)) {
        return 0;
    }

    // find cell of overlap
    int overlapRow, overlapCol;
    int confSlotIndex = conflicts[conflictIndex] - '0';
    // if not same direction:
    if (slotData[slotUpTo][3] != slotData[confSlotIndex][3]) {
        // overlap cell is at col of vertical and row of horizontal
        if (slotData[slotUpTo][3] == 'V') {
            overlapRow = slotData[confSlotIndex][0] - '0';
            overlapCol = slotData[slotUpTo][1] - '0';
        } else {
            overlapRow = slotData[slotUpTo][0] - '0';
            overlapCol = slotData[confSlotIndex][1] - '0';
        }
    }
    // if same direction:
    else {
        if (slotData[slotUpTo][3] == 'V') {
            // if vertical: overlap is first cell of lower down / aka greater row
            if (slotData[slotUpTo][0] > slotData[confSlotIndex][0]) {
                overlapRow = slotData[slotUpTo][0] - '0';
                overlapCol = slotData[slotUpTo][1] - '0';
            } else {
                overlapRow = slotData[confSlotIndex][0] - '0';
                overlapCol = slotData[confSlotIndex][1] - '0';
            }
        } else {
            // horizontal: overlap is first cell of further right / aka greater col
            if (slotData[slotUpTo][1] > slotData[confSlotIndex][1]) {
                overlapRow = slotData[slotUpTo][0] - '0';
                overlapCol = slotData[slotUpTo][1] - '0';
            } else {
                overlapRow = slotData[confSlotIndex][0] - '0';
                overlapCol = slotData[confSlotIndex][1] - '0';
            }
        }
    }

    // based on that cells index - get the letter of the word for that cell at that index
    int confSlotWordIndex;
    if (slotData[confSlotIndex][3] == 'H') {
        confSlotWordIndex = overlapCol - slotData[confSlotIndex][1];
    } else {
        confSlotWordIndex = overlapRow - slotData[confSlotIndex][0];
    }
    char confLetter = words[wordAtSlot[confSlotIndex]][confSlotWordIndex];

    // comp that to the index of our word at the relevant index
    int currentSlotWordIndex;
    if (slotData[slotUpTo][3] == 'H') {
        currentSlotWordIndex = overlapCol - slotData[slotUpTo][1];
    } else {
        currentSlotWordIndex = overlapRow - slotData[slotUpTo][0];
    }
    char currentLetter = words[wordForNewSlot][currentSlotWordIndex];
    // if conflict - return 1
    if (confLetter != currentLetter) {
        return 1;
    }
    // otherwise return recursive of conflictIndex + 1
    return compareConflictLetters(conflicts, slotData, wordAtSlot, conflictIndex+1, slotUpTo, wordForNewSlot, words);

}

int task5CrosswordGenerator(char crossWord[CROSSWORD_MAX_GRID][CROSSWORD_MAX_GRID],
                            char words[CROSSWORD_MAX_WORDS][CROSSWORD_MAX_WORD_LENGTH],
                            char slotData[CROSSWORD_MAX_SLOTS][CROSSWORD_SLOT_DATA],
                            int indexesUsed[CROSSWORD_MAX_WORDS],
                            int wordAtSlot[CROSSWORD_MAX_SLOTS],
                            int gridSize, int numSlots, int numWords, int slotUpTo, int wordUpTo) {


    int stillWords = 1;

    int wordIndex = findWordRightSize(words, indexesUsed, numWords, slotData[slotUpTo][2] - '0', wordUpTo);

    if (wordIndex == -1) {
        return 0;
    }

    // TODO - couldn't get conflict checking to work properly
    //make empty conflicts, then check if still empty after checking all conflicts
    // char conflicts[CROSSWORD_MAX_SLOTS] = "";
    // strcpy(conflicts, "");
    // checkConflict(indexesUsed, slotData, conflicts, wordIndex, slotUpTo, 0);
    // if (conflicts[0] != '\0') {
    //     if (compareConflictLetters(conflicts, slotData, wordAtSlot, 0, slotUpTo, wordIndex, words) == 1) {
    //         return 0;
    //     }
    // }

    indexesUsed[wordIndex] = 1;
    wordAtSlot[slotUpTo] = wordIndex;

    if (slotUpTo == numSlots - 1) {
        // if (
        putWordInGrid(crossWord, slotData[slotUpTo][0] - '0', slotData[slotUpTo][1] - '0',
            slotData[slotUpTo][2] - '0', slotData[slotUpTo][3], words[wordIndex]);
        // == 1) {
        return 1;
        // }
        // putSlotsInGrid(crossWord, slotData[slotUpTo][0] - '0', slotData[slotUpTo][1] - '0',
                // slotData[slotUpTo][2] - '0', slotData[slotUpTo][3]);
        // return 0;
    }

    while (stillWords) {
        // If call on next slot false - try next word that has enough letters
        if (task5CrosswordGenerator(crossWord, words, slotData, indexesUsed, wordAtSlot, gridSize, numSlots, numWords, slotUpTo+1, 0) == 0) {
            indexesUsed[wordIndex] = 0;
            wordAtSlot[slotUpTo] = -1;

            wordIndex = findWordRightSize(words, indexesUsed, numWords, slotData[slotUpTo][2] - '0', wordIndex+1);
            if (wordIndex == -1) {
                return 0;
            }

            //make empty conflicts, then check if still empty after checking all conflicts
            // char conflicts[CROSSWORD_MAX_SLOTS] = "";
            // strcpy(conflicts, "");
            // checkConflict(indexesUsed, slotData, conflicts, wordIndex, slotUpTo, 0);
            // if (conflicts[0] != '\0') {
            //     if (compareConflictLetters(conflicts, slotData, wordAtSlot, 0, slotUpTo, wordIndex, words) == 1) {
            //         return 0;
            //     }
            // }


            indexesUsed[wordIndex] = 1;
            wordAtSlot[slotUpTo] = wordIndex;
        } else {
            // if (
            putWordInGrid(crossWord, slotData[slotUpTo][0] - '0', slotData[slotUpTo][1] - '0',
                slotData[slotUpTo][2] - '0', slotData[slotUpTo][3], words[wordIndex]);
            // == 1) {
                return 1;
            // }
            // putSlotsInGrid(crossWord, slotData[slotUpTo][0] - '0', slotData[slotUpTo][1] - '0',
                // slotData[slotUpTo][2] - '0', slotData[slotUpTo][3]);
            // indexesUsed[wordIndex] = 0;
            // task5CrosswordGenerator(crossWord, words, slotData, indexesUsed, gridSize, numSlots, numWords, slotUpTo, wordIndex+1);
        }
    }

}