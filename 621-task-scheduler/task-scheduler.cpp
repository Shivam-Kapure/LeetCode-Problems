class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq; //max heap aahe hai default;
        queue<pair<int, int>> q;
        int count[26] = {0};
        int time = 0;

        for(char t : tasks)
            count[t - 'A']++;
        
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0)
                pq.push(count[i]);
        }

        while(!q.empty() || !pq.empty()) {
            time++;

            while(!q.empty() &&q.front().first != 0 && q.front().second <= time) {
                int one = q.front().first;
                q.pop();
                pq.push(one);
            }
            
            if(!pq.empty()) {
                int front = pq.top();
                pq.pop();
                front--;

                if(front != 0) {
                    q.push({front, time + n + 1});
                }
            }
        }
        return time;
    }
};