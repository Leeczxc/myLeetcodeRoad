struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* flip(ListNode* l1){
    ListNode* ite = nullptr;
    ListNode* head = nullptr;
    while(l1->next != nullptr){
        ite = l1->next;
        l1->next = ite->next;
        ite->next = head;
        head = ite;
    }
    ite = head;
    while(ite ->next != nullptr){
        ite = ite->next;
    }
    ite->next = l1;
    return head;
}