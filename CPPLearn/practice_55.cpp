#include <iostream>
using namespace std;





/*
����һ��������������������е�����k����㣬����ĵ�����1�����Ϊ�����βָ�롣
*/

struct ListNode
{
	int val;
	ListNode *next = NULL;
};

int main()
{

	int num;
	while (cin >> num)
	{
		cin.ignore();
		ListNode *head = new ListNode;
		ListNode *q = head;
		for (int i = 0; i < num; ++i)
		{
			ListNode *p = new ListNode;
			int tmp;
			cin >> tmp;
			p->val = tmp;
			q->next = p;
			q = q->next;
		}
		//�ҵ�����k�����
		cin.ignore();
		int k = 0;
		cin >> k;
		if (k == 0 || k>num)
			cout << 0 << endl;
		else
		{
			q = head->next;
			ListNode *p = q;
			for (int i = 0; i < k; ++i)
				q = q->next;
			while (q)
			{
				p = p->next;
				q = q->next;
			}
			cout << p->val << endl;
		}
		
	}
	
		

	return 0;
}