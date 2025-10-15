class Solution {
public:
    bool binarysearch(vector<int>& row, int target) {
        int low = 0; int high = row.size() - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(row[mid] == target) {
                return true;
            }
            else if(row[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        int startrow = 0; int endrow = m - 1;

        while(startrow <= endrow) {
            int midrow = startrow + (endrow - startrow)/2;
            if(matrix[midrow][0] <= target && matrix[midrow][n - 1] >= target) {
                return binarysearch(matrix[midrow], target);
            }
            else if(matrix[midrow][n - 1] < target) {
                startrow = midrow + 1;
            }
            else {
                endrow = midrow - 1;
            }
        }
        return false;
    }
};