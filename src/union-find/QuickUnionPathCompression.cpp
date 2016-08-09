/**
 *
 */

#include "QuickUnionPathCompression.h"

QuickUnionPathCompression::QuickUnionPathCompression(unsigned int numOfObjects)
	: mNumOfObjs(numOfObjects)
{
	mObjs = new unsigned int[numOfObjects];

	// Make all objects roots.
	for (int x = 0; x < numOfObjects; x++)
	{
		mObjs[x] = x;
	}
}

QuickUnionPathCompression::~QuickUnionPathCompression()
{
	delete mObjs;
}

void QuickUnionPathCompression::Union(unsigned int p, unsigned int q)
{
	unsigned int pRoot = Find(p);
	unsigned int qRoot = Find(q);
	mObjs[qRoot] = pRoot;
}

bool QuickUnionPathCompression::Connected(unsigned int p, unsigned int q)
{
	return (Find(p) == Find(q));
}

unsigned int QuickUnionPathCompression::Find(unsigned int x)
{
	unsigned int rootId = mObjs[x];
	while (rootId != mObjs[rootId])
		rootId = mObjs[rootId];

	while (x != rootId) {
		unsigned int nextId = mObjs[rootId];
		mObjs[x] = rootId;
		x = nextId;
	}

	return rootId;
}