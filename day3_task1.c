#include <stdio.h>

int main() {
    int n, choice;

    // Marrja e input-it për madhësinë
    printf("Shkruani nje numer (1 - 12): ");
    scanf("%d", &n);

    // Validimi i input-it
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem! Ju lutem vendosni numer nga 1 deri ne 12.\n");
        return 1;
    }

    // Zgjedhja e pattern-it
    printf("Zgjidhni pattern:\n");
    printf("1 - Pattern me yje (*)\n");
    printf("2 - Pattern me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Zgjedhje e pavlefshme!\n");
        return 1;
    }

    printf("\nRezultati:\n");

    // Krijimi i pattern-it
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (choice == 1) {
                printf("* ");
            } else {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}