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
        // 01. fast = 2vt = x+c + fy, slow = vt = x+ c+sy
        // -- vt = (f-s)y = x+c+sy -- slow current: x+c = ky
        // 02. fast = vt -- fact to x, slow to x+c+x = x + ky, meet
        ListNode *fast = head, *slow = head;
        do
        {
            if (fast == nullptr || fast->next == nullptr)
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
