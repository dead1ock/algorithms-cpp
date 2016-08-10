#include <gtest/gtest.h>

#include <collection/FixedArrayStack.h>
#include <collection/LinkedListStack.h>
#include <collection/ResizableStack.h>

TEST(LINKEDLISTSTACK, PushPopCount)
{
	LinkedListStack<int> stack;

	stack.Push(100);
	stack.Push(200);
	stack.Push(300);

	EXPECT_EQ(3, stack.Count());
	EXPECT_EQ(300, stack.Pop());
	EXPECT_EQ(200, stack.Pop());
	EXPECT_EQ(100, stack.Pop());
}

TEST(LINKEDLISTSTACK, Push1000)
{
	LinkedListStack<int> stack;

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}

TEST(LINKEDLISTSTACK, Push100000)
{
	LinkedListStack<int> stack;

	for (int x = 1; x <= 100000; x++)
		stack.Push(x);

	EXPECT_EQ(100000, stack.Count());
}

TEST(LINKEDLISTSTACK, Push1000000)
{
	LinkedListStack<int> stack;

	for (int x = 1; x <= 1000000; x++)
		stack.Push(x);

	EXPECT_EQ(1000000, stack.Count());
}

// =====================================================
//
// =====================================================

TEST(FixedArrayStack, PushPopCount)
{
	FixedArrayStack<int> stack(3);

	stack.Push(100);
	stack.Push(200);
	stack.Push(300);

	EXPECT_EQ(3, stack.Count());
	EXPECT_EQ(300, stack.Pop());
	EXPECT_EQ(200, stack.Pop());
	EXPECT_EQ(100, stack.Pop());
}

TEST(FixedArrayStack, Push1000)
{
	FixedArrayStack<int> stack(1000);

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}

TEST(FixedArrayStack, Push100000)
{
	FixedArrayStack<int> stack(100000);

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}

TEST(FixedArrayStack, Push1000000)
{
	FixedArrayStack<int> stack(1000000);

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}

// =====================================================
//
// =====================================================

TEST(ResizableStack, PushPopCount)
{
	ResizableStack<int> stack;

	stack.Push(100);
	stack.Push(200);
	stack.Push(300);

	EXPECT_EQ(3, stack.Count());
	EXPECT_EQ(300, stack.Pop());
	EXPECT_EQ(200, stack.Pop());
	EXPECT_EQ(100, stack.Pop());
}

TEST(ResizableStack, Push1000)
{
	ResizableStack<int> stack;

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}

TEST(ResizableStack, Push100000)
{
	ResizableStack<int> stack;

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}

TEST(ResizableStack, Push1000000)
{
	ResizableStack<int> stack;

	for (int x = 1; x <= 1000; x++)
		stack.Push(x);

	EXPECT_EQ(1000, stack.Count());
}