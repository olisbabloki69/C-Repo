#include <stdio.h>

// Krijimi i enum me 4 vlera
enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0;
    int invalidCount = 0;

    printf("=== PROGRAM ME ENUM (LEVEL) ===\n");

    // Loop për 3 testime
    for (int i = 1; i <= 3; i++) {
        printf("\nZgjedhja %d:\n", i);
        printf("1 - Beginner\n");
        printf("2 - Intermediate\n");
        printf("3 - Advanced\n");
        printf("4 - Expert\n");
        printf("Zgjedh nje numer: ");
        scanf("%d", &choice);

        // Lidhja me enum
        enum Level userLevel = choice;

        // Kontrolli me switch
        switch (userLevel) {
            case BEGINNER:
                printf("Ti je fillestar. Fillo me bazat.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Ti ke njohuri mesatare. Vazhdo ushtrimet.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Ti je avancuar. Provo projekte me te veshtira.\n");
                validCount++;
                break;

            case EXPERT:
                printf("Ti je ekspert! Mund te ndihmosh te tjeret.\n");
                validCount++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
        }
    }

    // Statistikat
    printf("\n=== STATISTIKAT ===\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje te pavlefshme: %d\n", invalidCount);

    return 0;
}