#include <iostream>

#include <gtest/gtest.h>

#include <heap/heap.h>

TEST(MaxHeapify, HeapifyBubbleDown)
{
	int collection[6] = { 1, 10, 9, 7, 3, 1 };
	MaxHeapify<int>(collection, 0, 6);
	EXPECT_EQ(10, collection[0]);
	EXPECT_EQ(7, collection[1]);
	EXPECT_EQ(9, collection[2]);
	EXPECT_EQ(1, collection[3]);
	EXPECT_EQ(3, collection[4]);
	EXPECT_EQ(1, collection[5]);
}

TEST(BuildMaxHeap, BuildSimple)
{
	int collection[6] = { 1, 10, 9, 7, 3, 1 };
	BuildMaxHeap<int>(collection, 6);
	EXPECT_EQ(10, collection[0]);
	EXPECT_EQ(7, collection[1]);
	EXPECT_EQ(9, collection[2]);
	EXPECT_EQ(1, collection[3]);
	EXPECT_EQ(3, collection[4]);
	EXPECT_EQ(1, collection[5]);
}

TEST(BuildMaxHeap, BuildComplicated)
{
	int collection[15] = { 10, 84, 9, 84, 77, 42, 3, 9, 18, 101, 44, 33, 22, 11, 15 };
	BuildMaxHeap<int>(collection, 15);
	EXPECT_EQ(101, collection[0]);
	EXPECT_EQ(84, collection[1]);
	EXPECT_EQ(42, collection[2]);
	EXPECT_EQ(18, collection[3]);
	EXPECT_EQ(84, collection[4]);
	EXPECT_EQ(33, collection[5]);
	EXPECT_EQ(15, collection[6]);
	EXPECT_EQ(9, collection[7]);
	EXPECT_EQ(10, collection[8]);
	EXPECT_EQ(77, collection[9]);
	EXPECT_EQ(44, collection[10]);
	EXPECT_EQ(9, collection[11]);
	EXPECT_EQ(22, collection[12]);
	EXPECT_EQ(11, collection[13]);
	EXPECT_EQ(3, collection[14]);
}

TEST(HeapSort, Sort15)
{
	int collection[15] = { 10, 84, 9, 84, 77, 42, 3, 9, 18, 101, 44, 33, 22, 11, 15 };
	HeapSort<int>(collection, 15);
	for (int x = 0; x < 15; x++)
		std::cout << collection[x] << " ";
	std::cout << std::endl;
}