/*
Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size = mountainArr.length();
        if(size==0)
        return -1;

       int l = 0, r = size-1;
        int peak; 

        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(mid==0) 
                mid = mid+1;
            else if(mid==size-1) 
                mid = mid-1;

            int val = mountainArr.get(mid);
            int left = mountainArr.get(mid-1);
            int right = mountainArr.get(mid+1);
            if(val>right && val>left) // peak element condition satisfies
            {
                peak = mid;
                break;
            }
            else if(val>left && val<right) // current index's value is larger than its left and smaller than its right, i.e., on the increasing slope
            {
                l = mid+1;
            }
            else // current index's value is smaller than its left and larger than its right, i.e., on the decreasing slope
            {
                r = mid-1;
            }
        }

        if(target==mountainArr.get(peak)) // if the target element is at the peak
            return peak;
        

//BINARY SEARCH on the left subarray of the peak i.e., INCREASING SEQUENCE
        l = 0, r = peak-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int val = mountainArr.get(mid);
            
            if(val==target)
                return mid;
            else if(val>target)
                r = mid-1;
            else
                l = mid+1;
        }

//BINARY SEARCH on right part to the peak i.e., DECREASING SEQUENCE
        l = peak+1, r = size-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int val = mountainArr.get(mid);
            if(val==target)
                return mid;
            else if(val>target)
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
};
