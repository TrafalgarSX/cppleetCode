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
        bool ans = false;


        return ans;

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

