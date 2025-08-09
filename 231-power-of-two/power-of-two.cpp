class Solution {
public:
    bool isPowerOfTwo(int n) {
        int temp=n;
        long long bit=1;
        while(bit<=temp){
            if((temp&bit) && (temp^bit)==0) return true;
            bit=bit<<1;
        }
        return false;
    }
};