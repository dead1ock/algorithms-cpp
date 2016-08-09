/**
 *
 */

#include "QuickFind.h"

QuickFind::QuickFind(unsigned int numOfObjects)
	: mNumOfObjs(numOfObjects)
{
	mObjs = new unsigned int[numOfObjects];

	for (int x = 0; x < numOfObjects; x++)
		mObjs[x] = x;
}

QuickFind::~QuickFind()
{
	delete mObjs;
}

void QuickFind::Union(unsigned int p, unsigned int q)
{
	unsigned int pId = mObjs[p];
	unsigned int qId = mObjs[q];

	for (int x = 0; x < mNumOfObjs; x++)
	{
		if (mObjs[x] == pId)
			mObjs[x] = qId;
	}
}

bool QuickFind::Connected(unsigned int p, unsigned int q)
{
	return (mObjs[p] == mObjs[q]);
}