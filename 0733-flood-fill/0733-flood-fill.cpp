class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size(); 
        
        vector<int> row = {-1,0,0,1};
        vector<int> col = {0,-1,1,0};
        int init = image[sr][sc];
        
        vector<vector<int>>res (image.begin(),image.end());
        
        queue<pair<int,int>>q;
        
        q.push({sr,sc});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            res[front.first][front.second] = color;
            for(int k=0;k<4;k++)
            {
                int nr = front.first + row[k];
                int nc= front.second + col[k];
                if(nr >=0 && nr < n && nc >=0 &&nc <m && image[nr][nc] == init && res[nr][nc] != color)
                {
                    q.push({nr,nc});
                }
            }
        }
        return res;
    }
};