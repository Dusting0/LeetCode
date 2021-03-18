#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *empty_head = new ListNode;
        ListNode *wait_head = new ListNode;
        empty_head->next = head;
        ListNode *head_ptr, *cur_ptr, *tail_ptr, *wait_tail;
        head_ptr = empty_head;
        cur_ptr = empty_head->next;
        tail_ptr = empty_head->next;
        wait_tail = wait_head;

        int cnt = 1;
        while(cnt<=right) {
            if(cnt >= left) {
                tail_ptr = tail_ptr->next;
                head_ptr->next = tail_ptr;

                //反插
                cur_ptr->next = wait_head->next;
                wait_head->next = cur_ptr;
                if(cur_ptr->next == NULL) {
                    wait_tail = cur_ptr;
                }

                cur_ptr = tail_ptr;
            } else {
                head_ptr = head_ptr->next;
                cur_ptr = cur_ptr->next;
                tail_ptr = tail_ptr->next;
            }
            cnt ++;
        }

        head_ptr->next = wait_head->next;
        wait_tail->next = tail_ptr;
        return empty_head->next;
    }
};