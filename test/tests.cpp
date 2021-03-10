// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "fun.h"

TEST(task1, test1) {
  const char * str = "qwe4  gftt e 555gr rrgr  grhh ";
  unsigned int result = faStr1(str);
  EXPECT_EQ(4,result);
}

TEST(task1, test2) {
  const char * str = "  qwe4 ";
  unsigned int result = faStr1(str);
  EXPECT_EQ(0,result);
}

TEST(task2, test3) {
  const char * str = "Hello, world!";
  unsigned int result = faStr2(str);
  EXPECT_EQ(0,result);
}

TEST(task2, test4) {
  const char * str = "Hello world!";
  unsigned int result = faStr2(str);
  EXPECT_EQ(1,result);
}

TEST(task3, test5) {
  const char * str = " bad dog ";
  unsigned int result = faStr3(str);
  EXPECT_EQ(3,result);
}

TEST(task3, test6) {
  const char * str = " six monkeys";
  unsigned int result = faStr3(str);
  EXPECT_EQ(5,result);
}

TEST(task3, roundTest) {
  const char * str = "a bc de";
  unsigned int result = faStr3(str);
  EXPECT_EQ(2,result);
}

TEST(task3, divisionByZeroTest) {
  const char * str = " ";
  unsigned int result = faStr3(str);
  EXPECT_EQ(0,result);
}
