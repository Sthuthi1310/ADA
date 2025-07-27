#include <stdio.h>
#include <stdlib.h>

int count = 0;

// Euclid's Algorithm
int Euclid_gcd(int a, int b)
{
    count = 0;
    while (b != 0)
    {
        count++;
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

// Consecutive Integer Checking
int consecutive_integer(int a, int b)
{
    count = 0;
    int gcd = 1;
    int min = (a < b) ? a : b;
    while (min != 0)
    {
        count++;
        if (a % min == 0 && b % min == 0)
        {
            gcd = min;
            break;
        }
        min--;
    }
    return gcd;
}

// Modified Euclid's Algorithm
int modified_euclids(int a, int b)
{
    count = 0;
    while (a != b)
    {
        count++;
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

// Tester for manual input
void tester()
{
    int a, b;
    int count1, count2, count3;

    printf("Enter the value of a:\n");
    scanf("%d", &a);
    printf("Enter the value of b:\n");
    scanf("%d", &b);

    int gcd1 = Euclid_gcd(a, b);
    count1 = count;

    int gcd2 = consecutive_integer(a, b);
    count2 = count;

    int gcd3 = modified_euclids(a, b);
    count3 = count;

    printf("GCD using Euclid's method: %d (Steps: %d)\n", gcd1, count1);
    printf("GCD using Consecutive Integer method: %d (Steps: %d)\n", gcd2, count2);
    printf("GCD using Modified Euclid's method: %d (Steps: %d)\n", gcd3, count3);
}

// Plotter for best/average/worst case recording
void plotter()
{
    int a, b;
    int count1, count2, count3;

    FILE *fp1 = fopen("BestCase_gcd.txt", "w");
    FILE *fp2 = fopen("AverageCase_gcd.txt", "w");
    FILE *fp3 = fopen("WorstCase_gcd.txt", "w");

    // Best case inputs
    printf("Enter the inputs for the best case:\n");
    for (int k = 1; k < 10; k++)
    {
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);

        Euclid_gcd(a, b);
        count1 = count;

        modified_euclids(a, b);
        count2 = count;

        consecutive_integer(a, b);
        count3 = count;

        fprintf(fp1, "%d %d %d %d\n", k, count1, count2, count3);
    }

    // Average case inputs
    printf("Enter the inputs for the average case:\n");
    for (int k = 1; k < 10; k++)
    {
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);

        Euclid_gcd(a, b);
        count1 = count;

        modified_euclids(a, b);
        count2 = count;

        consecutive_integer(a, b);
        count3 = count;

        fprintf(fp2, "%d %d %d %d\n", k, count1, count2, count3);
    }

    // Worst case inputs
    printf("Enter the inputs for the worst case:\n");
    for (int k = 1; k < 10; k++)
    {
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);

        Euclid_gcd(a, b);
        count1 = count;

        modified_euclids(a, b);
        count2 = count;

        consecutive_integer(a, b);
        count3 = count;

        fprintf(fp3, "%d %d %d %d\n", k, count1, count2, count3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int main()
{
    int ch;

    printf("\n1. Tester\n2. Plotter\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        tester();
        break;

    case 2:
        plotter();
        break;

    default:
        printf("Invalid choice!!\n");
    }

    return 0;
}