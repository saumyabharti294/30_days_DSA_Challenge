/*
  Example 2:

Input:N = 3, Arr[] = {1, 3, 3}
Output: 3 2

Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
*/



vector<int> findTwoElement(vector<int> arr, int n) {
      
        long long sum1=0;
        long long sum_cons=(long long)n*((long long)n+1)/(long long)2;
        
        for(auto it:arr)sum1+=it;
        
        long long sq1=0;
        for(auto it:arr)sq1+=(long long)it*(long long)it;
        
        long long sq_cons=((long long)n*((long long)n+(long long)1)*((long long)2*(long long)n+(long long)1))/(long long)6;
        
        long long p=sum1-sum_cons;
        long long q=sq1-sq_cons;
        
        long long k=q/p;
        
        long long x=(p+k)/(long long)2;
        long long y=x-p;
        
        return{x,y};  
     }
