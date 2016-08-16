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
void InsertionSort(T* in, unsigned int size) {
	int y = 0;
	T smaller;

	// For each item in the collection.
	for (int x = 0; x < size; x++)
	{
		y = x;

		// Check every item to the left until we find an item
		// we are greater than.
		while (y > 0)
		{
			// If we are less than the item to the left, swap.
			if (in[y] < in[y - 1]) {
				smaller = in[y];
				in[y] = in[y-1];
				in[y-1] = smaller;
				y--;
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