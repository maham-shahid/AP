#include "mycode.h"
#include "gtest/gtest.h"

TEST(MatrixAdd, Blah) {
	matrix a(2);
	matrix b(2);
	matrix c;
	c=a+b;
	int w=c.m[0][0];
	int x=c.m[0][1];
	int y=c.m[1][0];
	int z=c.m[1][1];

  EXPECT_EQ(w, 2);
  EXPECT_EQ(x, 4);
  EXPECT_EQ(y, 6);
  EXPECT_EQ(z, 8);
}

TEST(MatrixSub, Blah) {
	matrix a(2);
	matrix b(2);
	matrix c;
	c=a-b;
	int w=c.m[0][0];
	int x=c.m[0][1];
	int y=c.m[1][0];
	int z=c.m[1][1];

  EXPECT_EQ(w, 0);
  EXPECT_EQ(x, 0);
  EXPECT_EQ(y, 0);
  EXPECT_EQ(z, 0);
}

TEST(MatrixMul, Blah) {
	matrix a(2);
	matrix b(2);
	matrix c;
	c=a*b;
	int w=c.m[0][0];
	int x=c.m[0][1];
	int y=c.m[1][0];
	int z=c.m[1][1];

  EXPECT_EQ(w, 7);
  EXPECT_EQ(x, 10);
  EXPECT_EQ(y, 12);
  EXPECT_EQ(z, 24);
}
