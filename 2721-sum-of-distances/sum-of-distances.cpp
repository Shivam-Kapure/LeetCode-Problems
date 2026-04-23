class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, long long> indexSum;
        unordered_map<int, long long> indexFreq;

        vector<long long> arr(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++) {
            long long freq = indexFreq[nums[i]];
            long long sum = indexSum[nums[i]];

            arr[i] += freq*i - sum;

            indexFreq[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        indexFreq.clear();
        indexSum.clear();

        for(int i = nums.size() - 1; i >= 0; i--) {
            long long freq = indexFreq[nums[i]];
            long long sum = indexSum[nums[i]];

            arr[i] += sum - freq*i;

            indexFreq[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        return arr;
    }
};