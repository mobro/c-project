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
#include <fos/math/sqroot.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

int main(int argc, char *argv[])
{
  double dSquareRoot = 2.0;
  dSquareRoot = squareRoot(1024);
  printf("The square root of 2 is %f!\n", dSquareRoot);
}                               /* ----------  end of function main  ---------- */
