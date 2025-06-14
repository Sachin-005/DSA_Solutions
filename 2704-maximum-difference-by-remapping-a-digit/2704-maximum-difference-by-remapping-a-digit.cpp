class Solution {
public:

    int chnum(vector<int>v,int f){
        int num=v[0];
        int ans=0;
        if(v[0]==9&&f==1){
            int i=0;
            while(i<v.size()&&v[i]==9){
                i++;
            }
            if(i<v.size())num=v[i];
        }
        if(f==1){
            for(int i=0;i<v.size();i++){
                if(num==v[i]){
                    v[i]=9;
                }
                ans=(ans*10)+v[i];
            }
        }
        else{
            for(int i=0;i<v.size();i++){
                if(num==v[i]){
                    v[i]=0;
                }
                ans=(ans*10)+v[i];
            }
        }
        return ans;
    }

    int minMaxDifference(int num) {
        vector<int> v;
        string s=to_string(num);
        for(char c:s){
            v.push_back(c-'0');
        }
        cout<<endl;
        int maxi=chnum(v,1);
        int mini=chnum(v,0);
        return maxi-mini;
    }
};