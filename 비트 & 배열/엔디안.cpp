#include<stdio.h>
main(void){
        int n = 0x00111111;
        char * c = (char *)&n;
        printf("%x\n",c[0]);

        if(c[0])
            printf("little endian");
            // 11 11 11 00
        else 
            printf("big endian");
            // 00 11 11 11 
}
