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

//solution code starts here

class Solution {
public:
int carry=0;
int sum=0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;

        ListNode*ans=new ListNode(0);
        ListNode*temp=ans;
        ListNode*t1=l1;
        ListNode*t2=l2;

        int d1;
        int d2;

        while(t1!=NULL || t2!=NULL)
        {
              d1=(t1!=NULL)?t1->val:0;
              d2=(t2!=NULL)?t2->val:0;

              this->sum=(d1+d2+this->carry)%10;
               temp->next=new ListNode(this->sum);
               temp=temp->next;
               this->carry=(d1+d2+this->carry)/10;

               if(t1!=NULL)t1=t1->next;
               if(t2!=NULL)t2=t2->next;

        }
        if(this->carry!=0)
        {
            temp->next=new ListNode(this->carry);
            temp=temp->next;
        }
        temp->next=NULL;
        return ans->next;
    }
};

