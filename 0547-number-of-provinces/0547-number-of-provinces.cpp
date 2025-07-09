class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool>vis(V,false);
        int count =0;

        function<void(int)> dfs = [&](int n)
        {
            vis[n] = true;
            for(int i=0;i<V;i++)
            {
                if(isConnected[n][i] == 1 && !vis[i])
                   dfs(i);
            }
        };
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i);
            }
        }
        return count;
    }
};