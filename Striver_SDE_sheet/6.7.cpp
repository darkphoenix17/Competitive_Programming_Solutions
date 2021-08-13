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
	ListNode* rotateRight(ListNode* head, int k) {
		//cout<<lengthof(head);
		ListNode *ans, *prev, *cur;
		int n = lengthof(head);
		if (n == 0 || n == 1) return head;
		k = k % n;
		n = n - k;
		if (k == 0) return head;
		cur = head;
		while (n--) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		ans = cur;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = head;
		return ans;
	}
};