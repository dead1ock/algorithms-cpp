/**
* Queue implementation using a linked list.
*
* Pros:
* Enqueue/Dequeue operations run in constant time.
* No fixed capacity.
*
* Cons:
* High memory footprint.
*
* Notes:
* A great container to use when you need a resizable queue for a small to moderate amount of entries.
*
* Memory Analysis: 8N + 16;
*/

template<typename T>
class LinkedQueue
{
public:
	LinkedQueue()
		: mHead(nullptr),
		mTail(nullptr),
		mCount(0) {
		
	}

	~LinkedQueue() {

	}

	/*
	* Runtime Analysis: O(1)
	*/
	void Enqueue(T item) {
		Node* newTail = new Node(item);

		if (mHead == nullptr && mTail == nullptr) { // First Enqueue
			mHead = newTail;
			mTail = newTail;
		}
		else {
			mTail->next = newTail;
			mTail = newTail;
		}

		mCount++;
	}

	/*
	* Runtime Analysis: O(1)
	*/
	T Dequeue() {
		T item = mHead->item;
		Node* oldHead = mHead;

		mHead = mHead->next;
		delete oldHead;

		mCount--;
		return item;
	}

	/*
	* Runtime Analysis: O(1)
	*/
	unsigned int Count() {
		return mCount;
	}

private:
	struct Node
	{
		Node(T _item) {
			item = _item;
			next = nullptr;
		}

		T item;
		Node* next;
	};

	Node* mHead;
	Node* mTail;
	unsigned int mCount;

};