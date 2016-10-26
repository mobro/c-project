/*
 * =====================================================================================
 *
 *       Filename:  sqroot.c
 *
 *    Description:  Calculate the square root of a const double value
 *
 *        Version:  1.0
 *        Created:  10/25/2016 10:28:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Moritz Broghammer (), MoritzBroghammer@web.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <math.h>
#include <fos/math/sqroot.h>

double squareRoot(const double a)
{
  double b = sqrt(a);
  if (b != b)
  {                             // nan check
    return -1.0;
  } else
  {
    return sqrt(a);
  }
}
