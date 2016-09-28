// Heap Algorithms

#include <cmath>

//
// MAX HEAP ALGORITHMS
//

/**
 * Calculates parent index.
 *
 * @param i The node we want the parent of.
 * @return Index to the parent node.
 */
int parent(int index) {
	return floor((index - 1) / 2);
}

/**
 * Calculates the left child.
 *
 * @param i The node we want the left child of.
 * @return The index of the left child.
 */
int left(int index) {
	return (2 * index) + 1;
}

/**
 * Calculates the right child.
 *
 * @param i The node we want the right child of.
 * @return The index of the right child.
 */
int right(int index) {
	return (2 * index) + 2;
}

/**
 * Determines if a left or right child of the specified node
 * is smaller, if so: swap the node with its left or right child, and then
 * call recursively on the swapped node. (Maintains max-heap property.)
 *
 * Runtime Analysis: O(log(n))
 */
template<typename T>
void MaxHeapify(T* a, int i, int len) {
	int l = left(i);
	int r = right(i);
	int largest = i;

	if ((l < len) && (a[l] > a[i]))
		largest = l;
	else
		largest = i;

	if ((r < len) && (a[r] > a[largest]))
		largest = r;

	if (largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		MaxHeapify(a, largest, len);
	}
}

/**
 * Takes an unordered array of T and constructs
 * a MAX-HEAP.
 *
 * Runtime Analysis: O(log(n))
 *
 * @param a The array to order MAX-HEAP.
 * @param size The size of the input array.
 */
template<typename T>
void BuildMaxHeap(T* a, int size) {
	for (int i = floor((size - 1) / 2); i >= 0; i--)
		MaxHeapify(a, i, size);
}

/**
 * Sorts an array using the Heap Sort Algorithm.
 *
 * Runtime Analysis: O(n log(n))
 */
template<typename T>
void HeapSort(T* a, int size) {
	BuildMaxHeap(a, size);
	for (int i = size - 1; i >= 1; i--)
	{
		T temp = a[i];
		a[i] = a[0];
		a[0] = temp;

		size--;

		MaxHeapify(a, 0, size);
	}
}

/**
 * Returns the element in the heap with the largest key.
 *
 * Runtime Analysis: O(1)
 *
 * @param a The heap to use.
 * @param size The size of the heap.
 * @return The element with the largest key in the heap.
 */
template<typename T>
T HeapMaximum(T* a, int size) {
	if (size > 0)
		return a[0];
	else
		return NULL;
}

/**
 * Extracts the maximum element from the top of the heap, then
 * maintains the heap property by places the bottom most element
 * on the top of the heap, then invoking Max Heapify.
 *
 * Runtime Analysis: O(log n)
 *
 * @param a The heap to extract the maximum from.
 * @param size The size of the heap. This paramater will be decremented to reflect the new
 * size of the heap.
 * @return The element with the largest key in the heap.
 */
template<typename T>
T HeapExtractMax(T* a, int& size) {
	if (size < 1)
		return NULL;

	T max = a[0];
	a[0] = a[size - 1];
	size--;

	MaxHeapify(a, 0, size);
	return max;
}

/**
 * 
 *
 * Runtime Analysis: O(log n)
 *
 * @param a The heap.
 * @param size The size of the heap.
 * @param index The node we want to "bubble up."
 * Runtime Analysis: O(log n)
 */
template<typename T>
void HeapIncreaseKey(T* a, int size, int index, T key) {
	if (0 >= index || index >= size || a[index] > key)
		return;

	a[index] = key;

	while ((parent(index) >= 0) && (a[index] > a[parent(index)]))
	{
		// Exchange
		T temp = a[parent(index)];
		a[parent(index)] = a[index];
		a[index] = temp;

		index = parent(index);
	}
}

/**
* Increases the heap size by 1, then inserts
* the new key on the bottom of the heap and bubbles up the
* node (using HeapIncreaseKey).
*
* Runtime Analysis: O(log n)
*
* @param a The heap.
* @param size The size of the heap. This will be incremented by 1.
* @param newKey The new key inserted into the heap.
* @return A pointer to the new heap memory block.
*/
template<typename T>
T* MaxHeapInsert(T* a, int& size, T newKey) {
	// Expand input array.
	T* newMemory = new T[++size];
	memcpy(newMemory, a, size * sizeof(T));
	a = newMemory;

	// Preserve heap property.
	a[size - 1] = -INFINITY;

	// Insert new key and bubble up.
	HeapIncreaseKey(a, size, size - 1, newKey);
	return a;
}

