#include <stdio.h>
#include <string.h>
#include <math.h>

int str_len(char *text) {
    int i;
    for (i = 0; text[i] != '\0'; i++);
    return i;
}

int str_toint(int argc, char *argv[]) {
    int len = str_len(argv[1]);
    int sum = 0;
    int counter = 0;

    for (int i = 0; i < len; i++) {
        int num = argv[1][i] - '0';
        sum += num * (int)pow(10, len - counter - 1);
        counter++;
    }

    return sum;
}

int calculator(int argc, char *argv[], char operator) {
    if (argc != 4) {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return 1;
    }

    int number1 = str_toint(argc, argv);
    int number2 = str_toint(argc, argv + 2);
    float result = 0;

    switch (operator) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            result = (float)number1 / number2;
            break;
        default:
            printf("Invalid operator: %c\n", operator);
            return 1;
    }

    printf("Result: %.2f\n", result);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return 1;
    }
    
    char operator = argv[2][0];

    calculator(argc, argv, operator);

    return 0;
}

// gcc calculator.c -o calculator.o -lm