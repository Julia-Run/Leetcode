/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // size >= 0; two pointers
        // no cycle, return nullptr
        ListNode *fast = head, *slow = head;
        do
        {
            if (fast == nullptr || fast->next == nullptr)
            { // in case head = nullptr;
              // && make sure fast = fast->next->next; make sense;
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        // fast = slow;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end
