class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();

        while(k--) {

            vector<int> tmp;
            
            for(int i = 0; i < m; i++) {
                tmp.push_back(grid[i][n-1]);
            }
            // 保存最后一列

            for(int i = n-1; i > 0; i--) {
                for(int j = 0; j < m; j++) {
                    grid[j][i] = grid[j][i-1];
                } 
            }
            //交换后n-1列
            
            for(int i = 0; i < m-1; i++) {
                grid[i+1][0] = tmp[i];
            }

            grid[0][0] = tmp[m-1];
        }

        return grid;
    }
};

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();
        
        int total = m * n;
        k %= total;

        if(k == 0) return grid;

        vector<int> b(total);
        vector<int> c(total);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                b[i*n+j] = grid[i][j];
            }
        }
        
        for(int i=0; i<total; i++) {
            c[(i+k) % total] = b[i];
        }

        for(int i=0; i<total; i++) {
            grid[i/n][i%n] = c[i];
        }

        return grid;
    }
};