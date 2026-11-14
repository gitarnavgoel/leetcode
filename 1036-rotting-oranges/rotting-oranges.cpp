class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i =0 ; i < n; i++)
        {
            for(int j =0 ; j <m ; j++)
            {
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        int time= 0;
        while(!q.empty())
        {
            int sz = q.size();

            for(int i =0 ;i <sz ; i++)
            {
            int r= q.front().first.first;
            int c = q.front().first.second;
            int curr = q.front().second;
            time = max(time,curr);
            q.pop();
            vector<int> dx = {-1,0,1,0};
            vector<int> dy = {0,1,0,-1};

            for(int k =0 ; k < 4 ; k++)
            {
                int nr = r+dx[k];
                int nc = c+dy[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(grid[nr][nc]==1 && !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({{nr,nc},curr+1});
                    }
                }
            }

            }
        }

        for(int i =0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]==1 && vis[i][j] == 0) return -1;
            }
        }

        return time;
    }
};