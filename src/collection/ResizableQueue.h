/**
* Queue implementation using a dynamically allocated array.
*
* Pros:
* Enqueue/Dequeue operations run in amortized constant time.
* No fixed capacity.
*
* Cons:
* 
*
* Notes:
* 
*
* Memory Analysis: N + 20;
*/

template<typename T>
class ResizableQueue
{
public:
	ResizableQueue()
		: mHead(0),
		mTail(0),
		mCount(0) {
		mItems = new T[2];
		mCapacity = 2;
	}

	~ResizableQueue() {

	}

	/*
	* Runtime Analysis: O(1) Amortized
	*/
	void Enqueue(T item) {
		if (mCount == mCapacity) {
			Resize(mCapacity * 2);
		}

		mItems[mTail++] = item;

		if (mTail > mCapacity)
			mTail = 0;

		mCount++;
	}

	/*
	* Runtime Analysis: O(1) Amortized
	*/
	T Dequeue() {
		T item = mItems[mHead++];

		if (mHead >= mCapacity)
			mHead = 0;

		if (mCount <= (mCapacity / 4))
			Resize(mCapacity / 2);

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
	
	void Resize(unsigned int newCapacity) {
		T* newArray = new T[newCapacity];
		
		for (int x = 0; x < mCount; x++)
		{
			newArray[x] = mItems[mHead++];
			if (mHead >= mCapacity)
				mHead = 0;
		}

		delete[] mItems;

		mHead = 0;
		mTail = mCapacity;
		mCapacity = newCapacity;
		mItems = newArray;
	}

	T* mItems;
	unsigned int mCapacity;
	unsigned int mCount;
	unsigned int mHead;
	unsigned int mTail;

};