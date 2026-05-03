class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1;
        int start=0;
        int end=0;
        int count=0;
        int n=nums.size();

        while(end<n)
        {
            product *=nums[end];

            while(product>=k && start <=end)
            {
                product /=nums[start];
                start++;
            }
            count +=end-start+1;
            end++;
        }
        return count;
    }
};