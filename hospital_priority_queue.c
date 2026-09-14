#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[50];
    int priority;
};

struct Patient queue[MAX];
int count = 0;

void addPatient() {
    if (count == MAX) {
        printf("Queue is full!\n");
        return;
    }

    printf("Enter patient name: ");
    scanf("%s", queue[count].name);

    printf("Enter priority (1=Emergency, 2=Urgent, 3=Routine): ");
    scanf("%d", &queue[count].priority);

    count++;

    printf("Patient added successfully.\n");
}

void treatNextPatient() {
    int i, highest;
    struct Patient temp;

    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }

    highest = 0;

    for (i = 1; i < count; i++) {
        if (queue[i].priority < queue[highest].priority) {
            highest = i;
        }
    }

    printf("Patient treated: %s\n", queue[highest].name);
    printf("Priority: %d\n", queue[highest].priority);

    for (i = highest; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;
}

int main() {
    int choice;

    do {
        printf("\n===== Hospital Patient Priority Queue =====\n");
        printf("1. Add Patient\n");
        printf("2. Treat Next Patient\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                treatNextPatient();
                break;

            case 3:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
