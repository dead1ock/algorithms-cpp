/**
 *
 */

class QuickUnionPathCompression
{
public:
	QuickUnionPathCompression(unsigned int numOfObjects);
	~QuickUnionPathCompression();

	void Union(unsigned int p, unsigned int q);
	bool Connected(unsigned int p, unsigned int q);

private:
	unsigned int Find(unsigned int x);

	unsigned int* mObjs;
	unsigned int mNumOfObjs;

};