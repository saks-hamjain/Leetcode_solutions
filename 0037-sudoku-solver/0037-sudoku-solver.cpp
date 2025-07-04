class Solution {
public:
    bool issafe(int row,int col,char val,vector<vector<char>>&board){
        for(int i=0;i<9;i++)
        {
             if(board[row][i] == val) return false;
             if(board[i][col] == val) return false;
             //box check
             int boxrow = 3*(row/3) +i/3;
             int boxcol = 3*(col/3)+ i % 3;
             if(board[boxrow][boxcol] == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i =0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    for(char val = '1';val<='9';val++)
                    {
                        if(issafe(i,j,val,board)){
                            board[i][j] = val;
                        
                          bool possible = solve(board);
                          if(possible) return true;
                          board[i][j] = '.';
                      }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
       solve(board);   
    }
};