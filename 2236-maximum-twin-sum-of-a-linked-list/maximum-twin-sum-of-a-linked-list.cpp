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
    int pairSum(ListNode* head) {
        vector<int>arr;
        //iterate through the linked list add value to array

        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
        }

        //[5 4 2 1]

        int i=0;
        int j=arr.size()-1;

        int twinsum=INT_MIN;

        while(i<j)
        {
            int sum=arr[i]+arr[j];
            twinsum=max(twinsum,sum);
            i++;
            j--;
        }
        return twinsum;
    }
};