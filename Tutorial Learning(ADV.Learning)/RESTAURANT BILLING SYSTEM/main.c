#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// structures

typedef struct {
    float price;
    int qty;
    char item[20];
} Items;

typedef struct  {
    int numOfItems;
    Items itm[50];
    char customer[50];
    char date[25];
    char time[25];
} Orders;

// functions to generate bills
void generateBillHeader(char name[50], char date[30], char time[30]) {
    printf("\n\n");
    printf("\t    Flinfo7");
    printf("\n\t   ==========");
    printf("\nDate: %s", date);
    printf("\nTime: %s", time);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("------------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n------------------------------------------");
    printf("\n\n");
}

void generateBillBody(char item[30], int qty, float price) {
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

void generateBillFooter(float total) {
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst; // netTotal + cgst +sgst
    // CGST = Central Goods and Service Tax
    // SGST = State Goods and Service Tax

    printf("------------------------------------------\n");
    printf("Sub Total:\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t--------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n------------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n------------------------------------------\n");
}

int main() {

    int opt, n;
    float total;
    Orders ord;
    Orders order;
    char saveBill = 'y';
    char name[50];
    FILE *fp;

    //Dashboard
    start: system("cls"); // Start takes the program over if the user chooses, i.e. after an operation
    printf("\t==========Flinfo7=========="); 
    repeat: printf("\n\nPlease select your prefered operation"); // Repeat takes the program over if the user enters a wrong option
    printf("\n\n1. Generate Invoice");
    printf("\n2. Show all Invoices");
    printf("\n3. Search Invoice");
    printf("\n4. Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
        system("cls");
        printf("\nPlease enter the name  of the customer:\t");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer) - 1] = '\0';
        strcpy(ord.date, __DATE__);
        strcpy(ord.time, __TIME__);
        printf("\nPlease enter the number of items:\t");
        scanf("%d", &n);
        ord.numOfItems = n;
        total = 0;

        for(int i=0; i < n; i++) {
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t", i + 1);
            fgets(ord.itm[i].item, 20, stdin);
            ord.itm[i].item[strlen(ord.itm[i].item) - 1] = '\0';
            printf("Please enter the quantity:\t");
            scanf("%d", &ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f", &ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.customer, ord.date, ord.time);
        for(int i = 0; i < ord.numOfItems; i++)
        {
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);

        fgetc(stdin);
        printf("\nDo you want to save the Invoice? [y/n]:\t");
        scanf("%c", &saveBill);
        fgetc(stdin);

        saveBill = tolower(saveBill);

        if(saveBill == 'y') {
            fp = fopen("RestaurantBill.dat", "ab+");
            int flag = 0;
            flag = fwrite(&ord, sizeof(Orders), 1, fp);
            // printf("\nDummy: %d", fwrite);

            if(flag)
                printf("\nSuccesfully saved!");
            else
                printf("\nError saving!");
            fclose(fp);
        }
        break;
    case 2:
        system("cls");
        fp = fopen("RestaurantBill.dat", "rb");
        printf("\n*******Your Previous Invoices*******\n");


        while(fread(&order, sizeof(Orders), 1, fp)) {
            total = 0;

            generateBillHeader(order.customer, order.date, order.time);
            for(int i = 0; i < order.numOfItems; i++) {
                generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                total += order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(total);
        }
        fclose(fp);
        break;
    case 3:
        printf("\nEnter the name of the customer:\t");
        fgets(name, 50, stdin);
        name[strlen(name) - 1] = '\0';

        system("cls");
        fp = fopen("RestaurantBill.dat", "rb");

        bool invoice_found = false;

        while(fread(&order, sizeof(Orders), 1, fp)) {
            total = 0;
            // invoice_found = false;

            if(!strcmp(order.customer, name)) {
                printf("\n\n*******Invoice of %s*******\n", name);
                generateBillHeader(order.customer, order.date, order.time);
                for(int i = 0; i < order.numOfItems; i++) {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                    total += order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(total);
                invoice_found = true;
            }
        }

        if(!invoice_found) {
            printf("\n\nSorry, the invoice for %s does not exist.", name);
        }

        fclose(fp);
        break;
    case 4:
        printf("\n\t\t Goodbye :)");
        exit(0);
        break;
    default:
        system("cls");
        printf("Sorry, invalid option");
        goto repeat;

        break;
    }

    char choice; // choice here is for the user to choose if they wish to take another operation and continue with the program
    printf("\n\nDo you wish to perform another operation?: [y/n]\t");
    scanf("%c", &choice);

    choice = tolower(choice);

    if(choice == 'y') goto start;
    else 
        printf("\n\t\tGoodbye :)");

    printf("\n\n");
    return 0;
}
