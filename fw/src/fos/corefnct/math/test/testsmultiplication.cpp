/*
 * =====================================================================================
 *
 *       Filename:  testsqroot.cpp
 *
 *    Description:  /
 *
 *        Version:  1.0
 *        Created:  10/26/2016 12:30:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Moritz Broghammer (), MoritzBroghammer@web.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../src/fw_multiplication.c"
#include <gtest/gtest.h>

TEST(MulitplicationTest, NegativeNos)
{
  INT32 i32Result = 0;
    
  umult32( 2, 2, &i32Result);
  
  ASSERT_EQ( 4, i32Result);
  
  umult32( 4, 2, &i32Result);
  
  ASSERT_EQ( 4, i32Result);
  
}

