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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
		return head;
    ListNode *cur = head;
    int count = 1;
    while( cur->next != nullptr){
    	count++;
    	cur = cur->next;
	}
	k = k % count;
	if(k == 0)
		return head;
	int step = count - k - 1;
	cur->next = head;
	ListNode* newTail = head;
	while(step--){
		newTail = newTail->next;
	}
	ListNode *newHead = newTail->next;
	newTail->next = nullptr;
	return newHead;  
    }
};