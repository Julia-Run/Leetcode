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
        ListNode *fast = head, *slow = head;
        // while (fast != slow)
        // {
        // fast,slow refers to head at the fitst beginning
        //     if (!fast || !fast->next)
        //         return nullptr;
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }
        do
        {
            // do it once at the first beginning
            // this time: don't have to satisfy fast!=slow;
            if (!fast || !fast->next)
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
