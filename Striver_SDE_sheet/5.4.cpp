/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	int lengthofNode(ListNode* head) {
		int len = 0;
		while (head != NULL) {
			head = head->next;
			len++;
		}
		return len;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int cnt = lengthofNode(head) - n;
		ListNode *tmp, *cur;
		if (cnt == 0) {
			if (lengthofNode(head) == 1) {
				delete(head);
				return NULL;
			}
			else {
				cur = head->next;
				delete(head);
				return cur;
			}

		}
		cur = head;
		while (cnt > 1) {
			//cout<<cur->val;
			cur = cur->next;
			cnt--;
		}
		tmp = cur->next;
		cur->next = tmp->next;
		delete(tmp);
		return head;
	}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode * start = new ListNode();
		start -> next = head;
		ListNode* fast = start;
		ListNode* slow = start;

		for (int i = 1; i <= n; ++i)
			fast = fast->next;

		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = slow->next->next;
		delete(fast);
		return head;
	}
};