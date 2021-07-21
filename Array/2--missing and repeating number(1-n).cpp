//FIRST APPROACH : O(N) TIME AND O(N) SPACE USING HASHING
//SECOND APPROACH (OPTIMAL) : MAKE TWO EQATIONS USING SUM AND SUM OF SQUARES 
//THIRD APPROACH USING XOR  (OPTIMAL)

void solve(int arr[],int n){
    int xor1 = 0;
    int xor 2 = 0;
    for (int i = 0; i < n;i++){
        xor1 ^= arr[i];
        xor2 ^= (i + 1);
    }
    int xor3 = xor1 ^ xor2;  //THIS WILL COME EQAL TO XOR OF MISSING NUMBER AND REPEATING NUMBER, // (1^2^3^4^5^6)^(1^2^4^5^6^6) =  3^6  //MISSING AND REPEATING NUMBER XOR
    int set_bit_pos = 1;
    while(true){     //finding the rightmost setbit in xor3
        if(xor3%2!=0){
            break;
        }
        set_bit_pos += 1;
        xor3 /= 2;
    }
    xor1 = 0;
    xor2 = 0;
    int ck = 1;
    for (int i = 1; i <=set_bit_pos;i++){
        ck << 1;                               //converting ck such that its only set_bit_pos is set and other are 0 i.e it will look like 1000...
    }
    for (int i = 0; i < n;i++){
        if(arr[i]&ck)  // it is not zero that means set_bit_pos position of arr[i] has set bit
            xor1 ^= arr[i];
        else
            xor2 ^= arr[i];
        if((i+1)^ck)
            xor1 ^= (i + 1);
        else
            xor2 ^= (i + 1);
    }


    //NOW ONE OF XOR1 and XOR2 will be missing number and the other one will be repeating number 
    //WE CAN FIND THAT IN ONE TRAVERSAL OF THE GIVEN ARRAY
}

