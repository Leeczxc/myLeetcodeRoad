#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *res = new ListNode();
    ListNode *ite = res;
    int rem = 0;
    ite->val = (l1->val + l2->val + rem) % 10;
    rem = (l1->val + l2->val + rem) / 10;
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != nullptr && l2 != nullptr)
    {
        ite->next = new ListNode( (l1->val + l2->val + rem) % 10);
        rem = (l1->val + l2->val + rem) / 10;
        ite = ite->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l2 != nullptr)
    {
        std::swap(l1, l2);
    }
    if (l1 != nullptr)
    {
        while (l1 != nullptr)
        {
            ite->next= new ListNode((l1->val + rem) % 10);
            rem = (l1->val + rem) / 10;
            ite = ite->next;
            l1 = l1->next;
        }
    }
    if (rem != 0)
    {
        ite->next = new ListNode(rem);
    }
    return res;
}