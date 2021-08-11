class Solution {
public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
                if (l1 == NULL) return l2;
                if (l2 == NULL) return l1;
                if (l1->val > l2->val) std::swap(l1, l2);
                ListNode * res = l1;
                while (l1 != NULL && l2 != NULL) {
                        ListNode *tmp = NULL;
                        while (l1 != NULL && l1->val <= l2->val) {
                                l1 = l1->next;
                                tmp = l1;
                        }
                        tmp->next = l2;
                        std::swap(l1, l2);
                }
                return res;
        }
};

class Solution {
public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

                ListNode* result = NULL;

                if (l1 == NULL) return l2;
                else if (l2 == NULL) return l1;
                else if (l1->val >= l2->val)
                        result = l2, result->next = mergeTwoLists(l1, l2->next);

                else if (l1->val < l2->val)
                        result = l1 , result->next = mergeTwoLists(l1->next, l2);
                return result;

        }
};
