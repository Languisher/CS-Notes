#include <stdio.h>
#include <assert.h>
#include <math.h>

int main() {
    int max_num; // 范围
    int num2judge; // 被检验是否是素数的数
    int div; // 被除数
    int is_prime; // 是素数旗帜

    // Receive the input 
    printf("Input the range: (Integer > 1) ");
    scanf("%d", &max_num); 
    assert ( max_num > 1 );

    // Create the list of primes, initialisation
    int prime_list[max_num]; // 素数列表
    for ( int index = 0; index < max_num; index++ ) {
        prime_list[index] = 0;
    }

    prime_list[0] = 2;
    int * prime_pos = prime_list; // Pointers to the prime_list

    // Operation for each nubmer in the range; 
    for( num2judge = 3; num2judge <= max_num; num2judge++ ) {
        /* Initialisation */
        is_prime = 1; 

        // Try for each div 
        for ( int * prime_list_search = prime_list; 
              prime_list_search <= prime_pos &&
              *prime_list_search <= (int)(sqrt(max_num)); // 2 judgements
              prime_list_search++ ) {
                if ( num2judge % *prime_list_search == 0 ) {
                    is_prime = 0;
                    break;
                }
              }

        if( is_prime ) {
            *++prime_pos = num2judge;
        }
    }

    // Print the prime list
    printf("The list of primes: ");
    for ( int * prime_list_search = prime_list; 
          prime_list_search <= prime_pos;
          prime_list_search++ ) {
            printf("%d ", *prime_list_search);
          }

    return 0;
}