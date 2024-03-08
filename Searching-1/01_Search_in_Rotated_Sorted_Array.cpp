class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[low]<=nums[mid]){ //means left wala sorted hai
                if(nums[low]<=target && target<=nums[mid])
                    high = mid-1;   //ab left side jayega
                else
                    low = mid+1;
            }
            else{ // nums[mid] <= nums[high]  right wala sorted hai
                if(nums[mid]<=target && target<=nums[high])
                    low = mid+1;  //ab right jayega
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};