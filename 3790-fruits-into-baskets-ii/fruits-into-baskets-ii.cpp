class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int all=fruits.size();

        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    all--;
                    baskets[j]=-1e9;
                    break;
                }
            }
        }

        return all;
    }
};