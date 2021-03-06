/*
 * =====================================================================================
 *
 *       Filename:  measctrl.c
 *
 *    Description:  Measurement controller module
 *
 *        Version:  1.0
 *        Created:  12/29/2016 06:19:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Moritz Broghammer (), MoritzBroghammer@web.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <as/meas/measctrl.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitMeasctrl
 *  Description:  
 * =====================================================================================
 */
void InitMeasctrl(int32_t i32Cntr)
{
  int32_t i32Loop = 0;

  for (i32Loop = 0; 10 > i32Loop; i32Loop++)
  {
    printf("child meas process: counter value is %d\n", ++i32Cntr);
  }

  while(1)
  {
        // This is the meas controller super loop
  }
}                               /* -----  end of function InitMeasctrl  ----- */
