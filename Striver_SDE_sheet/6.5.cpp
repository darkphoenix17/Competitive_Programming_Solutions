/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow, *fast;
		slow = fast = head;
		if (head == NULL || head->next == NULL || head->next->next == NULL) return nullptr;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) {
				break;
			}
		}
		if (fast == NULL || fast->next == NULL) {
			return nullptr;
		}
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};