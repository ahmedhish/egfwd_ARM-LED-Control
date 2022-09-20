#ifndef BITWISE_OPERATION_
#define BITWISE_OPERATION_

/* Set a specific bit in any register:
 *  REG:            0x0011              --> 0b0000000000010001
 *  BIT: No.2 --(Decimal2Binary"1<<BIT")--> 0b0000000000000010 (OR)
 *                 RE                       = 0b0000000000010011
 */    
#define SET_BIT(REG,BIT) ( REG|= (1<<BIT) )


/* Clear a specific bit in any register:
 *  REG:            0x0011              --> 0b0000000000010001
 *  BIT: No.2 --(Decimal2Binary"1<<BIT")--> 0b0000000000000010 (OR)
 *                                        = 0b0000000000010011
 */ 
#define CLEAR_BIT(REG,BIT) (REG &= (~(1<<BIT)))


// Toggle a specific bit in any register
#define TOGGLE_BIT(REG,BIT) (REG ^= (1<<BIT))


// Check if a specific bit in any register is set
#define GET_BIT(REG,BIT) ( (REG & (1<<BIT))>>BIT )





#endif /*BITWISE_OPERATION_*/