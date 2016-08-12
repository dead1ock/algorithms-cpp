#include <gtest/gtest.h>

#include <sort/sort.h>

TEST(SelectionSort, Sort10)
{
	int collection[10];
	
	for (int x = 9; x >= 0; x--)
		collection[x] = x;

	SelectionSort<int>(collection, 10);

	EXPECT_EQ(0, collection[0]);
	EXPECT_EQ(1, collection[1]);
	EXPECT_EQ(2, collection[2]);
	EXPECT_EQ(3, collection[3]);
	EXPECT_EQ(4, collection[4]);
	EXPECT_EQ(5, collection[5]);
	EXPECT_EQ(6, collection[6]);
	EXPECT_EQ(7, collection[7]);
	EXPECT_EQ(8, collection[8]);
	EXPECT_EQ(9, collection[9]);
}

TEST(InsertionSort, Sort10)
{
	int collection[10];

	for (int x = 9; x >= 0; x--)
		collection[x] = x;

	InsertionSort<int>(collection, 10);

	EXPECT_EQ(0, collection[0]);
	EXPECT_EQ(1, collection[1]);
	EXPECT_EQ(2, collection[2]);
	EXPECT_EQ(3, collection[3]);
	EXPECT_EQ(4, collection[4]);
	EXPECT_EQ(5, collection[5]);
	EXPECT_EQ(6, collection[6]);
	EXPECT_EQ(7, collection[7]);
	EXPECT_EQ(8, collection[8]);
	EXPECT_EQ(9, collection[9]);
}