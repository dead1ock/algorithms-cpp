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
	EXPECT_EQ(3, collection[0]);
	EXPECT_EQ(9, collection[1]);
	EXPECT_EQ(9, collection[2]);
	EXPECT_EQ(10, collection[3]);
	EXPECT_EQ(11, collection[4]);
	EXPECT_EQ(15, collection[5]);
	EXPECT_EQ(18, collection[6]);
	EXPECT_EQ(22, collection[7]);
	EXPECT_EQ(33, collection[8]);
	EXPECT_EQ(42, collection[9]);
	EXPECT_EQ(44, collection[10]);
	EXPECT_EQ(77, collection[11]);
	EXPECT_EQ(84, collection[12]);
	EXPECT_EQ(84, collection[13]);
	EXPECT_EQ(101, collection[14]);
}

TEST(HeapMaximum, Maximum) {
	int collection[15] = { 10, 84, 9, 84, 77, 42, 3, 9, 18, 101, 44, 33, 22, 11, 15 };
	BuildMaxHeap<int>(collection, 15);
	EXPECT_EQ(101, HeapMaximum<int>(collection, 15));
}

TEST(HeapExtractMax, ExtractMax) {
	int collection[15] = { 10, 84, 9, 84, 77, 42, 3, 9, 18, 101, 44, 33, 22, 11, 15 };
	BuildMaxHeap<int>(collection, 15);
	int size = 15;

	EXPECT_EQ(101, HeapExtractMax<int>(collection, size));
	EXPECT_EQ(14, size);
	EXPECT_EQ(84, collection[0]);
	EXPECT_EQ(84, collection[1]);
	EXPECT_EQ(42, collection[2]);
	EXPECT_EQ(18, collection[3]);
	EXPECT_EQ(77, collection[4]);
	EXPECT_EQ(33, collection[5]);
	EXPECT_EQ(15, collection[6]);
	EXPECT_EQ(9, collection[7]);
	EXPECT_EQ(10, collection[8]);
	EXPECT_EQ(3, collection[9]);
	EXPECT_EQ(44, collection[10]);
	EXPECT_EQ(9, collection[11]);
	EXPECT_EQ(22, collection[12]);
	EXPECT_EQ(11, collection[13]);
}

TEST(MaxHeap, HeapIncreaseKey) {
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

	HeapIncreaseKey<int>(collection, 15, 6, 140);

	EXPECT_EQ(140, collection[0]);
	EXPECT_EQ(84, collection[1]);
	EXPECT_EQ(101, collection[2]);
	EXPECT_EQ(18, collection[3]);
	EXPECT_EQ(84, collection[4]);
	EXPECT_EQ(33, collection[5]);
	EXPECT_EQ(42, collection[6]);
	EXPECT_EQ(9, collection[7]);
	EXPECT_EQ(10, collection[8]);
	EXPECT_EQ(77, collection[9]);
	EXPECT_EQ(44, collection[10]);
	EXPECT_EQ(9, collection[11]);
	EXPECT_EQ(22, collection[12]);
	EXPECT_EQ(11, collection[13]);
	EXPECT_EQ(3, collection[14]);
}

TEST(MaxHeap, MaxHeapInsert) {
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

	int size = 15;
	int* newCollection = MaxHeapInsert<int>(collection, size, 69);
	EXPECT_EQ(101, newCollection[0]);
	EXPECT_EQ(84, newCollection[1]);
	EXPECT_EQ(42, newCollection[2]);
	EXPECT_EQ(69, newCollection[3]);
	EXPECT_EQ(84, newCollection[4]);
	EXPECT_EQ(33, newCollection[5]);
	EXPECT_EQ(15, newCollection[6]);
	EXPECT_EQ(18, newCollection[7]);
	EXPECT_EQ(10, newCollection[8]);
	EXPECT_EQ(77, newCollection[9]);
	EXPECT_EQ(44, newCollection[10]);
	EXPECT_EQ(9, newCollection[11]);
	EXPECT_EQ(22, newCollection[12]);
	EXPECT_EQ(11, newCollection[13]);
	EXPECT_EQ(3, newCollection[14]);
	EXPECT_EQ(9, newCollection[15]);
}