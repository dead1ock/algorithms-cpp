/**
 *
 */

class QuickFind
{
public:
	/*
	 * Algorithmic Complexity: N
	 */
	QuickFind(unsigned int numberOfObjects);
	~QuickFind();

	/*
	 * Algorithmic Complexity: N
	 */
	void Union(unsigned int p, unsigned int q);

	/*
	 * Algorithmic Complexity: 1
	 */
	bool Connected(unsigned int p, unsigned int q);

private:
	unsigned int* mObjs;
	unsigned int mNumOfObjs;
};