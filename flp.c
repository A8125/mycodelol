#include <stdio.h>
#include <stdlib.h>

int pwr(int x, int y){
    int c=1;
    while(y>0){
        c=x*c;
        y-=1;
    }
    return c;
}

int len(int n){
    int len=0;
    while(n>0){
        n=n/10;
        len++;
    }
    return len;
}

int exclude_digits(int n, int m){
    int c= n%pwr(10,len(n)-m);
    return c;
}

void append_number_end(int n){
    int m;
    int out_no;
    printf("\nEnter the number you want to append:\n");
    scanf("%d",&m);
    out_no = (n*pwr(10,len(m)))+m;
    printf("%d",out_no);
}
void replace_digits(int n){
    int m;
    printf("Enter a number you want to replace the digits with:\n");
    scanf("%d",&m);
    n=n/pwr(10,len(m));
    n=(n*pwr(10,len(m)))+m;
    printf("%d",n);
}
void append_number_wherever(int n){
    int m, c;
    int append_loc;
    int n_bak=n;
    printf("\nEnter after how many digits you'd like to append the number(FROM THE FRONT):\n");
    scanf("%d",&append_loc);
    printf("\nEnter the number you'd like to append:\n");
    scanf("%d",&m);
    n=n/pwr(10,len(n)-append_loc);
    n=n*pwr(10,len(m))+m;
    c=exclude_digits(n_bak,append_loc);
    n=(n*pwr(10,len(c)))+c;
    printf("%d",n);
}

void append_front(int n){
    int m;
    n = (m*pwr(10,len(n)))+n;
    printf("%d",&n);
}


int main(){
    int choice;
    int num;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Get power of a number\n");
       printf("2. Get length of a number\n");
        printf("3. Exclude digits from end\n");
        printf("4. Append number at end\n");
        printf("5. Append number at specific position\n");
        printf("6. Replace digits\n");
        printf("7. Append numbers in the front\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter base: ");
                scanf("%d", &num);
                int exp;
                printf("Enter exponent: ");
                scanf("%d", &exp);
                printf("Result: %d\n", pwr(num, exp));
                break;
            case 2:
                printf("Enter number: ");
                scanf("%d", &num);
                printf("Length: %d\n", len(num));
                break;
            case 3:
                printf("Enter number: ");
                scanf("%d", &num);
                int m;
                printf("Enter number of 1digits to exclude from end: ");
                scanf("%d", &m);
                printf("Result: %d\n", exclude_digits(num, m));
                break;
            case 4:
                printf("Enter number: ");
                scanf("%d", &num);
                append_number_end(num);
                break;
            case 5:
                printf("Enter number: ");
                scanf("%d", &num);
                append_number_wherever(num);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%d", &num);
                replace_digits(num);
                break;            
            case 7:
                printf("Enter a number: ");
                scanf("%d", &num);
                append_front(num);
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 8);
    return 0;
}