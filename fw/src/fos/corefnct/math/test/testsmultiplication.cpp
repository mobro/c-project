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
#include "../src/fw_mulitplication.c"
#include <gtest/gtest.h>

TEST(MulitplicationTest, NegativeNos)
{
  double dResult = 0;
    
  umult32( 2.0, 2.0, &dResult);
  
  ASSERT_EQ( -1.0, dResult);
  
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}                               /* ----------  end of function main  ---------- */
