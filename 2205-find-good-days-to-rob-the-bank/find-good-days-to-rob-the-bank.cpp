class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> ninc(n,0),ndec(n,0);


        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]){
                ninc[i]=ninc[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]){
                ndec[i]=ndec[i+1]+1;
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ninc[i]>=time && ndec[i]>=time){
                ans.push_back(i);
            }
        }

        return ans;

    }
};