class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        return 1;
        int count =0;
        int result=0;
        while(n)
        {   
            int r=n%2;

            result +=(pow(2,count)*!r);
            count++;
            n=n/2;
        }
        return result;
    }
};