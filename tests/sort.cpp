#include <iostream>

#include <gtest/gtest.h>

#include <sort/sort.h>

TEST(SelectionSort, Sort10)
{
	int collection[10];
	
	// Insert in reverse total order.
	for (int x = 9; x >= 0; x--)
		collection[9 - x] = x;

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

	// Insert in reverse total order.
	for (int x = 9; x >= 0; x--)
		collection[9 - x] = x;

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

TEST(ShuffleSort, Shuffle10)
{
	srand(time(NULL));

	int collection[10];

	// Insert in total order.
	for (int x = 0; x < 10; x++)
		collection[x] = x;

	ShuffleSort<int>(collection, 10);

	std::cout << "Collection: ";
	for (int x = 0; x < 10; x++)
		std::cout << collection[x] << " ";
	std::cout << std::endl;
}

TEST(ShellSort, Sort10)
{
	int collection[10];

	// Insert in total order.
	for (int x = 0; x < 10; x++)
		collection[x] = x;

	ShuffleSort<int>(collection, 10);
	ShellSort<int>(collection, 10);

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

TEST(Partition, Partition6)
{
	int collection[10] = { 8, 4, 6, 7, 10, 5 };
	EXPECT_EQ(1, Partition<int>(collection, 6));
	EXPECT_EQ(4, collection[0]);
	EXPECT_EQ(5, collection[1]);
	EXPECT_EQ(6, collection[2]);
	EXPECT_EQ(7, collection[3]);
	EXPECT_EQ(10, collection[4]);
	EXPECT_EQ(8, collection[5]);
}

TEST(QuickSort, Sort6)
{
	int collection[10] = { 8, 4, 6, 7, 10, 5 };
	QuickSort<int>(collection, 6);
	EXPECT_EQ(4, collection[0]);
	EXPECT_EQ(5, collection[1]);
	EXPECT_EQ(6, collection[2]);
	EXPECT_EQ(7, collection[3]);
	EXPECT_EQ(8, collection[4]);
	EXPECT_EQ(10, collection[5]);
}

TEST(Merge, Merge6)
{
	int collection[6] = { 5, 7, 10, // First array
		1, 4, 6 }; // Second array
	Merge<int>(collection, 0, 2, 5);
	EXPECT_EQ(1, collection[0]);
	EXPECT_EQ(4, collection[1]);
	EXPECT_EQ(5, collection[2]);
	EXPECT_EQ(6, collection[3]);
	EXPECT_EQ(7, collection[4]);
	EXPECT_EQ(10, collection[5]);
}

TEST(MergeSort, Sort6)
{
	int collection[6] = { 7, 5, 10, 4, 1, 6 };
	MergeSort<int>(collection, 6);
	EXPECT_EQ(1, collection[0]);
	EXPECT_EQ(4, collection[1]);
	EXPECT_EQ(5, collection[2]);
	EXPECT_EQ(6, collection[3]);
	EXPECT_EQ(7, collection[4]);
	EXPECT_EQ(10, collection[5]);
}