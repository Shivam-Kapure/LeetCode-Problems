class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tube;
        vector<int> result;
        int sol = 0;
        
        for(string s : tokens) {
            if(s != "+" && s != "-" && s != "*" && s != "/") {
                tube.push(stoi(s));
            }
            else {
                if(tube.size() >= 2) {
                    result.push_back(tube.top());
                    tube.pop();
                    result.push_back(tube.top());
                    tube.pop();
                    if(s == "+") {
                        sol = result[1] + result[0];
                    }
                    else if(s == "-") {
                        sol = result[1] - result[0];
                    }
                    else if(s == "*") {
                        sol = result[1] * result[0];
                    }
                    else {
                        sol = result[1] / result[0];
                    }
                    result.pop_back();
                    result.pop_back();
                    tube.push(sol);
                }
            }
        }
        if(!tube.empty()) {
            return tube.top();
        }
        else {
            return 0;
        }
    }
};