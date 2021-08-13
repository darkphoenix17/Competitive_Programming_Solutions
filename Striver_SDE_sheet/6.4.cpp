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
    ListNode* reverselist(ListNode *head) {
        ListNode*prev, *nex;
        prev = nex = NULL;
        while (head != NULL) {
            nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* slow, *fast;
        slow = fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverselist(slow->next);
        slow = slow->next;

        while (slow != NULL) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;
        int cnt = 0;
        while (cur != NULL) {
            cnt++;
            v.push_back(cur->val);
            cur = cur->next;
        }
        int n = v.size();
        for (int i = 0; i < n / 2; i++) {
            if (v[i] != v[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};