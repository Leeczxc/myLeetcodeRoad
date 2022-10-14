//
// Created by Lee on 2022/9/23.
//

#ifndef LEETCODE_LINKEDLIST707_H
#define LEETCODE_LINKEDLIST707_H
class MyLinkedList{
public:
    int val;
    MyLinkedList* prev;
    MyLinkedList* next;
    MyLinkedList() {
        prev = nullptr;
        next = nullptr;
    }

    int get(int index){
        MyLinkedList* head = this;
        while(head != nullptr){
            if(index > 0){
                head = head->next;
                index--;
            } else
                break;
        }
        if(head == nullptr)
            return -1;
        return head->val;
    }

    void addAtHead(int val) {
        MyLinkedList* insert = new MyLinkedList();
        insert->val = val;
        if(this->next != nullptr){
            insert->next = this->next;
            this->next->prev = insert;
        }
        this->next = insert;
        insert->prev = this;
    }

    void addAtTail(int val) {
        MyLinkedList* head = this;
        while(head->next != nullptr)
            head = head->next;
        MyLinkedList* insert = new MyLinkedList();
        insert->val = val;
        head->next = insert;
        insert->prev = head;
    }

    void addAtIndex(int index, int val){
        MyLinkedList* head = this;
        while(head != nullptr){
            if(index > 0){
                index--;
                head = head->next;
            }
            else
                break;
        }
        if(index == 0){
            if(head == nullptr){
                addAtTail(val);
            }else{
                MyLinkedList* insert = new MyLinkedList();
                insert->val = val;
                head->prev->next = insert;
                insert->next = head;
                head->prev = insert;
            }
        }
    }

    void deleteAtIndex(int index) {
        MyLinkedList* head = this;
        while(head != nullptr){
            if(index > 0){
                index--;
                head = head->next;
            }
            else
                break;
        }
        if(head == 0) {
            head->prev->next = head->next;
            if(head->next != nullptr)
                head->next->prev = head->prev;
            delete(head);
        }
    }
};
#endif //LEETCODE_LINKEDLIST707_H
