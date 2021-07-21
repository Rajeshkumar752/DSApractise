//TIME : 0(N)  1 Traversal
//   O(1) space 
  
  void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = -1; int high =n;
        int curr= 0 ;
        while(curr<high){
            if(nums[curr]==0){
                low+=1;
                swap(nums[low],nums[curr]);
                curr+=1;
            }
            else if(nums[curr]==2){
                high-=1;
                swap(nums[high],nums[curr]);
            }
            else{
                curr+=1;
            }
        }
        return ;
    }

    // Low represents the index till which all elements will be 0
    //high represents the index after which till n all values will be 2