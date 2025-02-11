/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int> result;
        result.resize(row * col);
        int loop = row / 2;
        int offset = 1;
        int startx = 0;
        int starty = 0;
        int fill = 1;
        int index = 0;

        while(loop--) {
            int i = startx;
            int j = starty;

            for(; j < col - offset; ++i) {
                result.push_back(matrix[i][j]);
            }

            for(; i < row - offset; ++j) {
                result.push_back(matrix[i][j]);
            }

            for(; j > startx; --i) {
                result.push_back(matrix[i][j]);
            }

            for(; i > starty; --j) {
                result.push_back(matrix[i][j]);
            }

            ++offset;
            ++startx;
            ++starty;
        }
#if 0
        if(row % 2 != 0) {
            int mid = row / 2;
            for(int i = mid; i < rightBorder - offset; ++i) {
                result[index++] = matrix[i][starty];
            }
        }
#endif

        return result;
    }
};
// @lc code=end

