#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXRANDOMVALUE 3
#define MAXPREV 500

int arr[4][4] = { 0 }, c[4], score = 0, highscore = 0, count = 0;

// Function to find the length of a number (count of digits)
int findlen(int n) {
    int len = 0;
    if (n == 0) return 1;
    while (n > 0) {
        len++;
        n /= 10;
    }
    return len;
}

// Function to print the game board
void print() {
    system("clear || cls");
    printf("\n\t\t\t=============== 2048 GAME ===============\n");
    printf("\t\t\tScore: %d\tHigh Score: %d\n", score, highscore);
    printf("\t\t\t----------------------------------------\n");
    for (int i = 0; i < 4; i++) {
        printf("\t\t\t");
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] != 0) {
                int len = findlen(arr[i][j]);
                printf("%*d%*s", (5 - len) / 2 + len, arr[i][j], (5 - len) / 2, "");
            }
            else {
                printf("     ");
            }
            printf("|");
        }
        printf("\n\t\t\t----------------------------------------\n");
    }
    printf("\tControls: W (Up), S (Down), A (Left), D (Right)\n");
    printf("\tR (Restart), P (Undo), U (Exit)\n");
    printf("\tEnter your choice: ");
}

// Function to add a random number to the board
void addrandomno() {
    srand(time(NULL));
    int i, j;
    do {
        i = rand() % 4;
        j = rand() % 4;
    } while (arr[i][j] != 0);
    arr[i][j] = (rand() % 10 < 9) ? 2 : 4;
}

// Function to shift and merge the row/column values
int shiftmerge(int* line) {
    int moved = 0;
    for (int i = 0; i < 3; i++) {
        if (line[i] == 0) {
            for (int j = i + 1; j < 4; j++) {
                if (line[j] != 0) {
                    line[i] = line[j];
                    line[j] = 0;
                    moved = 1;
                    break;
                }
            }
        }
        if (line[i] != 0 && line[i] == line[i + 1]) {
            line[i] *= 2;
            score += line[i];
            for (int j = i + 1; j < 3; j++) {
                line[j] = line[j + 1];
            }
            line[3] = 0;
            moved = 1;
        }
    }
    return moved;
}

// Function to handle moves
int move(char direction) {
    int moved = 0;
    if (direction == 'W' || direction == 'w') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                c[j] = arr[j][i];
            }
            moved |= shiftmerge(c);
            for (int j = 0; j < 4; j++) {
                arr[j][i] = c[j];
            }
        }
    }
    else if (direction == 'S' || direction == 's') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                c[j] = arr[3 - j][i];
            }
            moved |= shiftmerge(c);
            for (int j = 0; j < 4; j++) {
                arr[3 - j][i] = c[j];
            }
        }
    }
    else if (direction == 'A' || direction == 'a') {
        for (int i = 0; i < 4; i++) {
            moved |= shiftmerge(arr[i]);
        }
    }
    else if (direction == 'D' || direction == 'd') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                c[j] = arr[i][3 - j];
            }
            moved |= shiftmerge(c);
            for (int j = 0; j < 4; j++) {
                arr[i][3 - j] = c[j];
            }
        }
    }
    return moved;
}

// Function to save the high score to a file
void saveHighScore() {
    FILE* file = fopen("highscore.txt", "w");
    if (file == NULL) {
        perror("Error opening highscore.txt");
        return;
    }
    fprintf(file, "%d", highscore);
    fclose(file);
}

// Function to load the high score from a file
void loadHighScore() {
    FILE* file = fopen("highscore.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &highscore);
        fclose(file);
    }
}

// Function to reset the game
void resetgame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    score = 0;
    addrandomno();
    addrandomno();
}

// Main function
int main() {
    char choice;
    loadHighScore();
    resetgame();
    print();
    while (1) {
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer
        if (choice == 'U' || choice == 'u') {
            printf("Exiting the game.\n");
            saveHighScore();
            break;
        }
        else if (choice == 'R' || choice == 'r') {
            resetgame();
        }
        else if (move(choice)) {
            addrandomno();
        }
        else {
            printf("Invalid move!\n");
        }
        if (score > highscore) highscore = score;
        print();
    }
    return 0;
}
