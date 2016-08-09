/**
 *
 */

class WeightedQuickUnion
{
public:
	WeightedQuickUnion(unsigned int numOfObjects);
	~WeightedQuickUnion();

	void Union(unsigned int p, unsigned int q);
	bool Connected(unsigned int p, unsigned int q);

private:
	unsigned int Find(unsigned int x);

	unsigned int* mObjs;
	unsigned int* mNumOfChildren;
	unsigned int mNumOfObjs;
};