class Solution {
public:
    void bfs(int row , int col , vector<vector<int>>&vis , int color , vector<vector<int>>&image,int x)
    {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int m = image.size();
        int n = image[0].size();
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            q.pop();
            
            vector<int> dx = {-1,1,0,0};
            vector<int> dy = {0,0,-1,1};

            for(int i =0 ; i < 4 ; i++)
            {
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n)
                {
                    if(image[nr][nc]==x && !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n= image[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int x = image[sr][sc];
        bfs(sr,sc , vis,color,image,x);
        return image;
    }
};