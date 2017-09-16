#include "ASA_Lib.h"
//----------definition about External interrupt(M128_EXT series)
#define reg_ExtINT_Enable       200
#define reg_ExtINT_Mode_A       201
#define reg_ExtINT_Mode_B       202
#define reg_ExtINT_Flag         203
#define reg_ExtINT_DDR_A        204
#define reg_ExtINT_DDR_B        205

#define INTn_Enable              1
#define INTn_Disable             0
//----------definition about KB00
#define KB00_ID 2

//----------function be executed when interrupt
char data;
char flag;
void func(void)
{
    //------------ after triggered
    ASA_KB00_get( KB00_ID , 100, 1 , &data);
    flag = 1;
}

int main(int argc, char const *argv[]) {
    //-------------variables

    //-------------initial settings
    ASA_M128_set();                     // initial settings for M128
    M128_EXT_set( reg_ExtINT_Mode_B , 0x03 , 0 , 3 );    // set INT4 triggered by low level
    M128_EXT_set( reg_ExtINT_DDR_B  , 0x10 , 4 , 0 );    // set INT4 as input to be able be triggered
    M128_EXT_isr( 4 , func);                             // Register function executed when triggered
    M128_EXT_set( reg_ExtINT_Enable , 0x01 , 0 , 1 );    // Enable INT4 interrupt

    while(1)
    {
        if(flag)
        {
            printf("Data: %d\n", data );
            flag = 0;
        }

    }
    return 0;
}
