class Solution {
public:
    int evalRPN(vector<string>& tok) {
        stack<int> s;
        for(auto i : tok){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res;
                if(i == "+"){
                    res = b + a;
                }
                else if(i == "-"){
                    res = b - a;
                }
                else if(i == "*"){
                    res = b*a;
                }
                else{
                    res = b/a;
                }
                s.push(res);
            }
            else{
                s.push(stoi(i));
            }
        }

        return s.top();
    }
};