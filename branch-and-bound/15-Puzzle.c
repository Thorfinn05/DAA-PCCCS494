#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int calculate_heuristic(int puzzle[MAX][MAX], int goal[MAX][MAX], int n) {
    int heuristic = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (puzzle[i][j] != 0) {
                int value = puzzle[i][j];
                int goal_x = (value - 1) / n;    
                int goal_y = (value - 1) % n;    
                heuristic += abs(i - goal_x) + abs(j - goal_y); // Manhattan distance
            }
        }
    }
    return heuristic;
}

int is_goal(int puzzle[MAX][MAX], int goal[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (puzzle[i][j] != goal[i][j]) {
                return 0;  
            }
        }
    }
    return 1;  // Goal state reached
}

void find_blank(int puzzle[MAX][MAX], int n, int *x, int *y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (puzzle[i][j] == 0) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void solve(int puzzle[MAX][MAX], int goal[MAX][MAX], int n, int depth, int *min_cost) {
    int h = calculate_heuristic(puzzle, goal, n); 
    int cost = depth + h; 

    // If cost exceeds current minimum, prune this branch
    if (cost >= *min_cost) {
        return;
    }

    if (is_goal(puzzle, goal, n)) {
        *min_cost = depth;
        return;
    }

    int x, y;
    find_blank(puzzle, n, &x, &y);

    // Up
    if (x > 0) {
        swap(&puzzle[x][y], &puzzle[x - 1][y]);
        solve(puzzle, goal, n, depth + 1, min_cost);
        swap(&puzzle[x][y], &puzzle[x - 1][y]); // Undo move
    }
    // Down
    if (x < n - 1) {
        swap(&puzzle[x][y], &puzzle[x + 1][y]);
        solve(puzzle, goal, n, depth + 1, min_cost);
        swap(&puzzle[x][y], &puzzle[x + 1][y]); // Undo move
    }
    // Left
    if (y > 0) {
        swap(&puzzle[x][y], &puzzle[x][y - 1]);
        solve(puzzle, goal, n, depth + 1, min_cost);
        swap(&puzzle[x][y], &puzzle[x][y - 1]); // Undo move
    }
    // Right
    if (y < n - 1) {
        swap(&puzzle[x][y], &puzzle[x][y + 1]);
        solve(puzzle, goal, n, depth + 1, min_cost);
        swap(&puzzle[x][y], &puzzle[x][y + 1]); // Undo move
    }
}

int main() {
    int puzzle[MAX][MAX], goal[MAX][MAX];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter the puzzle configuration:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k == n * n) {
                goal[i][j] = 0;  // Blank tile
            } else {
                goal[i][j] = k++;
            }
        }
    }
    printf("Goal state:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", goal[i][j]);
        }
        printf("\n");
    }
    int min_cost = 10000; 
    solve(puzzle, goal, n, 0, &min_cost);
    if (min_cost != 10000) {
        printf("Minimum moves to solve the puzzle: %d\n", min_cost);
    } else {
        printf("Puzzle is unsolvable.\n");
    }
    return 0;
}