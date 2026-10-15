class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(!num) return "";

        string ans = "";

        while(sum!=0)
        {
            if(!num) break;
            if(sum>=9)
            {
                ans+=('0'+9);
                sum-=9;
                num-=1;
            }
            else{
                ans+=('0'+sum);
                num-=1;
                sum = 0;
            }
        }
        while(num)
        {
            ans+='0';
            num--;
        }
        if(sum!=0) return "";
        return ans;
    }
};