class Solution {
public:
    int m, n;
    int INF = 10000000;
    vector<int> houses;
    vector<vector<int>> cost;
    int dp[101][101][21] = {};

    int recur(int i, int target, int col){

        if(i == m){
            if(target == 1){
                return 0;
            }
            else{
                return INF;
            }
        }

        if(target <= 0){
            return INF;
        }

        if(dp[i][target][col] == -1){
            if(houses[i] != 0){ 
                if(i != 0 && col != houses[i]){
                    dp[i][target][col] = recur(i+1, target-1, houses[i]);
                }
                else{
                    dp[i][target][col] = recur(i+1, target, houses[i]);
                }
            }
            else{
                int minCost = INF;
                for(int k = 1; k <= n; k++){
                    if(i != 0 && col != k){
                        minCost = min(minCost, cost[i][k-1] + recur(i+1, target-1, k));
                    }
                    else{
                        minCost = min(minCost, cost[i][k-1] + recur(i+1, target, k));
                    }
                }

                dp[i][target][col] = minCost;
            }
        }

        return dp[i][target][col];
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->houses = houses;
        this->cost = cost;
        this->m = m;
        this->n = n;

        memset(dp, -1, sizeof(dp));

        int res = recur(0, target, 0);
        return res == INF? -1 : res;
    }
};