/**
* Queue implementation using fixed-size array.
*
* Pros:
* Enqueue/Dequeue operations run in constant time.
* Low, predictable memory footprint.
*
* Cons:
* Fixed size.
*
* Notes:
* A great container to use if you have a fixed queue length and want constant time performance.
*
* Memory Analysis: 8N + 16;
*/

template<typename T>
class FixedQueue
{
public:
	FixedQueue(unsigned int capacity)
	: mCapacity(capacity),
	mHead(0),
	mTail(0),
	mCount(0) {
		mItems = new T[capacity];
	}

	~FixedQueue() {

	}

	/*
	 * Runtime Analysis: O(1)
	 */
	void Enqueue(T item) {
		if (mCount == mCapacity) // Overflow, simply ignore.
			return;

		mItems[mTail++] = item;
		mCount++;
		
		if (mTail >= mCapacity)
			mTail = 0;
	}

	/*
	* Runtime Analysis: O(1)
	*/
	T Dequeue() {
		T obj = mItems[mHead++];
		if (mHead >= mCapacity)
			mHead = 0;
		mCount--;
		return obj;
	}

	/*
	* Runtime Analysis: O(1)
	*/
	unsigned int Count() {
		return mCount;
	}

private:
	T* mItems;
	unsigned int mCapacity;
	unsigned int mCount;
	unsigned int mHead;
	unsigned int mTail;

};