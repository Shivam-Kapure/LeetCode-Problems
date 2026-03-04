class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size(); int c = mat[0].size();
        int count = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                
                if(mat[i][j] == 1) {
                    bool isSpecial = true;

                    for(int col = 0; col < c; col++) {
                        if(mat[i][col] == 1 && col != j) {
                            isSpecial = false;
                            break;
                        }
                    }

                    if(isSpecial) {
                        for(int row = 0; row < r; row++) {
                            if(mat[row][j] == 1 && row != i) {
                                isSpecial = false;
                                break;
                            }
                        }
                    }

                    if(isSpecial)
                        count++;
                }
            }
        }
        return count;
    }
};