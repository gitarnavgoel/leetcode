class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l= 0 , r = sqrt(c);
        while(l<=r)
        {
            if(1LL*l*l + 1LL*r*r == c) return true;
            if(l*l + r*r <c) l++;
            else r--;
        }
        return false;
    }
};