#include <stdio.h>

//Function to calculate common divider of two numbers
int gcd(int a, int b)
{
    int c;
    while (a != 0) {
        c = a; a = b%a;  b = c;
    }
    return b;
}

int main() {
    //Menu Variables
    int menu;
    //Indexing Variable
    int i = 0, j = 0;
    // Int Variables for Calculations (Menu Option 2)
    int temp1, num1, num2;
    int a, b, c; //Calculating biggest divisor
    long long  gcd, div = 2, ans = 0, maxfact;//Caclucalting largest prime
    //Int Variables for Creating Square(Menu Option 3)
    int wid, hei;
    //Print Main Menu
    printf("Please select a choice from the menu\n"
        " 0 Exit \n 1 Main Menu \n 2 Devider Calculator \n 3 Print Square\n");
    while (i < 5)
    {
        //Insert Selected Option into the Variable
        scanf("%d", &menu);
        // Check If the Selected Option is Valid
        if (menu > 4) {
            // Check if the User has inserted wrong option too many times
            if (i == 4) {
                printf("You have inserted invalid number too many times, the program will now exit\n");
                break;
            }
            else
                //Notify User that he has selected invalid option
                i++;
            printf("The number you have inserted is invalid Please Try Again\n");
            continue;
        }
        //Check Which Menu Item Has Been Selected and Run Commands
        switch (menu) {
        case 0:
            //Terminate the Program
            break;
            break;
        case 1:
            //Reprint Main Menu
            printf("Please select a choice from the menu\n"
                " 0 Exit \n 1 Main Menu \n 2 Devider Calculator \n 3 Print Square\n");
            break;
        case 2:
            do {
                printf("Please Enter 1st Number (Upper Row),Positive Number Up To 6 Digits Long\n");
                scanf("%d", &num1);
            } while (num1 > 1000000);
            do {
                printf("Please Enter the 2nd Number (Left Column),Positive Number Up to 6 Digits Long\n");
                scanf("%d", &num2);
            } while (num2 > 1000000);
            temp1 = num1;
            for (i = 0; i < 10; i++) {
                printf("\t%d", temp1++);
            }
            for (i = 0; i < 10; i++) {
                printf("\n%d", num2);
                for (j = 0; j < 10; j++) {
                    a = num1;
                    b = num2;
                    c = 0;
                    while (a != 0) {
                        c = a; a = b%a;  b = c;
                    }
                    gcd = b;
                    while (gcd != 0) {
                        if (gcd % div != 0)
                            div = div + 1;
                        else {
                            maxfact = gcd;
                            gcd = gcd / div;
                            if (gcd == 1) {
                                break;
                            }
                        }
                    }
                    printf("\t%d", maxfact);
                    num1++;
                }
                num1 -= 10;
                num2++;
            }
            printf("\n Please Choose From The Menu Again");
                break;
        case 3:
            do {
                printf("Please enter the square odd width, range 5-21\n");
                scanf("%d", &wid);
            } while ((wid % 2) == 0 || wid<5 || wid>21);
            do {
                printf("Please enter the square odd height, range 5-21\n");
                scanf("%d", &hei);
            } while ((hei % 2) == 0 || hei<5 || hei>21);
            for (i = 0; i < wid; i++) {
                printf("\n");
                for (j = 0; j < hei; j++)

                    printf("o");
            }
            break;
        default:
            NULL;
        }
    }
    return 0;
}
