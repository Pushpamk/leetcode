class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = rowIndex(matrix, target);
        cout<<row<<endl;
        int low = 0, high = matrix[0].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target)
                return true;
            
            else if (matrix[row][mid] > target)
                high = mid - 1;
            
            else
                low = mid + 1;
        }
        return false;
    }
    int rowIndex(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size();
        int mid = 0;
        while (low < high) {
            mid = (high + low) / 2;
            if (matrix[mid][0] == target)
                return mid;
            else if (matrix[mid][0] > target)
                high = mid;
            else
                low = mid + 1;
        }
        return max(0, low - 1);
    }
};
