#include <stdio.h>

int main() {
    int a;
    double b;

    // Pointerat
    int *pA;
    double *pB;

    // Input
    printf("Shkruaj nje vlere integer: ");
    scanf("%d", &a);

    printf("Shkruaj nje vlere double: ");
    scanf("%lf", &b);

    // Lidhja e pointerave me adresat
    pA = &a;
    pB = &b;

    // Shfaqja fillestare
    printf("\n--- VLERA FILLESTARE ---\n");
    printf("a (direkt): %d\n", a);
    printf("Adresa e a: %p\n", &a);
    printf("a permes pointer (*pA): %d\n", *pA);

    printf("\nb (direkt): %.2lf\n", b);
    printf("Adresa e b: %p\n", &b);
    printf("b permes pointer (*pB): %.2lf\n", *pB);

    // Ruajmë vlerat fillestare për krahasim
    int oldA = a;
    double oldB = b;

    // Ndryshimi përmes pointerave
    *pA = *pA + 10;
    *pB = *pB * 2;

    // Shfaqja pas ndryshimit
    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a (i ri): %d\n", a);
    printf("b (i ri): %.2lf\n", b);

    // Kontrolli me if/else për a
    printf("\n--- ANALIZA PER a ---\n");
    if (a > oldA) {
        printf("Vlera e a eshte rritur.\n");
    } else if (a < oldA) {
        printf("Vlera e a eshte zvogeluar.\n");
    } else {
        printf("Vlera e a ka mbetur e njejte.\n");
    }

    // Kontroll intervali për b
    printf("\n--- ANALIZA PER b ---\n");
    if (b >= 0 && b <= 100) {
        printf("b eshte brenda intervalit [0, 100].\n");
    } else {
        printf("b eshte jashte intervalit [0, 100].\n");
    }

    return 0;
}