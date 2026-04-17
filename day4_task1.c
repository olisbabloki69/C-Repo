#include <stdio.h>

// ENUM për statusin
enum Status {
    FILLUAR = 1,
    NE_PROGRES,
    PERFUNDUAR
};

// STRUCT për regjistrim
struct Progress {
    char name[50];
    int score;
    enum Status status;
};

// Funksion për të printuar statusin
void printStatus(enum Status s) {
    switch (s) {
        case FILLUAR: printf("Filluar"); break;
        case NE_PROGRES: printf("Ne progres"); break;
        case PERFUNDUAR: printf("Perfunduar"); break;
        default: printf("I panjohur");
    }
}

// Funksion për raport
void printReport(struct Progress records[], int count) {

    if (count == 0) {
        printf("\nNuk ka te dhena per raport.\n");
        return;
    }

    int total = count;
    int completed = 0;
    int sum = 0;
    int max = records[0].score;
    int min = records[0].score;

    for (int i = 0; i < count; i++) {

        sum += records[i].score;

        if (records[i].status == PERFUNDUAR) {
            completed++;
        }

        if (records[i].score > max) {
            max = records[i].score;
        }

        if (records[i].score < min) {
            min = records[i].score;
        }
    }

    float avg = (float)sum / total;

    printf("\n===== RAPORT =====\n");
    printf("Total regjistrime: %d\n", total);
    printf("Te perfunduara: %d\n", completed);
    printf("Mesatarja e pikeve: %.2f\n", avg);
    printf("Max: %d | Min: %d\n", max, min);

    // Klasifikim me if/else
    if (avg >= 80) {
        printf("Vleresim: Shume mire\n");
    } else if (avg >= 50) {
        printf("Vleresim: Mesatar\n");
    } else {
        printf("Vleresim: Duhet permiresim\n");
    }

    if (completed == total) {
        printf("Status global: Te gjitha te perfunduara\n");
    } else if (completed > 0) {
        printf("Status global: Ne progres\n");
    } else {
        printf("Status global: Asgje e perfunduar\n");
    }
}

int main() {

    struct Progress records[5]; // kapacitet maksimal
    int count = 0;
    int choice;

    while (1) {

        printf("\n1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha\n");
        printf("3. Raport\n");
        printf("4. Dil\n");
        printf("Zgjedhja: ");

        // Validim input menu
        if (scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {

            case 1: {
                if (count >= 5) {
                    printf("Kapaciteti maksimal u arrit!\n");
                    break;
                }

                printf("Shkruaj emrin: ");
                scanf("%s", records[count].name);

                printf("Shkruaj piket: ");
                scanf("%d", &records[count].score);

                int statusInput;
                printf("Zgjidh statusin:\n");
                printf("1. Filluar\n2. Ne progres\n3. Perfunduar\n");
                printf("Zgjedhja: ");

                // Validim statusi
                if (scanf("%d", &statusInput) != 1 ||
                    statusInput < 1 || statusInput > 3) {
                    printf("Status i pavlefshem!\n");
                    while (getchar() != '\n');
                    break;
                }

                records[count].status = (enum Status)statusInput;
                count++;

                printf("Regjistrimi u shtua me sukses!\n");
                break;
            }

            case 2: {
                if (count == 0) {
                    printf("Nuk ka regjistrime.\n");
                    break;
                }

                printf("\n--- Lista e regjistrimeve ---\n");
                for (int i = 0; i < count; i++) {
                    printf("Emri: %s, Piket: %d, Status: ",
                           records[i].name,
                           records[i].score);
                    printStatus(records[i].status);
                    printf("\n");
                }
                break;
            }

            case 3:
                printReport(records, count);
                break;

            case 4:
                printf("Programi u mbyll.\n");
                return 0;

            default:
                printf("Zgjedhje e pavlefshme! Provo perseri.\n");
        }
    }

    return 0;
}