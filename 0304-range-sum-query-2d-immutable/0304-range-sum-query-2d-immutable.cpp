class NumMatrix {
public:
    vector<vector<int>> mat,pre;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        mat = matrix; 
        int m = mat.size();
        int n = mat[0].size();  
        pre= vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i = 1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+ mat[i-1][j-1];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int sum = pre[row2+1][col2+1] - pre[row2+1][col1]-pre[row1][col2+1]+pre[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */