#include <iostream>
using namespace std;
class TreeNode
{
private:
	string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(const string& t = string()) : value(t), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode& t) : value(t.value), count(t.count), left(t.left), right(t.right) { ++* count; }
	TreeNode& operator=(const TreeNode& t)
	{
		++* t.count;
		if (-- * count == 0)
		{
			if (left)
			{
				delete left;
				left = nullptr;
			}
			if (right)
			{
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
		value = t.value;
		count = t.count;
		left = t.left;
		right = t.right;
		return *this;
	}
	~TreeNode()
	{
		if (-- * count == 0)
		{
			if (left)
			{
				delete left;
				left = nullptr;
			}
			if (right)
			{
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
};
class BinStrTree
{
private:
	TreeNode* root;
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree& b) : root(b.root) {}
	BinStrTree& operator=(const BinStrTree& b)
	{
		auto t = b.root;
		delete root;
		root = t;
		return *this;
	}
	~BinStrTree()
	{
		delete root;
	}
};