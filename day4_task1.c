#include <stdio.h>
#include <string.h>

// ENUM
enum Status {
    FILLUAR = 1,
    NE_PROGRES,
    PERFUNDUAR
};

// STRUCT
struct Progress {
    int id;
    char name[50];
    int score;
    enum Status status;
};

// Print status
void printStatus(enum Status s) {
    switch (s) {
        case FILLUAR: printf("Filluar"); break;
        case NE_PROGRES: printf("Ne progres"); break;
        case PERFUNDUAR: printf("Perfunduar"); break;
        default: printf("I panjohur");
    }
}

// Analize inteligjente
void printRecommendation(struct Progress p) {
    printf(">> Analize: ");

    if (p.score < 50 && p.status != PERFUNDUAR) {
        printf("Rrezik i larte - progres i ulet dhe jo i perfunduar.\n");
    }
    else if (p.score >= 50 && p.score < 80 && p.status == NE_PROGRES) {
        printf("Ne rruge te mire - vazhdo punen.\n");
    }
    else if (p.score >= 80 && p.status == PERFUNDUAR) {
        printf("Shkelqyeshem - objektivi i arritur!\n");
    }
    else if (p.status == FILLUAR) {
        printf("Vetem i filluar - nevojitet me shume angazhim.\n");
    }
    else {
        printf("Gjendje normale.\n");
    }
}

// RAPORT
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

        if (records[i].status == PERFUNDUAR)
            completed++;

        if (records[i].score > max)
            max = records[i].score;

        if (records[i].score < min)
            min = records[i].score;
    }

    float avg = (float)sum / total;

    printf("\n===== RAPORT =====\n");
    printf("Total: %d\n", total);
    printf("Te perfunduara: %d\n", completed);
    printf("Mesatarja: %.2f\n", avg);
    printf("Max: %d | Min: %d\n", max, min);

    if (avg >= 80)
        printf("Vleresim: Shume mire\n");
    else if (avg >= 50)
        printf("Vleresim: Mesatar\n");
    else
        printf("Vleresim: Duhet permiresim\n");

    if (completed == total)
        printf("Status global: Te gjitha te perfunduara\n");
    else if (completed > 0)
        printf("Status global: Ne progres\n");
    else
        printf("Status global: Asgje e perfunduar\n");
}

// KERKIM
void searchRecords(struct Progress records[], int count) {

    if (count == 0) {
        printf("Nuk ka regjistrime.\n");
        return;
    }

    int option;
    printf("\nKerko sipas:\n1. ID\n2. Emrit\nZgjedhja: ");
    scanf("%d", &option);

    int found = 0;

    if (option == 1) {
        int id;
        printf("Shkruaj ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (records[i].id == id) {
                printf("\n--- U gjet ---\n");
                printf("ID: %d, Emri: %s, Piket: %d, Status: ",
                       records[i].id,
                       records[i].name,
                       records[i].score);
                printStatus(records[i].status);
                printf("\n");

                printRecommendation(records[i]);
                found = 1;
            }
        }

    } else if (option == 2) {

        char name[50];
        printf("Shkruaj emrin: ");
        scanf("%s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(records[i].name, name) == 0) {
                printf("\n--- U gjet ---\n");
                printf("ID: %d, Emri: %s, Piket: %d, Status: ",
                       records[i].id,
                       records[i].name,
                       records[i].score);
                printStatus(records[i].status);
                printf("\n");

                printRecommendation(records[i]);
                found = 1;
            }
        }

    } else {
        printf("Zgjedhje e pavlefshme!\n");
        return;
    }

    if (!found)
        printf("Asnje regjistrim nuk u gjet.\n");
}

// MAIN
int main() {

    struct Progress records[5];
    int count = 0;
    int choice;

    while (1) {

        printf("\n1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha\n");
        printf("3. Raport\n");
        printf("4. Kerko regjistrim\n");
        printf("5. Dil\n");
        printf("Zgjedhja: ");

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

                records[count].id = count + 1;

                printf("Shkruaj emrin: ");
                scanf("%s", records[count].name);

                printf("Shkruaj piket: ");
                scanf("%d", &records[count].score);

                int statusInput;
                printf("Zgjidh statusin:\n");
                printf("1. Filluar\n2. Ne progres\n3. Perfunduar\n");
                printf("Zgjedhja: ");

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

                printf("\n--- Lista ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d, Emri: %s, Piket: %d, Status: ",
                           records[i].id,
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
                searchRecords(records, count);
                break;

            case 5:
                printf("Programi u mbyll.\n");
                return 0;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }
    }

    return 0;
}