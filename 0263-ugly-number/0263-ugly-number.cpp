class Solution {
public:
    bool isUgly(int n) {
        
        if(n<1)
            return false;
        vector<int>arr{2,3,5};
        
        while(n%5==0)
            n=n/5;
        
        while(n%3==0)
            n=n/3;
        
        while(n%2==0)
            n=n/2;
        
        return n==1;
    }
};