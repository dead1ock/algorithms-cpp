#include <gtest/gtest.h>

#include <collection/FixedArrayStack.h>
#include <collection/FixedQueue.h>
#include <collection/LinkedListStack.h>
#include <collection/LinkedQueue.h>
#include <collection/ResizableStack.h>
#include <collection/ResizableQueue.h>

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

// =====================================================
//
// =====================================================

TEST(FixedQueue, EnqueueDequeueCount)
{
	FixedQueue<int> queue(3);

	queue.Enqueue(100);
	queue.Enqueue(200);
	queue.Enqueue(300);

	EXPECT_EQ(3, queue.Count());
	EXPECT_EQ(100, queue.Dequeue());
	EXPECT_EQ(200, queue.Dequeue());
	EXPECT_EQ(300, queue.Dequeue());
}

TEST(FixedQueue, Enqueue1000)
{
	FixedQueue<int> queue(1000);

	for (int x = 1; x <= 1000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000, queue.Count());
}

TEST(FixedQueue, Enqueue100000)
{
	FixedQueue<int> queue(100000);

	for (int x = 1; x <= 100000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(100000, queue.Count());
}

TEST(FixedQueue, Enqueue1000000)
{
	FixedQueue<int> queue(1000000);

	for (int x = 1; x <= 1000000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000000, queue.Count());
}

TEST(FixedQueue, ProduceEnqueueOverflow)
{
	FixedQueue<int> queue(1000000);

	for (int x = 1; x <= 1000001; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000000, queue.Count());
}

// =====================================================
//
// =====================================================

TEST(LinkedQueue, EnqueueDequeueCount)
{
	LinkedQueue<int> queue;

	queue.Enqueue(100);
	queue.Enqueue(200);
	queue.Enqueue(300);

	EXPECT_EQ(3, queue.Count());
	EXPECT_EQ(100, queue.Dequeue());
	EXPECT_EQ(200, queue.Dequeue());
	EXPECT_EQ(300, queue.Dequeue());
}

TEST(LinkedQueue, Enqueue1000)
{
	LinkedQueue<int> queue;

	for (int x = 1; x <= 1000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000, queue.Count());
}

TEST(LinkedQueue, Enqueue100000)
{
	LinkedQueue<int> queue;

	for (int x = 1; x <= 100000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(100000, queue.Count());
}

TEST(LinkedQueue, Enqueue1000000)
{
	LinkedQueue<int> queue;

	for (int x = 1; x <= 1000000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000000, queue.Count());
}

// =====================================================
//
// =====================================================

TEST(ResizableQueue, EnqueueDequeueCount)
{
	ResizableQueue<int> queue;

	queue.Enqueue(100);
	queue.Enqueue(200);
	queue.Enqueue(300);

	EXPECT_EQ(3, queue.Count());
	EXPECT_EQ(100, queue.Dequeue());
	EXPECT_EQ(200, queue.Dequeue());
	EXPECT_EQ(300, queue.Dequeue());
}

TEST(ResizableQueue, Enqueue1000)
{
	ResizableQueue<int> queue;

	for (int x = 1; x <= 1000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000, queue.Count());
}

TEST(ResizableQueue, Enqueue100000)
{
	ResizableQueue<int> queue;

	for (int x = 1; x <= 100000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(100000, queue.Count());
}

TEST(ResizableQueue, Enqueue1000000)
{
	ResizableQueue<int> queue;

	for (int x = 1; x <= 1000000; x++)
		queue.Enqueue(x);

	EXPECT_EQ(1000000, queue.Count());
}