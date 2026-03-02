class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int n = skill.size();
        long long sum = 0;
        int l = 0; int r = n - 1;

        for(int i : skill)
            sum += i;
        
        long long size = n/2;
        long long target = sum/size;

        if(sum % size != 0)
            return -1;
        
        while(l < r) {
            if(skill[l] + skill[r] == target)
                ans += (skill[l] * skill[r]);
            else
                return -1;
            l++; r--;
        }
        return ans;
    }
};