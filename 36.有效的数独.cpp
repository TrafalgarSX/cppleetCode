/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <vector>
#include <unordered_map>
using namespace std;


// @lc code=start
class Solution {
public:
    unordered_map<char, bool> exist;
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudoku_solution(board);
    }

    bool isValidSudoku_solution(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int sudoku[9][9] = {0};
        for (size_t i = 0; i < 9; i++)
        {
          for (size_t j = 0; j < 9; j++){
            if(board[i][j] == '.') 
                continue;
            int indexNumber = board[i][j] - '1';
            if(row[i][indexNumber]) 
                return false;
            if(column[j][indexNumber]) 
                return false;
            if(sudoku[j/3 + (i / 3) * 3][indexNumber])
                return false;
            row[i][indexNumber] = 1;
            column[j][indexNumber] = 1;
            sudoku[j/3 + (i / 3) * 3][indexNumber] = 1;
          }
        }
        return true;

    }

    bool isValidSudoku_brutal_force(vector<vector<char>>& board) {
        int size = board.size();
        // check row
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++){
                if(board[i][j] == '.'){
                    continue;
                }else if(exist.find(board[i][j]) == exist.end()){
                    exist.emplace(board[i][j], true);
                }else{
                    return false;
                }
            }
            exist.clear();
        }
        // check column
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++){
                if(board[j][i] == '.'){
                    continue;
                }else if(exist.find(board[j][i]) == exist.end()){
                    exist.emplace(board[j][i], true);
                }else{
                    return false;
                }
            }
            exist.clear();
        }
        // check sudoku
        for (size_t i = 0; i < size; i+=3)
        {
            for (size_t j = 0; j < size; j+=3)
            {
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                      if(board[k + i][l + j] == '.'){
                        continue;
                      }
                      else if (exist.find(board[k + i][l + j]) == exist.end()) {
                        exist.emplace(board[k + i][l + j], true);
                      } else {
                        return false;
                      }
                    }
                }
                exist.clear();
            }
        }
        return true; 
    }
};
// @lc code=end

