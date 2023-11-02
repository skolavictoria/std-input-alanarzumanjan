#include <stdio.h>
#include <string.h>
#include <math.h>
int str_len(char *text) {
    int i;
    for (i = 0; text[i] != '\0'; i++);
    return i;
}

int main(int argc, char *argv[]) {
    printf("Len = %d\n", str_len(argv[1]));

    int len = str_len(argv[1]);
    int sum = 0;
    int counter = 0;

    for (int i = 0; i < len; i++) {
        int num = argv[1][i] - '0';
        sum += num * (int)pow(10, len - counter - 1);
        counter++;
    }
    printf("Integeri = %d\n", sum);

    return 0;
}
// gcc main.c -o main.o -lm
// gcc main.c -o main.o -o
// ./main.o 12345