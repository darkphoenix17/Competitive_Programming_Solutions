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
	int lengthof(ListNode *head) {
		int cnt = 0;
		while (head != NULL) {
			cnt++;
			head = head->next;
		}
		return cnt;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int car = 0;
		int len1 = lengthof(l1);
		int len2 = lengthof(l2);
		if (len1 < len2) swap(l1, l2);
		ListNode* head = l1;
		//cout<<lengthof(l1)<<endl;
		ListNode* prev;
		while (l2 != NULL) {
			int a = l1->val;
			int b = l2->val;
			l1->val = (a + b + car) % 10;
			car = (a + b + car) / 10;
			prev = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			int a = l1->val;
			l1->val = (a + car) % 10;
			car = (a + car) / 10;
			prev = l1;
			l1 = l1->next;
		}
		if (car) {
			ListNode *t = new ListNode();
			prev->next = t;
			t->val = car;
		}
		return head;
	}
};