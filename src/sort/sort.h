// Sorting Algorithms

/*
 * Runtime Analysis: O(N^2)
 */
template<typename T>
void SelectionSort(T* in, unsigned int size) {
	T* smallest;
	
	for (int x = 0; x < size; x++)
	{
		smallest = &in[x];
		for (int y = x + 1; y < size; y++)
		{
			if (in[y] < *smallest)
				smallest = &in[y];
		}

		in[x] = *smallest;
		*smallest = in[x];
	}
}