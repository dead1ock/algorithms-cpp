
/*
 * Stack implemented using a Linked List backend.
 */
template<typename T>
class LinkedListStack
{
public:
	LinkedListStack()
	{
		mRootNode = nullptr;
		mNodeCount = 0;
	}

	~LinkedListStack()
	{ }

	/**
	 * Algorithmic Complexity: 1
	 */
	void Push(T obj)
	{
		Node* lastRoot = mRootNode;
		mRootNode = new Node();
		mRootNode->mObj = obj;
		mRootNode->mNext = lastRoot;
		mNodeCount++;
	}

	/**
	 * Algorithmic Complexity: 1
	 */
	T Pop()
	{
		Node* lastRoot = mRootNode;
		T obj = lastRoot->mObj;
		mRootNode = lastRoot->mNext;
		mNodeCount--;
		delete lastRoot;
		return obj;
	}

	unsigned int Count() { return mNodeCount; }

private:
	struct Node
	{
		T mObj;
		Node* mNext;
	};

	Node* mRootNode;
	unsigned int mNodeCount;
};