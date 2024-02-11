/*
Example 1:

Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
Output: 4

Explanation: 
We can distribute the first 4 natural numbers into arr1 and arr2.
arr1 = [1] and arr2 = [2,3,4].
We can see that both arrays satisfy all the conditions.
Since the maximum value is 4, we return it.
*/

class Solution {
public:

    int minimizeSet(int d1, int d2, int uqC1, int uqC2) {
        long int low=1,high=INT_MAX;
        int ans=INT_MAX;
        long long int lcm=((long long)d1*d2)/__gcd(d1,d2);
        while(low<=high){
             int  mid=low+(high-low)/2;

             //not divisible by d1
             int notd1= mid -mid/d1;

            // not divisible by d2
             int notd2= mid- mid/d2;

            // not divisble by both
             int notboth= mid-mid/lcm;
             
           if(notd1>=uqC1 and notd2>=uqC2 and notboth>=(uqC1+uqC2)){
               ans=mid;
               high=mid-1;
           }
           else low=mid+1;
        }
       
        return ans;
    }
};
