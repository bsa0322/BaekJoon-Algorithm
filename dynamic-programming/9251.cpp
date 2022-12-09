#include<stdio.h>
#include<string.h>

int table[1001][1001];

int main() {
    char a[1001];
    char b[1001];
    int i, j, n, m, mx = 0;
    gets(a);
    gets(b);
    n = strlen(a);
    m = strlen(b);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] != b[j]) {
                mx = 0;
                if (i - 1 >= 0 && mx < table[i - 1][j]) mx = table[i - 1][j];
                if (j - 1 >= 0 && mx < table[i][j - 1]) mx = table[i][j - 1];
                table[i][j] = mx;
            } else {
                if (i - 1 >= 0 && j - 1 >= 0)
                    table[i][j] = table[i - 1][j - 1] + 1;
                else table[i][j] = 1;
            }
        }
    }
    printf("%d\n", table[n - 1][m - 1]);
    return 0;
}