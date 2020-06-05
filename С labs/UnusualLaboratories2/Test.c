#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
    char d;
    int z = 1, k = 3, n, n1=0;
    double sum, num1=0, num2=0;
    double* mas = (double*)malloc(k * sizeof(double));
    char* y = (char*)malloc(10 * sizeof(char));
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\TheLostLegend\\Desktop\\kek.txt", "r");
    if (fp == NULL) {
        puts("Cannot open file.");
        return 0;
    };
    char** fz = (char**)malloc(z * sizeof(char*));
    if (!fz) return 1;
    for (int i = 0; i < z; i++) {
        fz[i] = (char*)malloc(80 * sizeof(char));
    }
    for (int i = 0; i < z; i++)
    {
        fgets(fz[i], '\0', fp);
    }
    FILE* fp1;
    fopen_s(&fp1, "C:\\Users\\TheLostLegend\\Desktop\\kek1.txt", "r");
    if (fp1 == NULL) {
        puts("Cannot open file.");
        return 0;
    };
    char** fz1 = (char**)malloc(k * sizeof(char*));
    if (!fz1) return 1;
    for (int i = 0; i < k; i++) {
        fz1[i] = (char*)malloc(80 * sizeof(char));
    }
    for (int i = 0; i < k; i++)
    {
        fgets(fz1[i], '\0', fp1);
    }

    for (int i = 0; i < k; i++) {
        for(int j = 0; j<10; j++){
            y[j] = fz1[i][j + 2];
        }
        mas[i] = atof(y);
    }

    for (int i = 0; i < z; i++) {
        for (int j = 0; j < 80; j++) {
            d = fz[i][j];
            if (j % 2 == 0) {
                for (int o = 0; o < k; o++)
                    if (d == fz1[o][1]) n = o;
                if (j == 0) num1 = y[n];
                else {
                    num2 = y[n];
                    if (n1 == 1) num1 += num2;
                    if (n1 == 2) num1 -= num2;
                    if (n1 == 3) num1 *= num2;
                    if (n1 == 4) num1 /= num2;
                }
            }
            else {
                if (d == '+') n1 = 1;
                if (d == '-') n1 = 2;
                if (d == '*') n1 = 3;
                if (d == '/') n1 = 4;
            }
        }
        sum = num1;
        printf("%f", sum);
    }
    getch();

    return 0;
}