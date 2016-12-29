/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.08.2016 17:38:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fos/config.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <fos/math/sqroot.h>
#include <as/meas/measctrl.h>
#include <fos/os/syscallint.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

int main(int argc, char *argv[])
{
  int32_t iPID = 0;
  int32_t i32Cntr = 0;

  printf("Beginning of program\n");
  
  iPID = CreateProcess();

  if (0 == iPID)
  {
    // Start the measctrl process
    InitMeasctrl(i32Cntr);
  }
  else if (0 < iPID)
  {
    int32_t i32Loop = 0;
    for (i32Loop = 0; 50 > i32Loop; i32Loop++)
    {
      printf("parent process: counter value is %d\n", ++i32Cntr);
    }
    wait();
  }
  else
  {
    printf("fork failed\n");
  }

  printf("End of program\n");

  return 0;
}                               /* ----------  end of function main  ---------- */
