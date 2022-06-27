class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // hint: merge sort

        int length = nums1.size() + nums2.size();
        vector<int> nums;
        for(int i = 0, j = 0; i + j < length/2+1;) // 找一半就好
        {
            if(i < nums1.size())
            {
                if(j < nums2.size())
                    nums.push_back((nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++]);
                else
                    nums.push_back(nums1[i++]);
            }
            else
                nums.push_back(nums2[j++]);

        }

        return (length % 2) ? nums[length/2]: 1.0*(nums[length/2] + nums[length/2-1])/2;
    }
};
