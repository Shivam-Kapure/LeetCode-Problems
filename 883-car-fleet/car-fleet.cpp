class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st; 
        map<int, int> omap;
        for(int i = 0; i < position.size(); i++) {
            omap[position[i]] = speed[i];
        }
        for(auto it = omap.rbegin(); it != omap.rend(); ++it) {
            double time = (double)(target - it->first)/it->second;
            if(st.empty()) {
                st.push(time);
            }
            else {
                if(time <= st.top()) {
                    continue;
                }
                else {
                    st.push(time);
                }
            }
        }
        return st.size();
    }
};