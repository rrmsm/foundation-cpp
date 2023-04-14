/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
 输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *bbb = new ListNode(-1);
        bbb->next = head;
        ListNode *pre = bbb;
        ListNode *cur = head;
        while(cur && cur->next){
            if(cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val){
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur = cur->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return bbb->next;
    }
};