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

#include <sms/sysctrl.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

int main(int argc, char *argv[])
{
  printf("Beginning of program\n");

  InitSysctrl();



  printf("End of program\n");

  return 0;
}                               /* ----------  end of function main  ---------- */
