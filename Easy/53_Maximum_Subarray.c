

int maxSubArray(int* nums, int numsSize){

    int sum = nums[0], maxn = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        if(sum + nums[i] > nums[i]) sum += nums[i];
        else sum = nums[i];

        if(maxn < sum) maxn = sum;
    }

    return (numsSize > 1) ? maxn: nums[0];
}
