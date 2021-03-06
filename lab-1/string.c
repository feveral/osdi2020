#include "string.h"
#include "uart.h"

void strInvert(char *str) {
    int size = strlen(str);
    char buffer[size];
    for (int i = 0; i < size; i++) {
        buffer[i] = str[size-i-1];
    }
    for (int i = 0; i < size; i++) {
        str[i] = buffer[i];
    }
}

int strlen(char *str){
    int len = 0;
    while(str[len] != '\0') len ++;
    return len;
}

int strEqual(char *str1, char *str2)
{
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    int length = (str1len > str2len) ? str1len : str2len;
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) return 0;
    }
    return 1;
}

void intToStr(int num, char *str) {
    int index = 0;
    while(num > 0) {
        str[index++] = (num % 10) + 48;
        num /= 10;
    }
    if (num == 0 && index ==0) str[index++] = '0';
    str[index] = '\0';
    strInvert(str);
}

void doubleToStr(double num, char *str) {
    int intPart = (int)num;
    char intPartStr[128] = {0};
    intToStr(intPart, intPartStr);
    int intPartStrSize = strlen(intPartStr);
    for (int i = 0; i < intPartStrSize; i++) {
        str[i] = intPartStr[i];
    }
    str[intPartStrSize] = '.';
    
    char floatPartStr[128] = {0};
    double floatPart = num - (double) intPart;

    floatPart *= 100000000;
    while((int)floatPart % 10 == 0 ) floatPart /= 10;
    intToStr((int)floatPart, floatPartStr);
    int floatPartStrSize = strlen(floatPartStr);

    for (int i = intPartStrSize + 1; i < intPartStrSize + floatPartStrSize + 1; i++) {
        str[i] = floatPartStr[i - intPartStrSize - 1];
    }
    str[intPartStrSize + 1 + floatPartStrSize] = '\0';
}