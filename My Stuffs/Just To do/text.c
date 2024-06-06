#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define maxNumOfStuds 50
#define completeFee 5000


typedef struct
{
    bool isCompleted;
    bool paidInInstallments;
    int installments[5];
    int numOfInstallments;
} Fee;

typedef struct
{
    Fee fee;
    char name[50];
    char address[50];
    char phone[10];
    bool deleted;

} Student;

typedef struct
{
    Student student[maxNumOfStuds];
    int numOfStuds;
} Class;

void calculateInstallment(int, Class *, int);
void newStudentInformation();
int updateStudentInformation(char[]);
int searchStudent(char[]);
int deleteStudent(char[]);

/*
* The file pointer is declared globally to keep store the new student information for recovery and update
*/
FILE *fp;

/*
* The file pointer below is a temporary pointer used to delete records from the binary file
* When a record is to be deleted, 
* the info from the old pointer is rewriten to this pointer except the records where deleted = true
*/
FILE *fptr; 

int main() {

    int choice;
    char ch = 'y';

    while (ch == 'y'){
        system("cls");
        printf("\nDo you wish to\n1. Enter new information\n2. Update information\n3. Search Entry\n4. Delete student");
        enter: printf("\nEnter choice: ");
        scanf("%d", &choice);
        fgetc(stdin);

        if(choice != 1 && choice != 2 && choice != 3 && choice != 4) {
            printf("Please enter a valid choice!!\n");
            goto enter;
        }

        char name[50];

        switch (choice)
        {
        case 1:
            newStudentInformation();
            break;
        case 2:
            printf("\nEnter the name of the student you wish to update their information: ");
            fgets(name, 50, stdin);
            name[strlen(name) - 1] = '\0';
            updateStudentInformation(name);
            break;
        case 3:
            printf("\nEnter the name of the student you wish to search their information: ");
            fgets(name, 50, stdin);
            name[strlen(name) - 1] = '\0';
            searchStudent(name);
            break;
        case 4:
            printf("\nEnter the name of the student you wish to delete their information: ");
            fgets(name, 50, stdin);
            name[strlen(name) - 1] = '\0';
            deleteStudent(name);
            break;
        default:
            break;
        }

        ch = getchar();
    }


    return 0;
}

/*
 * calculateInstallment will take in:
 * - the fee given by the user, 
 * - the class structure and
 * - the particular student paying the fee, or the index of the student belonging to the class  
*/
void calculateInstallment(int paidFee, Class *class, int index) {
    int num = class->student[index].fee.numOfInstallments; // for easy access to number of installments
    int enteredFee = paidFee; // enteredFee will be used to save the exact entered fee into the installments array since the paidFee var will be incremented.
    ++class->student[index].fee.numOfInstallments;

    for(int i = 0; i < num; i++) {
        paidFee += class->student[index].fee.installments[i];
    }

    if (paidFee < completeFee){
        class->student[index].fee.isCompleted = false;
        class->student[index].fee.paidInInstallments = true;
        class->student[index].fee.installments[num] = enteredFee;
    }
    else if(paidFee == completeFee) {
        class->student[index].fee.installments[num] = enteredFee;
        class->student[index].fee.isCompleted = true;
    }
}

