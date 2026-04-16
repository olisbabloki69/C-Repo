#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Marrja e input-it
    printf("Shkruani vleren fillestare: ");
    scanf("%d", &start);

    printf("Shkruani vleren perfundimtare: ");
    scanf("%d", &end);

    // Validimi i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    // Analiza e numrave
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int totalNumbers = evenCount + oddCount;

    // Rezultati
    printf("\n--- Rezultati ---\n");
    printf("Intervali: [%d, %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("Numra çift: %d | Shuma: %d\n", evenCount, evenSum);
    printf("Numra tek: %d | Shuma: %d\n", oddCount, oddSum);

    // Krahasimi
    if (evenCount > oddCount) {
        printf("Ka me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numrat çift dhe tek jane te barabarte ne numer.\n");
    }

    return 0;
}