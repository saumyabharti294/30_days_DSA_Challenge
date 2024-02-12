/*
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/




class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      //declaring a vector where we will store all the value in lists
        vector<int> n;

        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            while(temp!=NULL)
            {
                n.push_back(temp->val);
                temp=temp->next;
            }

        }
      //step 2 : Then we will sort the vector    
        sort(n.begin(),n.end());
      
     //step 3 : declaring a listnode as we have return the sorted listnode after merging all k lists values
        ListNode* ans=new ListNode(-1);
        ListNode* f=ans;
        for(int i=0;i<n.size();i++)
        {
           
            ListNode* temp=new ListNode(n[i]);
            f->next=temp;
            f=f->next;
        }
       
        return ans->next;
    }
};
