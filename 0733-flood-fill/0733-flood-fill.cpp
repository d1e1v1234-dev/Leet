class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        int start = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] =color;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [x,y] = q.front();
                q.pop();
                arr[x][y]=1;
                for(auto d : dir)
                {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m &&
                       image[nx][ny]==start && !arr[nx][ny])
                    {
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return image;    
    }
};