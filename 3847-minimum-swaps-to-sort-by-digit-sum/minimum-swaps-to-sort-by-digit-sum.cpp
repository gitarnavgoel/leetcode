
class Solution {
public:
    int sum(int x) {
        int ans = 0;

        while (x) {
            ans += x % 10;
            x /= 10;
        }

        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{sum(nums[i]), nums[i]}, i});
        }

        sort(v.begin(), v.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || v[i].second == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
