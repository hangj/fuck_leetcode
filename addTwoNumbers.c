// 2. 两数相加
// https://leetcode-cn.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    int carry = 0;
    for(; p1->next && p2->next; p1=p1->next, p2=p2->next){
        int sum = p1->val + p2->val + carry;
        p1->val = sum % 10;
        carry = sum / 10;
    }

    int sum = p1->val + p2->val + carry;
    p1->val = sum % 10;
    carry = sum / 10;

    if(!p1->next) p1->next = p2->next;

    while(p1->next && carry > 0){
        p1 = p1->next;

        int sum = p1->val + carry;
        p1->val = sum % 10;
        carry = sum / 10;
    }

    if(carry > 0){
        p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p1->next->val = carry;
        p1->next->next = NULL;
    }

    return l1;
}
