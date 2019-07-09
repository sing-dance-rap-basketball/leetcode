#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *unsorted = head->next;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head->next = nullptr;
        while (unsorted != nullptr) {
            ListNode *temp = unsorted;
            unsorted = unsorted->next;
            ListNode *p = dummy;
            for (; (p->next) && temp->val > p->next->val; ) {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
        return dummy->next;
    }
};

int main()
{
    std::vector<int> list{4,2,1,3};
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;
    for (int i = 0; i < list.size(); ++i, p = p->next) {
        p->next = new ListNode(list[i]);
    }
    p->next = nullptr;

    Solution s;
    s.insertionSortList(dummy->next);

    return 0;
}