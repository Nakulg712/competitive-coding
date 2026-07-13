class Solution {
public:
    int searchInsert(vector<int>& num, int target) {
        int left = 0, right= num.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if (num[mid]== target)
            return mid;
            else if (num[mid] < target)
            left = mid+1;
            else
            right = mid-1;
        }
        return left;
    }
};
