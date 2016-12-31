/*
 * =====================================================================================
 *
 *       Filename:  sysctrl.c
 *
 *    Description:  System controller module
 *
 *        Version:  1.0
 *        Created:  12/31/2016 08:39:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Moritz Broghammer (), MoritzBroghammer@web.de
 *   Organization:  
 *
 * =====================================================================================
 */

#include <fos/config.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sms/sysctrl.h>
#include <fos/math/sqroot.h>
#include <as/meas/measctrl.h>
#include <fos/os/syscallint.h>

static void CreateUIProcess(int32_t i32Cntr);
static void CreateMeasProcess(int32_t i32Cntr);

void InitSysctrl()
{
  int32_t i32Loop = 0;
  int32_t i32Cntr = 0;

  CreateUIProcess(i32Cntr);
  CreateMeasProcess(i32Cntr);

  for (i32Loop = 0; 20 > i32Loop; i32Loop++)
  {
    printf("parent process: counter value is %d\n", ++i32Cntr);
  }

  // Wait here till all child processes are closed
  wait();
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateMeasProcess
 *  Description:  
 * =====================================================================================
 */
static void CreateMeasProcess(int32_t i32Cntr)
{
  int32_t iPID = 0;

  iPID = CreateProcess();

  if (0 == iPID)
  {
    // Start the measctrl process
    InitMeasctrl(i32Cntr);
  }
  else if (0 > iPID)
  {
    printf("fork failed\n");
  }

}                               /* -----  end of function CreateMeasProcess  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateUIProcess
 *  Description:  
 * =====================================================================================
 */
static void CreateUIProcess(int32_t i32Cntr)
{
  int32_t iPID = 0;

  iPID = CreateProcess();

  if (0 == iPID)
  {
    // Start the measctrl process
    InitUIctrl(i32Cntr);
  }
  else if (0 > iPID)
  {
    printf("fork failed\n");
  }

}                               /* -----  end of function CreateMeasProcess  ----- */
