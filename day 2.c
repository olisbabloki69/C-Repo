#include <stdio.h>

int main() {

    // ===== 1. Variablat =====
    int age = 20;
    float height = 1.75;
    double salary = 1234.56;
    char grade = 'A';

    printf("=== Variables ===\n");
    printf("Age: %d\n", age);
    printf("Height: %f\n", height);
    printf("Salary: %f\n", salary);
    printf("Grade: %c\n\n", grade);


    // ===== 2. Input / Output =====
    int userAge;
    float userHeight;

    printf("Enter your age: ");
    scanf("%d", &userAge);

    printf("Enter your height: ");
    scanf("%f", &userHeight);

    printf("You are %d years old and %.2f meters tall\n\n", userAge, userHeight);


    // ===== 3. if / else =====
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number > 0) {
        printf("Positive\n");
    } else if (number < 0) {
        printf("Negative\n");
    } else {
        printf("Zero\n");
    }


    // ===== 4. switch =====
    int day;

    printf("\nEnter a number (1-3): ");
    scanf("%d", &day);

    switch(day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        default:
            printf("Invalid input\n");
    }


    // ===== 5. Mini Challenge =====
    int score;

    printf("\nEnter your score: ");
    scanf("%d", &score);

    if (score > 90) {
        printf("Excellent\n");
    } else if (score > 70) {
        printf("Good\n");
    } else if (score > 50) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }

    return 0;
}