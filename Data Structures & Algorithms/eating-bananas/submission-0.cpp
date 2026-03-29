class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int speed = r;

        while(l <= r){
            int m = l + (r-l)/2;

            long long currTime = 0;
            for(int i = 0; i < n; ++i){
                currTime += (piles[i] + m - 1)/m;
            }

            if(currTime <= h){
                speed = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return speed;
    }
};
