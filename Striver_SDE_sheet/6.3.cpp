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

//for ref: https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k == 1) return head;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode* cur = dummy, *prev = dummy, *nex = dummy;
		int cnt = 0;
		while (cur->next != NULL) {
			cur = cur->next;
			cnt++;
		}
		//cout<<cnt<<" ";
		while (cnt >= k) {
			cur = prev->next;
			nex = cur->next;
			for (int i = 1; i < k; i++) {
				cur->next = nex->next;
				nex->next = prev->next;
				prev->next = nex;
				nex = cur->next;
			}
			//cout<<prev->val<<" ";
			prev = cur;
			cnt -= k;
		}
		return dummy->next;
	}
};