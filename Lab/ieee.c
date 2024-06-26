#include <stdio.h>

void printb(unsigned int val, int len){
    for(int i=0;i<len;i++,val<<=1){
        printf("%d",!!(val & 0x80000000U));
        // printf("%d",val<0);
    }
}

void printIEEEfields(float val){
    unsigned int bits=*((unsigned int*)&val);
    // int bits=*((int*)&val);
    printf("s: %d ",!!(bits & 0x80000000U));
    // printf("s: %d",bits<0);
    bits<<=1;
    printf("exp: ");
    printb(bits,8);
    printf(" frac: ");
    bits<<=8;
    printb(bits,23);
    printf("\n");
}

int main(void){
    float val;
    scanf("%f",&val);
    printIEEEfields(val);
    return 0;
}