class Solution {
public:
    bool detect(int n , vector<int>&vis , vector<vector<int>> & adj)
    {
        vis[n]=1;
        
        for(auto it : adj[n])
        {
            if(!vis[it])
            {
                if(detect(it,vis,adj)) return true;
            }else{
                if(vis[it]==1) 
                return true;
            }
        }
        vis[n]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& grid) {
        vector<int> vis(n);

        vector<vector<int>> adjList(n);
        for(int i =0 ; i < grid.size();i++)
        {
            int a= grid[i][0];
            int b = grid[i][1];
            adjList[b].push_back(a);
        }

        for(int i =0 ; i < n; i++)
        {
            if(!vis[i])
            {
                if(detect(i,vis,adjList)) return false;
            }
        }
        return true;
    }
};