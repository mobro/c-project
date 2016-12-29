/*
 * =====================================================================================
 *
 *       Filename:  syscallint.c
 *
 *    Description:  System-call interface to the kernel
 *
 *        Version:  1.0
 *        Created:  12/29/2016 07:28:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Moritz Broghammer (), MoritzBroghammer@web.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <fos/os/syscallint.h>

int32_t CreateProcess(void)
{
  pid_t pid = -1;
#ifdef __linux__
  pid = fork();
#else
  printf("Wrong os!");
#endif

  return (int32_t) pid;
}
