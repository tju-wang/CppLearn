#include <iostream>
using namespace std;


/*
�ݹ鷽ʽ�������ĺ������
*/

struct Tree {
	int val;
	struct Tree *left, *right;
};

void back(Tree *head);
int main()
{
	//Tree 

	return 0;
}

void back(Tree *head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->left)
		back(head->left);
	if (head->right)
		back(head->right);
	cout << head->val;

}

