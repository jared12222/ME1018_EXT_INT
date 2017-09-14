# ME1018_EXT_INT
    For class about External Interrupt
## Thinks you need to know before using External Interrupt
    Binary operation,
## Description about fuctions
### M128 EXT
    This series of function tends to set up all the settings and get the information related to External Interrupt on M128(ATmega128). Basic principles about these functions are based on the "registers" that control or indicate the status about External interrupt. Registers' description is in the following table.

    Variables
      LSByte: Index of registers.
      Mask, Shift: For Binary operation.
      Data: Input or Output value.

    set, put, fpt ---> value of register = ((Original Value) & (~Mask)) | ((Mask) & (Data << Shift))

    fgt, get      ---> value you get = ((Register value) & (Mask)) >> Shift


    |  Index  |  Register  |  Available function  |
    | :-----: | :--------: | :------------------  |
    | 200     |  EIMSK     |  set                 |
    | 201     |  EICRA     |  set                 |
    | 202     |  EICRB     |  set                 |
    | 203     |  EIFR      |  fgt, fpt            |
    | 204     |  DDRE      |  set                 |
    | 205     |  DDRF      |  set                 |
