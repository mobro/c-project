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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fos/math/sqroot.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

int main(int argc, char *argv[])
{
  int32_t i32Cntr = 0;
  printf("Beginning of program\n");
#ifdef __linux__
  printf("You are running under linux\n");
#elif _WIN32
  printf("You are running under windows\n");
#else
#endif

  pid_t pid = fork();

  if (0 == pid)
  {
    int32_t i32Loop = 0;
    for (i32Loop = 0; 50 > i32Loop; i32Loop++)
    {
      printf("child process: counter value is %d\n", ++i32Cntr);
    }
  }
  else if (0 < pid)
  {
    int32_t i32Loop = 0;
    for (i32Loop = 0; 50 > i32Loop; i32Loop++)
    {
      printf("parent process: counter value is %d\n", ++i32Cntr);
    }
  }
  else
  {
    printf("fork failed\n");
  }

  printf("End of program\n");

  return 0;
}                               /* ----------  end of function main  ---------- */
