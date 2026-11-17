class Solution {
public:
vector<int> bfs(vector<vector<int>> list)
{
    int n = list.size();
    vector<int> order(n,0);
    
    for(int i =0 ; i < n; i++)
    {
        for(auto it : list[i])
        {
            order[it]++;
        }
    }
    queue<int>q;
    for(int i =0 ;i< n ; i++)
    {
        if(order[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : list[node])
        {
            order[it]--;
            if(order[it]==0) q.push(it);
        }
    }
    return topo;
}
    vector<int> findOrder(int n, vector<vector<int>>& grid) {
        vector<vector<int>> list(n);

        for(int i =0 ; i < grid.size() ; i++)
        {
            int a = grid[i][0];
            int b = grid[i][1];

            list[b].push_back(a);
        }

        vector<int> ans = bfs(list);
        if(ans.size()!=n) return {};
        return ans;
    }
};