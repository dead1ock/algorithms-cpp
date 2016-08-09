
#include <gtest/gtest.h>

#include "union-find/QuickFind.h"
#include "union-find/QuickUnionPathCompression.h"
#include "union-find/WeightedQuickUnion.h"

TEST(QuickFind, Connected) {
	QuickFind uf(10);

	uf.Union(1, 9);
	uf.Union(2, 8);
	uf.Union(2, 9);

	EXPECT_EQ(true, uf.Connected(1, 8));
	EXPECT_EQ(false, uf.Connected(9, 4));
}

TEST(QuickUnionPathCompression, Connected)
{
	QuickUnionPathCompression uf(10);

	uf.Union(1, 9);
	uf.Union(2, 8);
	uf.Union(2, 9);

	EXPECT_EQ(true, uf.Connected(1, 8));
	EXPECT_EQ(false, uf.Connected(9, 4));
}

TEST(WeightedQuickUnion, Connected)
{
	WeightedQuickUnion uf(10);

	uf.Union(1, 9);
	uf.Union(2, 8);
	uf.Union(2, 9);

	EXPECT_EQ(true, uf.Connected(1, 8));
	EXPECT_EQ(false, uf.Connected(9, 4));
}