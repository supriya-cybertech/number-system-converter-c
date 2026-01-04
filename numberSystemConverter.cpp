#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to its numeric value
int charToValue(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else
        return -1; // Invalid character
}

// Function to convert a numeric value to character
char valueToChar(int val) {
    if (val >= 0 && val <= 9)
        return '0' + val;
    else
        return 'A' + (val - 10);
}

// Function to convert any base number to decimal
long long toDecimal(char num[], int base) {
    long long result = 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        int val = charToValue(num[i]);
        if (val < 0 || val >= base) {
            printf("Invalid digit '%c' for base %d\n", num[i], base);
            return -1;
        }
        result = result * base + val;
    }
    return result;
}

// Function to convert decimal to any base
void fromDecimal(long long num, int base, char result[]) {
    char temp[65]; // Enough for 64-bit number in base 2
    int i = 0;
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    while (num > 0) {
        temp[i++] = valueToChar(num % base);
        num /= base;
    }
    // Reverse the string
    int j;
    for (j = 0; j < i; j++)
        result[j] = temp[i - j - 1];
    result[j] = '\0';
}

int main() {
    char num[65];
    int baseInput, baseOutput;
    
    // Input
    printf("Enter the number: ");
    scanf("%s", num);
    printf("Enter base of input number (2-36): ");
    scanf("%d", &baseInput);
    printf("Enter base of output number (2-36): ");
    scanf("%d", &baseOutput);
    
    if (baseInput < 2 || baseInput > 36 || baseOutput < 2 || baseOutput > 36) {
        printf("Bases must be between 2 and 36.\n");
        return 1;
    }

    // Convert to decimal
    long long decimal = toDecimal(num, baseInput);
    if (decimal == -1)
        return 1; // Invalid digit

    // Convert from decimal to target base
    char output[65];
    fromDecimal(decimal, baseOutput, output);

    printf("Number %s in base %d is %s in base %d\n", num, baseInput, output, baseOutput);

    return 0;
}

