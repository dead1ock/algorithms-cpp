/*
 * Stack implementation using a fixed array backend.
 *
 * Pros:
 * Constant time push/pop operations.
 *
 * Cons:
 * Fixed capacity.
 *
 *
 * Notes:
 * This container is great for instances where you have a known capacity of entries and need
 * constant time push/pop operations.
 *
 * Memory Analysis: 4 + N
 */
template<typename T>
class FixedArrayStack
{
public:
	FixedArrayStack(unsigned int capacity)
		: mCount(0) {
		mObjs = new T[capacity];
	}

	~FixedArrayStack() {

	}

	/**
	* Runtime Analysis: O(1)
	*/
	void Push(T obj)
	{
		mObjs[mCount++] = obj;
	}

	/**
	* Runtime Analysis: O(1)
	*/
	T Pop()
	{
		return mObjs[--mCount];
	}

	unsigned int Count() { return mCount;  }

private:
	T* mObjs;				// Size: N
	unsigned int mCount;	// Size: 4
};