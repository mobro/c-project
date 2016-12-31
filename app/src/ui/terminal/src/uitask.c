/*
 * =====================================================================================
 *
 *       Filename:  uitask.c
 *
 *    Description:  This module contains the user interface process
 *
 *        Version:  1.0
 *        Created:  12/31/2016 08:17:29 PM
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
#include <ui/terminal/uitask.h>

void InitUIctrl(int32_t i32Cntr)
{
  int32_t i32Loop = 0;

  for (i32Loop = 0; 10 > i32Loop; i32Loop++)
  {
    printf("child UI process: counter value is %d\n", ++i32Cntr);
  }
  while(1)
  {
// super ui loop stay here
  }
}                               /* -----  end of function InitMeasctrl  ----- */
