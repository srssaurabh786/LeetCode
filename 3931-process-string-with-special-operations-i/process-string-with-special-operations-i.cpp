class Solution {
public:
    string processStr(string s) {
        string result="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
         if(s[i]=='*')
         {
            if(result.length()>0)
            result.pop_back();
         }
         else if(s[i] =='#')
         {
            result+=result;
         }
         else if(s[i]=='%')
         {
         reverse(begin(result),end(result));
        }
        else
        {
            result +=s[i];
        }
        }
        return result;
    }
};