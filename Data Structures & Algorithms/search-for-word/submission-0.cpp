class Solution {
   bool helper(vector<vector<char>>& board, string& word, int index, int x, int y) {
        if (index == word.length()) return true;
        
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) {
            return false;
        }
        
        char temp = board[x][y];
        board[x][y] = '#'; 
        
        bool found = helper(board, word, index + 1, x + 1, y) ||
                     helper(board, word, index + 1, x - 1, y) ||
                     helper(board, word, index + 1, x, y + 1) || 
                     helper(board, word, index + 1, x, y - 1);
                     
        board[x][y] = temp;
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(helper(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};
