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
	ListNode* lastptr = nullptr;
	void reverse(ListNode* cur, ListNode* prev) {
		if (cur->next == nullptr) {
			cur->next = prev;
			lastptr = cur;
			return;
		}
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		reverse(temp, prev);
	}
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return head;
		reverse(head, nullptr);
		return lastptr;
	}
};