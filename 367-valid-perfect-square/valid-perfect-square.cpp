class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0; long long r = num;
        while(l <= r) {
            long mid = l + (r - l)/2;
            long a = (mid*mid);
            if(a == num)
                return true;
            else if(a < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};