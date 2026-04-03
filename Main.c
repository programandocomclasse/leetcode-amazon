#include <stdio.h>
#include <stdlib.h>

int main() {
    int x[2][4] = {{1,0,0,1},{0,1,1,0}};
    int rows = 2, cols = 4;
    int ok = 1;

    int nRobos = 0;
    for (int j = 0; j < cols; j++)
        if (x[0][j] == 1) nRobos++;

    for (int i = 0; i < rows && ok; i++) {
        int count = 0;
        for (int j = 0; j < cols; j++)
            if (x[i][j] == 1) count++;

        if (count != nRobos) { ok = 0; break; }
        if (i == 0) continue;

        int prev[4], curr[4], pi = 0, ci = 0;
        for (int j = 0; j < cols; j++) {
            if (x[i-1][j] == 1) prev[pi++] = j;
            if (x[i][j]   == 1) curr[ci++] = j;
        }
        for (int h = 0; h < ci; h++) {
            int d = prev[h] - curr[h];
            if (d < -1 || d > 1) { ok = 0; break; }
        }
    }
    printf(ok ? "true\n" : "false\n");
    return 0;
}