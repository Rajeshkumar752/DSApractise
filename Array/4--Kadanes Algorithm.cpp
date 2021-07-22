// WE USE KADANE'S ALGORITHM
//O(N) TIME COMPLEXITY


int maxSubarraySum(int arr[], int n){
        
    int ans = 0; int maxa =INT_MIN;
    int curr  = 0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        ans = max(curr,ans);
        if(curr<0){
            curr = 0;
        }
        maxa = max(maxa,arr[i]);
    }
        
    if(ans == 0){
        ans = maxa; // THIS EXTRA PART IS FOR CONDITION WHEN  ALL THE ARRAY ELEMENTS ARE NEGATIVE
    }
        
    return ans;
}