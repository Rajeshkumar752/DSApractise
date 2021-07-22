// APPROACH 1 (BRUTE) TIME :O(N^2)+O(NLOGN)  , SPACE:O(N)
    //->FIST SORT THE GIVEN VECTOR
    //->FOR EACH INTERVAL ITERATE ON ALL OTHER INTERVALS AND MERGE THEM
    //-> STORE ANS IN A SEPARATE DATA STRUCCTURE


//APPROACH 2 (OPTIMAL)  TIME:O(NLOGN) SPACE :O(N)

    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        if(n==1)
            return v; //If only 1 interval is there we don't need to do anything else

        vector<vector<int>> ans;
        vector<int> curr;   //to store the current interval
        
        sort(v.begin(),v.end());
        
        curr.push_back(v[0][0]);  // adding first elemnt to ans
        curr.push_back(v[0][1]);
        
        for(int i=1;i<n;i++){
            if(v[i][0]<=curr[1]){
                curr[1] = max(curr[1],v[i][1]);
            } 
            else{
                ans.push_back(curr);
                curr.clear();
                curr.push_back(v[i][0]);
                curr.push_back(v[i][1]);
            }
        }
        
        ans.push_back(curr);
          
    return ans;
    }