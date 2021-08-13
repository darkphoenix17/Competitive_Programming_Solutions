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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *t1, *t2;
		bool check1 = true, check2 = true;
		t1 = headA;
		t2 = headB;
		int f = 0;
		while (t1 != NULL || t2 != NULL) {
			if (t1 == NULL) {
				t1 = check1 ? headB : headA;
				check1 = check1 ? false : true;
			}
			if (t2 == NULL) {
				t2 = check2 ? headA : headB;
				check2 = check2 ? false : true;
			}
			if (t1 == t2) {
				f = 1;
				break;
			}
			t1 = t1->next;
			t2 = t2->next;
		}
		if (f) return t1;
		else return nullptr;

	}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode *> st;
		ListNode *t;
		t = headA;
		while (t != NULL) {
			st.insert(t);
			t = t->next;
		}
		t = headB;
		int f = 0;
		while (t != NULL) {
			if (st.find(t) != st.end()) {
				f = 1;
				break;
			}
			t = t->next;
		}
		if (f) return t;
		else return nullptr;
	}
};