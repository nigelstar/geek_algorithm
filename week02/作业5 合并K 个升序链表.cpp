class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        return mergeKLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;
        ListNode* list1 = mergeKLists(lists, left, mid);
        ListNode* list2 = mergeKLists(lists, mid + 1, right);

        return mergeTwoLists(list1, list2);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        unique_ptr<ListNode> dummy = make_unique<ListNode>();
        ListNode* node = dummy.get();
        while ((list1 != nullptr) || (list2 != nullptr)) {
            if ((list2 == nullptr) || ((list1 != nullptr) && (list1->val <= list2->val))) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        return dummy->next;
    }
};