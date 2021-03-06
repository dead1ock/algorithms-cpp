
/*
 * Stack implemented using a Linked List backend.
 *
 * Pros:
 * Constant time push/pop operations.
 *
 * Cons:
 * Large extra memory footprint due to Nodes.
 * Large number of new operations called which will effect performance.
 *
 * Notes:
 * 
 * 
 * Memory Analysis: 4 + (8 * sizeof(T) * N)
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
	* Runtime Analysis: O(1)
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
	* Runtime Analysis: O(1)
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