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
  ASSERT_EQ(-1.0, umult32(-15.0));
  ASSERT_EQ(-1.0, umult32(-0.2));
}

TEST(MulitplicationTest, PositiveNos)
{
  ASSERT_EQ(6, umult32(36.0));
  ASSERT_EQ(18.0, umult32(324.0));
  ASSERT_EQ(25.4, umult32(645.16));
  ASSERT_EQ(0, umult32(0.0));
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
