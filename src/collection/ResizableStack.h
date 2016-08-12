
/**
 * Stack implementation using resizable array.
 *
 * Pros:
 * Amortized constant time push/pop operations, resizable capacity.
 *
 * Cons:
 * Reallocation time can be significant if frequently pushing and popping a small set of objects.
 * Wasted memory if the number of entries straddles the lower end of the current capacity.
 * 
 *
 * Notes:
 * This type of container is great for applications where you anticipate a large number of objects but need a resizable capacity. 
 * If you need guarunteed constant time push/pop operations and a flexible capacity, see LinkedListStack.
 *
 * Memory Analysis: 8 + (sizeof(T) * N)
 */
template<typename T>
class ResizableStack
{
public:
	ResizableStack()
	{
		mObjs = new T[2];
		mCurrentCapacity = 2;
		mCount = 0;
	}

	~ResizableStack()
	{

	}

	/**
	 * Runtime Analysis: Amortized O(1)
	 */
	void Push(T obj)
	{
		if (mCount >= mCurrentCapacity)
			Resize(mCurrentCapacity * 2);

		mObjs[mCount++] = obj;
	}

	/**
	 * Runtime Analysis: Amortized O(1)
	 */
	T Pop()
	{
		T obj = mObjs[--mCount];

		if (mCount < (mCurrentCapacity / 4))
			Resize(mCurrentCapacity / 4);

		return obj;
	}

	unsigned int Count() { return mCount; }

private:

	/**
	 * Runtime Analysis: O(N)
	 */
	void Resize(unsigned int capacity)
	{
		T* newObjs = new T[capacity];
		
		for (unsigned int x = 0; x < mCount; x++)
			newObjs[x] = mObjs[x];

		delete[] mObjs;
		mCurrentCapacity = capacity;
		mObjs = newObjs;
	}

	T* mObjs;
	unsigned int mCount;
	unsigned int mCurrentCapacity;
};