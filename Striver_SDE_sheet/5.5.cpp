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
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode* tmp = node->next;
		node->next = tmp->next;
		delete(tmp);
	}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* curr = node;
		while (curr->next->next != nullptr) {
			curr->val = curr->next->val;
			curr = curr->next;
		}
		curr->val = curr->next->val;
		curr->next = nullptr;
	}
};