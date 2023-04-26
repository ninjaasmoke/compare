#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000000

char *cache[MAX_N];

char *fizzbuzz(int n) {
    char *result = cache[n - 1];
    if (result != NULL) {
        return result;
    }
    if (n % 15 == 0) {
        result = "FizzBuzz";
    } else if (n % 3 == 0) {
        result = "Fizz";
    } else if (n % 5 == 0) {
        result = "Buzz";
    } else {
        char *buffer = malloc(sizeof(char) * 16);
        snprintf(buffer, 16, "%d", n);
        result = buffer;
    }
    cache[n - 1] = result;
    return result;
}

int main() {
    char *fizzBuzzNumbers[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        fizzBuzzNumbers[i] = fizzbuzz(i + 1);
    }
    // Print the sequence if desired
    // for (int i = 0; i < MAX_N; i++) {
    //     printf("%s\n", fizzBuzzNumbers[i]);
    // }
    return 0;
}
