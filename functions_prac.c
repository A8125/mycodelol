#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void d_first_digit(int n)
{
    int len=0;
    int n_bak=n;
    int out_no;
    int sub_no, fin_no;
    while(n>0){
        len++;
        n=n/10;
    }
    out_no=n_bak/pow(10,len-1);
    sub_no=out_no*pow(10,len-1);
    fin_no=out_no-sub_no;
    printf("%d",fin_no);
}
int main()
{
    int n;
    printf("Enter a number: \n");
    scanf("%d",&n);
    d_first_digit(n);
    return 0;
}
