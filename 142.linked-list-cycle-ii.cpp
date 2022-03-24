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
        // 1. setting fast = 2slow. if not meet, no circle, return
        // 2. if meet, have circle, set fast = slow, when meet, at the start of circle
        ListNode *fast = head, *slow = head;
        do
        {

            if (fast == nullptr or fast->next == nullptr)
                // 01 make sure fast = fast->next->next make sense;
                // 02 one situation result;
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
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
