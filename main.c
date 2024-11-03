/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"



int main(void)
{
    uint8 compare =0 ;
    uint8 compare1 =0 ;
    
    uint8 i2cbuf[2];
    i2cbuf[0] = 0;
    i2cbuf[1] = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    PWM_Start();
    PWM1_Start();
    I2C_Start();
    I2C_EzI2CSetBuffer1(2,2,i2cbuf);
    

    for(;;)
    {
        if(compare!= i2cbuf[0])
        {
            compare = i2cbuf[0];
            PWM_WriteCompare(compare);
        }
        if(compare1!= i2cbuf[1])
        {
            compare1 = i2cbuf[1];
            PWM1_WriteCompare(compare1);
        }
        
    }
}

/* [] END OF FILE */
