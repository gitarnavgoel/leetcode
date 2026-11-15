class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;

        long long odd = 0, even = 1;
        long long ans = 0, sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum & 1) {
                ans = (ans + even) % MOD;
                odd++;
            }
            else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};