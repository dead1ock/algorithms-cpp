// Sorting Algorithms

/*
 * Runtime Analysis: O(N^2)
 */
template<typename T>
void SelectionSort(T* in, unsigned int size) {
	int smallestItemIndex;
	
	// For each item in the collection.
	for (int x = 0; x < size; x++)
	{
		smallestItemIndex = x;

		// Look to the right for the smallest item after it.
		for (int y = x + 1; y < size; y++)
		{
			// Set the new smallest pointer.
			if (in[y] < in[smallestItemIndex])
				smallestItemIndex = y;
		}

		// Swap the smallest found to the right with the current index.
		T temp = in[x];
		in[x] = in[smallestItemIndex];
		in[smallestItemIndex] = temp;
	}
}

/*
 * Runtime Analysis: O(N^2)
 */
template<typename T>
void InsertionSort(T* in, unsigned int size, unsigned int h = 1) {
	int y = 0;
	T smaller;

	// For each item in the collection.
	for (int x = 1; x < size; x += h)
	{
		y = x;

		// Check every item to the left until we find an item
		// we are greater than.
		while (y > 0)
		{
			// If we are less than the item to the left, swap.
			if (in[y] < in[y - h]) {
				smaller = in[y];
				in[y] = in[y - h];
				in[y - h] = smaller;
				y -= h;
			}
			// Otherwise continue to the right.
			else
				break;
		}
	}
}

/*
* Runtime Analysis: O(N)
*/
template<typename T>
void ShuffleSort(T* in, unsigned int size) {
	int randNum = 0;

	// For each item in the collection.
	for (int x = 1; x < size; x++)
	{
		// Generate a random number between 0 and x.
		randNum = rand() % x;

		// Swap current item with selected item.
		T swap = in[x];
		in[x] = in[randNum];
		in[randNum] = swap;
	}
}

/*
 * Runtime Complexity: O(N^(3/2) for 3x + 1 increments.
 */
template<typename T>
void ShellSort(T* in, unsigned int size) {
	int h = 1;

	while (h < (size / 3))
		h = 3 * h + 1; // 3x + 1 H-Sort increments.

	// H-Sort the array until we reach H=1.
	while (h >= 1)
	{
		InsertionSort(in, size, h);
		h = (h - 1)/3;
	}
}

/**
 * Partitions the input array into 3 sections. [<= pivot, pivot, > pivot]
 *
 * A pivot element is selected at the end of the array. Any element smaller than 
 * that element will reside on the left of the pivot, followed by the pivot, and then
 * the elements greater than the pivot.
 * 
 * Runtime Analysis: O(n)
 *
 * @param in The array to be partitioned.
 * @param size The length of the array.
 * @return The index of the pivot element.
 */
template<typename T>
unsigned int Partition(T* in, unsigned int size) {
	return Partition(in, 0, size - 1);
}

template<typename T>
unsigned int Partition(T* in, unsigned int start, unsigned int end) {
	// Set the pivot to the end of the array.
	T pivot = in[end];
	int i = start - 1;

	// From the start of the array, to the pivot.
	for (int j = start; j <= (end - 1); j++)
	{
		// If the element we are looking at is smaller than the pivot.
		if (in[j] <= pivot)
		{
			// Increment the current index.
			i++;

			// Exchange the pivot with the element we are looking at.
			T temp = in[i];
			in[i] = in[j];
			in[j] = temp;
		}
	}

	// Exchange the current index with the pivot.
	T temp = in[i+1];
	in[i+1] = in[end];
	in[end] = temp;

	// Return pivot position.
	return (i + 1);
}


/**
 * Sorts an array using the QuickSort algorithm.
 * 
 * Partitions the array @see Parition, then recursively sorts the left and right sub-arrays
 * holding the pivot fixed. Once each left and right sub-array has divided into problem sizes
 * of 1, all pivots are fixed in their correct positions and the array has been sorted.
 *
 * Runtime Analysis: O(n^2)
 *
 * @param in The array to be sorted.
 * @param size The length of the array.
 */
template<typename T>
void QuickSort(T* in, unsigned int size) {
	QuickSort(in, 0, size - 1);
}

template<typename T>
void QuickSort(T* in, unsigned int start, unsigned int end)
{
	// If we are not looking at an array of size 1.
	if (start < end) {
		// Partition the array.
		unsigned int pivot = Partition(in, start, end); // This is now in place, break the problem up again.

		// QuickSort elements to the left.
		QuickSort(in, start, pivot - 1);

		// QuickSort elements to the right.
		QuickSort(in, pivot + 1, end);
	}
}

/**
 * Takes an array and splits it into 2 sub-arrays (based on pivot position), then merges the contents
 * back together in ascending order.
 *
 * @param in The array to "merge"
 * @param start Where to start the merge operation on this array.
 * @param pivot The pivot where the array will be split into 2 sub-arrays. (Usually center is chosen).
 * @param end Where to end the merge operation on this array.
 */
template<typename T>
void Merge(T* in, unsigned int start, unsigned int pivot, unsigned int end)
{
	unsigned int size = (end + 1) - start;
	unsigned int i = start;
	unsigned int j = pivot + 1;
	unsigned int writeIndex = start;

	// Copy temporary array which will be used to compare
	// values for swapping.
	T* readArray = new T[size];
	memcpy(readArray, in, (start + size) * sizeof(T));

	while ((i <= pivot) && (j <= end))
	{
		if (readArray[i] <= readArray[j]) {
			in[writeIndex++] = readArray[i++];
		}
		else {
			in[writeIndex++] = readArray[j++];
		}
	}

	if (i > pivot)
	{
		// copy rest of second array
		memcpy(in + writeIndex, readArray + j, ((end + 1) - j) * sizeof(T));
	}
	else if (j > end)
	{
		// copy rest of first array
		memcpy(in + writeIndex, readArray + i, ((pivot + 1) - i) * sizeof(T));
	}

	//delete[] readArray; Causes exception?
}

/**
 * Sorts an array using the Merge Sort algorithm.
 *
 * DIVIDE: Divides the input sub-array recursively by n/2 until the size of
 * sub-array is equal to 1 (sorted).
 *
 * CONQUER: Invokes Merge() on each sorted sub-array while unwinding the stack,
 * merging the contents of each sorted sub-array back into the original array.
 *
 * COMBINE: The result is a sorted array.
 *
 * This is not an in-place sort and requires 2N memory!
 *
 * Runtime Analysis: O(n log(n))
 * Memory Consumption: O(2n)
 */
template<typename T>
void MergeSort(T* in, unsigned int start, unsigned int end)
{
	if (start < end)
	{
		int center = floor((start + end) / 2);
		MergeSort(in, start, center);
		MergeSort(in, center+1, end);
		Merge(in, start, center, end);
	}
}

template<typename T>
void MergeSort(T* in, unsigned int size)
{
	MergeSort(in, 0, size - 1);
}