class Solution {
public:
    void bfs(int r , int c , vector<vector<int>>&vis,vector<vector<char>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vis[r][c]=1;

        q.push({r,c});

        while(!q.empty())
        {
            int r1 = q.front().first;
            int c1 = q.front().second;
            q.pop();
            int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

for(int k = 0; k < 4; k++)
{
    int row = r1 + dr[k];
    int col = c1 + dc[k];

    if(row >= 0 && row < n &&
       col >= 0 && col < m &&
       !vis[row][col] && grid[row][col] == '1')
    {
        vis[row][col] = 1;
        q.push({row,col});
    }
}
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0 ; i < n ; i++)
        {
            for(int j =0 ; j <m ; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};