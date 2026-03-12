class Solution {
public:
    int concatenatedBinary(int n) {
        int M=1e9+7;
        long result=0;
        int digit=0;
        for(int num=1;num<=n;num++)
        {
          digit=log2(num)+1;
          result=((result<<digit)%M+num)%M;
        }
        return result;
    }
};