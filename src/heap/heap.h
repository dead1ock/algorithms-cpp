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
	return floor(index / 2);
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

	if ((l <= len) && (a[l] > a[i]))
		largest = l;
	else
		largest = i;

	if ((r <= len) && (a[r] > a[largest]))
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
 * @param a The array to order MAX-HEAP.
 * @param size The size of the input array.
 */
template<typename T>
void BuildMaxHeap(T* a, int size) {
	for (int i = floor((size - 1) / 2); i >= 0; i--)
		MaxHeapify(a, i, size);
}