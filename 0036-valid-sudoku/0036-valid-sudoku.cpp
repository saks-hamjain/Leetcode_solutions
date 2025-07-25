class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
       unordered_set<string> hash;
       for(int i=0;i<9;i++)
       {
        for(int j=0;j<9;j++)
        {
            if(board[i][j] == '.') continue;
            string row = string(1,board[i][j])+"ROW"+to_string(i);
            string col=string(1,board[i][j])+"COL"+to_string(j);
            string box = string(1,board[i][j])+"BOX"+to_string(i/3)+","+to_string(j/3);
            if(hash.find(row) != hash.end() || hash.find(col) != hash.end() || hash.find(box) != hash.end())
            return false;

            hash.insert(row);
            hash.insert(col);
            hash.insert(box);
        }
       } 
       return true;
    }
};