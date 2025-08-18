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
       ListNode* temp=head;
       int count=0;
       if(head==nullptr)return head;

       while(temp!=nullptr){count++;temp=temp->next;}
       k%=count;
       
       if(k==0)return head;
       temp=head;
       for(int i=1;i<count-k;i++){
        temp=temp->next;
       }
       ListNode* ki=temp->next;
       ListNode* ans=ki;
       temp->next=nullptr;
       while(ki->next!=nullptr)ki=ki->next;
       ki->next=head;
       return ans;
    
    }
};