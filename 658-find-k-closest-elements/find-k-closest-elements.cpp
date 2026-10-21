class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> v;
        int n = arr.size();
        for(int i =0 ;i < n ; i++)
        {
            v.push_back({abs(arr[i]-x),arr[i]});
        }
        vector<int> ans;
        sort(v.begin(),v.end());
        int idx =0;
        while(k--)
        {
            ans.push_back(v[idx].second) ;
            idx++;
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};