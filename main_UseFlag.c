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

int main(int argc, char const *argv[]) {
    //-------------variables
    char check,data;                    // for getting interrupt flag
    //-------------initial settings
    ASA_M128_set();                // initial settings for M128
    M128_EXT_set( reg_ExtINT_Mode_B , 0x03 , 0 , 3 );    // set INT4 triggered by low level
    M128_EXT_set( reg_ExtINT_DDR_B  , 0x10 , 4 , 0 );    // set INT4 as input to be able be triggered

    while(1)
    {
        //------------ wait for triggered
        while(check)
        {
            M128_EXT_fgt( reg_ExtINT_Flag , 0x10 , 4 , &check );    // if flag is set, leave the loop
        }

        //------------ after triggered
        ASA_KB00_get( KB00_ID , 100, 1 , &data);

        M128_EXT_fpt(203,0x10,4,1);    // clear the flag if interrupt isn't enable
    }
    return 0;
}
