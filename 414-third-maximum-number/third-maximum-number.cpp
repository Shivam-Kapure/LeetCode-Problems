class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> u_set;
        
        for(int num : nums) {
            if(u_set.count(num))
                continue;

            u_set.insert(num);
            pq.push(num);

            if(pq.size() > 3)
                pq.pop();
        }

        if(pq.size() < 3) 
            return *max_element(u_set.begin(), u_set.end());
        return pq.top();
    }
};