//19. 删除链表的倒数第 N 个结点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head | !head -> next) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }
        if(!fast){//这是只有一个指针的时候要注意的
            return head->next;//相当于不要了第一个节点！！
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};