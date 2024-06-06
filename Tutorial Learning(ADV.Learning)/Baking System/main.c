#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {

    system("color 3F");

    int pin= 1234, enteredPin, option, count = 0, continueTransaction = 1, amount = 1;
    int balance = 100000;

    time_t now;
    time(&now);
    printf("\n\t%s", ctime(&now));

    while(pin != enteredPin) {
        printf("\nEnter pin: ");
        scanf("%d", &enteredPin);

        if(pin != enteredPin) {
            Beep(600, 300);
            printf("\nInvalid Pin!");

            count++;
        }

        if(count ==  3 && pin != enteredPin) {
            printf("\nIt's either you've forgotten your pin or this pin isn't yours! :(");
            exit(0);
        }
    }

    while (continueTransaction != 0)
    {
        system("cls");
        printf("==============*Welcome to Banking with us.*==============");
        printf("\n\nEnter option from below");
        printf("\n1. Widthdraw");
        printf("\n2. Deposit");
        printf("\n3. Check Balance");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d", &option);

        switch(option){
            case 1
                while (amount % 500 != 0 || amount > balance)
                {
                    printf("\nEnter amount: ");
                    scanf("%d", &amount);

                    if(amount % 500 != 0) {
                        Beep(400, 500);
                        printf("\nAmount must be a multiple of 500");
                    }
                    if(amount > balance) {
                        Beep(400, 300);
                        printf("\nYou cannot widthdraw more than you current balance!");
                    }
                }
                
                balance -= amount;

                printf("You have succesfully widthdrawn XAF%d. Current balance: XAF%d", amount, balance);
                amount = 1;
                break;
            case 2:
                while (amount % 500 != 0)
                {
                    printf("\nEnter amount: ");
                    scanf("%d", &amount);

                    if(amount % 500 != 0) {
                        Beep(400, 500);
                        printf("\nAmount must be a multiple of 500");
                    }
                }
                
                balance += amount;

                printf("\nYou have succesfully Deposited XAF%d. Current balance: XAF%d", amount, balance);
                amount = 1;
                break;
            case 3:
                printf("\nYour current balance is: XAF%d", balance);
                break;
            case 4:
                printf("\nGoodbye!");
                exit(0);
            default:
                printf("\nPlease enter a valid option!");
                break;
        }

        printf("\nDo you wish to make another operation? Enter 1[Yes] and 0[No]: ");
        scanf("%d", &continueTransaction);
        fgetc(stdin);
    }

    return 0;
    
}