void newStudentInformation() {
    system("cls");

    time_t now;
    time(&now);

    Class class;
    char option = 'y';
    int i = 0, payment; // To keep track of the student
    bool correctPaymentDone = true; // Payment has to be done in correct installments.

    printf("\nYou can now start entering new student info");

    while(option == 'y') {
        printf("\nEnter name of student: ");
        fgets(class.student[i].name, 50, stdin);
        class.student[i].name[strlen(class.student[i].name) - 1] = '\0';

        printf("\nEnter phone of student: ");
        fgets(class.student[i].phone, 15, stdin);
        class.student[i].phone[strlen(class.student[i].phone) - 1] = '\0';

        printf("\nEnter Address of student: ");
        fgets(class.student[i].address, 50, stdin);
        class.student[i].address[strlen(class.student[i].address) - 1] = '\0';

        // I need to consider writing a function for this cause i'll have to use it twice.
        char response = 'y';
        do {
            correctPaymentDone = true;
            printf("\nEnter Payment: ");
            scanf("%d", &payment);
            fgetc(stdin);
            
            if(payment > completeFee) {
                printf("\nYou've entered more than the required fee!");
                printf("\nWould you like to continue with the entered amount? [y/n]: ");
                scanf("%c", &response);
                fgetc(stdin);
            }
            else if(payment != 2500 && payment != 5000) {
                printf("\n(Payment can be done in maximum two installments of 2500frs each)");
                correctPaymentDone = false; 
            }
        } while(response == 'n' || !correctPaymentDone);

        class.student[i].fee.isCompleted = true;
        class.student[i].fee.paidInInstallments = false;
        class.student[i].fee.numOfInstallments = 0;
        class.student[i].fee.installments[0] = 0;
        calculateInstallment(payment, &class, i);

        i++;

        printf("\nDo you wish to enter information for another student? [y/n]: ");
        scanf("%c", &option);
        fgetc(stdin);
        option = tolower(option);
    }

    class.numOfStuds = i;

    fp = fopen("Info.bin", "ab+");
    fwrite(&class, sizeof(class), 1, fp);
    fclose(fp);

    fp = fopen("File Info.txt", "a+");

    fprintf(fp, "\n**************************************************");
    fprintf(fp, "\n**************************************************\n");
    fprintf(fp, "=====Information on %s=====\n", ctime(&now));
    for(int j = 0; j < class.numOfStuds; j++) {
        fprintf(fp, "\nStudent: %s", class.student[j].name);
        fprintf(fp, "\nPhone: %s", class.student[j].phone);
        fprintf(fp, "\nAddress: %s", class.student[j].address);
        if(class.student[j].fee.isCompleted) {
            fprintf(fp, "\nFee is paid in full!");
        }
        else if(!class.student[j].fee.isCompleted) {
            fprintf(fp, "\nFee has not been paid in full!");
            
            int totalFeePaid = 0;
            for(int k = 0; k < class.student[j].fee.numOfInstallments; k++) {
                totalFeePaid += class.student[j].fee.installments[k];
            }
            fprintf(fp, "\nTotal fee paid: %d", totalFeePaid);
            fprintf(fp, "\nNumber of installments paid in: %d", class.student[j].fee.numOfInstallments);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

}

int updateStudentInformation(char name[]) {

    system("cls");

    time_t now;
    time(&now);

    Class class;
    bool studentFound = false;
    char option = 'y';
    int i, payment; // To keep track of the student;
    bool correctPaymentDone = true; // Payment has to be done in correct installments.
    printf("\nUpdate student info\n");

    fp = fopen("Info.bin", "rb");

    while (fread(&class, sizeof(class), 1, fp)) {
        for(i = 0; i < class.numOfStuds; i++) {
            if(!strcmp(class.student[i].name, name)) {
                printf("\nEnter new student name: ");
                fgets(class.student[i].name, 50, stdin);
                class.student[i].name[strlen(class.student[i].name) - 1] = '\0';
                printf("\nEnter new student phone: ");
                fgets(class.student[i].phone, 15, stdin);
                class.student[i].phone[strlen(class.student[i].phone) - 1] = '\0';
                printf("\nEnter new student Address: ");
                fgets(class.student[i].address, 50, stdin);
                class.student[i].address[strlen(class.student[i].address) - 1] = '\0';

                // I need to consider writing a function for this cause i'll have to use it twice.
                char response = 'y';
                do {
                    correctPaymentDone = true;
                    printf("\nEnter Payment: ");
                    scanf("%d", &payment);
                    fgetc(stdin);
                    
                    if(payment > completeFee) {
                        printf("\nYou've entered more than the required fee!");
                        printf("\nWould you like to continue with the entered amount? [y/n]: ");
                        scanf("%c", &response);
                        fgetc(stdin);
                    }
                    else if(payment != 2500 && payment != 5000) {
                        printf("\n(Payment can be done in maximum two installments of 2500frs each)");
                        correctPaymentDone = false; 
                    }
                } while(response == 'n' || !correctPaymentDone);
                calculateInstallment(payment, &class, i);

                fclose(fp); // The previous fp has to be closed before another fp is opened.

                fp = fopen("Info.bin", "ab+");
                fwrite(&class, sizeof(class), 1, fp);
                fclose(fp);

                studentFound = true;
                break;
            }
        }
    }
    
    if(!studentFound) {
        printf("\nStudent %s was not found.", name);

        return -1;
    }

    fp = fopen("File Info.txt", "a+");

    fprintf(fp, "\n**************************************************\n");
    fprintf(fp, "**************************************************\n");
    fprintf(fp, "====Updated Information of %s at %s====\n", name, ctime(&now));
    fprintf(fp, "\nStudent: %s", class.student[i].name);
    fprintf(fp, "\nPhone: %s", class.student[i].phone);
    fprintf(fp, "\nAddress: %s", class.student[i].address);
    if(class.student[i].fee.isCompleted) {
            fprintf(fp, "\nFee has now been paid in full!");
            fprintf(fp, "\nNumber of Installments paid in: %d", class.student[i].fee.numOfInstallments);
    }
    else if(!class.student[i].fee.isCompleted) {
        fprintf(fp, "\nFee has still not been paid in full!");

        int totalFeePaid = 0;
        for(int k = 0; k < class.student[i].fee.numOfInstallments; k++) {
            totalFeePaid += class.student[i].fee.installments[k];
        }
        fprintf(fp, "\nTotal fee paid: %d", totalFeePaid);
        fprintf(fp, "\nNumber of installments paid in: %d", class.student[i].fee.numOfInstallments);
    }
    fprintf(fp, "\n");
    printf("\nDone!");

    fclose(fp);

    return 0;
}

int searchStudent(char name[]) {

    system("cls");

    time_t now;
    time(&now);

    Class class;
    bool studentFound = false;
    char option = 'y';
    int i, payment; // To keep track of the student;

    fp = fopen("Info.bin", "rb");
    int h = 1;

    while (fread(&class, sizeof(class), 1, fp)) {
        printf("\n\nRecord %d", h);
        h++;
        for(i = 0; i < class.numOfStuds; i++) {
            if(!strcmp(class.student[i].name, name)) {
                printf("\nProoving to have found! i: %d", i);
                printf("\nNumber of Students: %d", class.numOfStuds);
                printf("\nStudent: %s", class.student[i].name);
                printf("\nPhone: %s", class.student[i].phone);
                printf("\nAddress: %s", class.student[i].address);
                if(class.student[i].fee.isCompleted) {
                    printf("\nFee has been paid in full!");
                    printf("\nNumber of Installments paid in: %d", class.student[i].fee.numOfInstallments);
                }
                else if(!class.student[i].fee.isCompleted) {
                    printf("\nFee has not been paid in full!");

                    int totalFeePaid = 0;
                    for(int k = 0; k < class.student[i].fee.numOfInstallments; k++) {
                        totalFeePaid += class.student[i].fee.installments[k];
                    }
                    printf("\nTotal fee paid: %d", totalFeePaid);
                    printf("\nNumber of installments paid in: %d", class.student[i].fee.numOfInstallments);
                }
                printf("\n");

                studentFound = true;
            }
        }
    }
    fclose(fp);

    if(!studentFound) {
        printf("\nStudent %s was not found.", name);

        return -1;
    }

    return 0;
}

int deleteStudent(char name[]) {
    fp = fopen("Info.bin", "rb");
    if(!fp) {
        return -1;
    }
    fptr = fopen("temp.bin", "wb+");
    if(!fptr) {
        return -1;
    }

    int i;
    bool found = false;
    Class class;

    while (fread(&class, sizeof(class), 1, fp)) {
        for(i = 0; i < class.numOfStuds; i++) {
            if(!strcmp(class.student[i].name, name)) {
                printf("\nRecord with requested name found and deleted!");

                found = true;
            } else {
                fwrite(&class, sizeof(class), 1, fptr);
            }
        }
    }

    if(!found) {
        printf("\nNo record exists with name: %s.", name);
    }

    fclose(fp);
    fclose(fptr);

    remove("Info.bin");
    rename("temp.bin", "Info.bin");

    return 0;
}

/*
* I got the idea of creating a remark var for each student
* The remark var will store the fee remark of the student
* I also think i will include the updated (boolean) var
* The updated var will serve for the new 'file info.txt' i will need to make
* I will also make a function to generate a 'file info.txt' (this is where the remark and 'update' vars
* will really come in handy).
*/