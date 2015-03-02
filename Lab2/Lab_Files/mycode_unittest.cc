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
  EXPECT_EQ(y, 15);
  EXPECT_EQ(z, 22);
}

TEST(MatrixAddnMul, Blah) {
	matrix a(2);
	matrix b(2);
	matrix c(2);
	matrix d;
	d=a+b;
	d=d*c;

	int w=d.m[0][0];
	int x=d.m[0][1];
	int y=d.m[1][0];
	int z=d.m[1][1];

  EXPECT_EQ(w, 14);
  EXPECT_EQ(x, 20);
  EXPECT_EQ(y, 30);
  EXPECT_EQ(z, 44);
}