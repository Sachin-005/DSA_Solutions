class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
              vector<int> freq(26, 0);
    for (char task : tasks) {
        freq[task - 'A']++;
    }

    priority_queue<int> maxHeap;
    for (int f : freq) {
        if (f > 0)
            maxHeap.push(f);
    }
    int time=0;
    while(!maxHeap.empty()){
        int i=0;
        vector<int> temp;
        while(i<=n){ // after schedulling we need to wait for n+1 time

            if(!maxHeap.empty()){
                if(maxHeap.top()>1)
                temp.push_back(maxHeap.top()-1);
                maxHeap.pop();
                
            }
            time++;
            if(maxHeap.empty() && temp.empty()){
                break;
            }
            i++;
        }
        for(int i: temp){
            maxHeap.push(i);
        }
    }
    return time;
    }
};