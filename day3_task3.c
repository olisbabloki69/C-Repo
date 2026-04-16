#include <stdio.h>

int main() {
    int start, end;

    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5Not3 = 0, sumDiv5Not3 = 0;

    // Marrja e input-it
    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete <= fundi.\n");
        return 1;
    }

    // Loop per analizimin e intervalit
    for (int i = start; i <= end; i++) {

        // Numrat qe pjestohet me 3
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        }
        // Numrat qe pjestohet me 5 por JO me 3
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    // Output
    printf("\n--- Rezultati ---\n");
    printf("Intervali: [%d, %d]\n", start, end);

    printf("\nPjestohen me 3:\n");
    printf("Numeruesi: %d | Shuma: %d\n", countDiv3, sumDiv3);

    printf("\nPjestohen me 5 por jo me 3:\n");
    printf("Numeruesi: %d | Shuma: %d\n", countDiv5Not3, sumDiv5Not3);

    // Krahasimi i shumave
    printf("\n--- Krahasimi i shumave ---\n");
    if (sumDiv3 > sumDiv5Not3) {
        printf("Shuma e numrave qe pjestohen me 3 eshte me e madhe.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("Shuma e numrave qe pjestohen me 5 (jo me 3) eshte me e madhe.\n");
    } else {
        printf("Te dy shumat jane te barabarta.\n");
    }

    return 0;
}