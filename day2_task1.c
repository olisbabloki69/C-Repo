#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short numriShort = 12;
    long numriLong = 123456789;

    // Marrja e input-it nga përdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin (nje karakter): ");
    scanf(" %c", &iniciali); // hapësira para %c shmang problemin me newline

    printf("Shkruaj gjatesine (ne metra, p.sh. 1.75): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Output i organizuar
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Vlera short: %hd\n", numriShort);
    printf("Vlera long: %ld\n", numriLong);

    return 0;
}