class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return solver(board);
    }
    bool solver(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                if(!isPossible(i,j,board)) return false;
            }
        }
        return true;
    }
    bool isPossible(int row,int col,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(i!=col && board[row][i]==board[row][col])
            {
                return false;
            }
            if(i!=row && board[i][col]==board[row][col])
            {
                return false;
            }
            int r=3*(row/3)+i/3;
            int c=3*(col/3)+i%3;
            if(!(r==row && c==col) && board[r][c]==board[row][col]) return false;
        }
        return true;
    }

};