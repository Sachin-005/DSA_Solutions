class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a: asteroids){
            bool exploded = false;
            while(!st.empty() && a<0 && st.top()>0){ // for opposite direction
                if(abs(a) > st.top()){
                    st.pop();
                    continue;
                }
                else if(abs(a) == st.top()){
                    st.pop();
                }
                exploded = true;
                break;
            }
            if(!exploded) st.push(a);
        }
         vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};