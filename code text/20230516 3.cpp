//92. 反转链表 II/** * Definition for singly-linked list. * struct ListNode { *     int val; *     ListNode *next; *     ListNode() : val(0), next(nullptr) {} *     ListNode(int x) : val(x), next(nullptr) {} *     ListNode(int x, ListNode *next) : val(x), next(next) {} * }; */class Solution {public:    ListNode* reverseBetween(ListNode* head, int left, int right) {        ListNode *Node = new ListNode(-1);        Node->next = head;        ListNode *leftest = Node;        ListNode *righter = head;        if(left == right) return head;        for(int i = 1; i < left; i++){            leftest = leftest->next;            righter = righter->next;        }        for(int i = left; i < right; i++){            righter = righter->next;        }        ListNode *lefter = leftest->next;        ListNode *rightest = righter->next;        leftest->next = nullptr;        righter->next = nullptr;        //lefter,,,,righter        ListNode *prev = rightest;        while(lefter != nullptr){            ListNode *Next = lefter->next;            lefter->next = prev;            prev = lefter;            lefter = Next;        }        leftest->next = righter;        return Node->next;//为什么改了个这个就行了    }};