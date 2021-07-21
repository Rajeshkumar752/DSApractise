// APPROACH 1 (TIME: O((N+m)*(LOG(N+M))) (SPACE:O(N+M))
    //->CREATE A ARRAY OF SIZE N+m AND PUT ALL ELEMNTS IN IT
    //->SORT THIS ARRAY
    //->PUT BACK ELEMENTS IN SORTED ARRAY


//APPROACH 2 (INSERTION SORT APPROACH)  TIME:O(N*M)  SPACE: O(1)
    //->TRAVERSE FIRST ARRAY AND IF ELEMNT IN CURR POSITION OF FIRST ARRAY IS GREATER THAN SECOND ARRAY 0th POS
    //->SWAP BOTH AND AFTER THAT SORT THE SECOND ARRAY (IT WILL TAKE ONLY ONE TRAVERSAL BCZ ARRAY IS SORTED EXCEPT 0th POS WHICH WE SWAPPED)
    //->IF ELEMNT IN CURR POSITION OF FIRST ARRAY IS SMALLER THAN SECOND ARRAY 0th POS THAN JUST GOT TO NEXT POS IN FIRST ARRAY

    
    void mergeSortedArray(int arr1[],int arr2[],int n,int m){
        for (int i = 0; i < n;i++){
            if(arr2[0]<arr1[i]){
                swap(arr2[0], arr1[i]);
                for (int j = 1; j < m;j++){ // sorting the second array whenever swap is performed
                    if(arr[j-1]>arr[j]){
                        swap(arr[j - 1], arr[j]);
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }

     
//APPROACH 3 (GAP METHOD)  SPACE:O(1) TIME: (N+M)*LOG(N+M) ||MOST OPTIMAL
    // INITIALLY SET GAP AS CEIL((N+M)/2)
    // THEN LOOP THROUGH ELEMNTS OF THE BOTH ARRAY KEEPING GAP AS ABOVE
    //DO TILL GAP IS 1 AND EVERYTIME DIVIDE GAP BY 2