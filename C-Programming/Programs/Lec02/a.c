#include <stdio.h>


int main() {
    int a[2][3][2];
    int count = 0;
    for ( int i = 0; i <= 2; i++ ) {
        for ( int j = 0; j <= 3; j++ ) {
            for ( int k = 0; k <= 2; k++ ) {
                a[i][j][k] = count++;
            }
        }
    }
    for ( int i = 0; i <= 2; i++ ) {
        for ( int j = 0; j <= 3; j++ ) {
            for ( int k = 0; k <= 2; k++ ) {
                printf("%d", a[i][j][k]);
            }
        }
    }
    return 0;
}