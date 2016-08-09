/**
 *
 */

#include "WeightedQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(unsigned int numOfObjects)
	: mNumOfObjs(numOfObjects)
{
	mObjs = new unsigned int[mNumOfObjs];
	mNumOfChildren = new unsigned int[mNumOfObjs];

	for (int x = 0; x < mNumOfObjs; x++)
	{
		mObjs[x] = x;
	}

	for (int x = 0; x < mNumOfObjs; x++)
	{
		mNumOfChildren[x] = 1; // A node is considered a child of itself.
	}
}

WeightedQuickUnion::~WeightedQuickUnion()
{
	delete mObjs;
	delete mNumOfChildren;
}

void WeightedQuickUnion::Union(unsigned int p, unsigned int q)
{
	unsigned int pRoot = Find(p);
	unsigned int qRoot = Find(q);
	if (mNumOfChildren[pRoot] > mNumOfChildren[qRoot]) {
		mObjs[qRoot] = pRoot;
		mNumOfChildren[pRoot] += mNumOfChildren[qRoot];
	}
	else {
		mObjs[pRoot] = qRoot;
		mNumOfChildren[qRoot] += mNumOfChildren[pRoot];
	}
}

bool WeightedQuickUnion::Connected(unsigned int p, unsigned int q)
{
	return (Find(p) == Find(q));
}

unsigned int WeightedQuickUnion::Find(unsigned int x)
{
	unsigned int xId = mObjs[x];
	if (xId == x)
		return xId;
	else
		return Find(xId);
}