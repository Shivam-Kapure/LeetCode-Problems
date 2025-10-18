class Solution {
public:
    bool binary_helper(vector<int>& piles, int k, int h) {
        int total_time = 0;
        for(int pile : piles) {
            int div = pile/k;
            total_time += div;
            if(pile % k != 0) {
                total_time++;
            }
        }
        if(total_time <= h) {
            return true;
        }
        else {
            return false;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right) {
            int mid = left + (right - left)/2;
            if(binary_helper(piles, mid, h)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};