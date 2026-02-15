#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    int identity = 1;
    for (int i = 0; i < n && identity; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                if (a[i][j] != 1) {
                    identity = 0;
                    break;
                }
            } else {
                if (a[i][j] != 0) {
                    identity = 0;
                    break;
                }
            }
        }
    }

    if (identity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
