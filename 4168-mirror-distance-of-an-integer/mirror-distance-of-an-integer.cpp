class Solution {
public:
    int getreverse(int n)
    {
        int rev=0;
        while(n)
        {
        int N=n%10;
        rev=(rev*10)+N;
        n=n/10;
        }

        return rev;
    }
    int mirrorDistance(int n) {
        return abs(n-getreverse(n));
    }
};