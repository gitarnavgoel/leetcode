class Solution {
public:
    
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        int mini = min(need1,need2);

        if(costBoth<cost1 +cost2){
            ans+=1LL*costBoth*mini;
            need1-=mini;
            need2-=mini;
        }
        if(need1>0){
             if(costBoth<cost1) ans+=1LL*need1*costBoth;
             else{
                ans+=1LL*need1*cost1;
             }
        }

        if(need2>0){
             if(cost2<costBoth) ans+=1LL*need2*cost2;
             else{
                ans+=1LL*need2*costBoth;
             }
        }

        return ans;
    }
};     