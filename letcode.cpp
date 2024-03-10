void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int tmp[m + n];
    int count1 = 0, count2 = 0, cur = 0;
    while(count1 < m || count2 < n){
        if(count1 >= m)
            cur = nums2[count2++];
        else if(count2 >= n)
            cur = nums1[count1++];
        else if(nums1[count1] <= nums2[count2])
            cur = nums1[count1++];
        else if(nums2[count2] < nums1[count1])
            cur = nums2[count2++];
        tmp[count1+count2-1] = cur;
    }
    
    for(int i = 0; i < n + m; i++){
        nums1[i] = tmp[i];
    }
}

int removeElement(int* nums, int numsSize, int val) {
    int length = numsSize;
    for(int i = 0; i < length;){
        if(nums[i] == val){
            nums[i] = nums[length-1];
            length--;
        }
        else
            i++;
    }
    return length;
}

int removeDuplicates(int* nums, int numsSize) {
    int x = 10002, j = 0;
    int tmp[numsSize];

    for(int i = 0; i < numsSize; i++){
        if(x != nums[i]){
            x = nums[i];
            nums[j] = nums[i];
            j++;
        }
        else{
            continue;
        }
    }
    return j;
}

int removeDuplicates(int* nums, int numsSize) {
    int p = 0, count = 0, x = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(x != nums[i]){
            x = nums[i];
            nums[p] = nums[i];
            p++;
            count = 1;
        }
        else if(x == nums[i] && count < 2){
            nums[p] = nums[i];
            p++;
            count++;
        }
        else{
            continue;
        }
    }
    return p;
}

int majorityElement(int* nums, int numsSize) {
    int count = 0, candidate = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(count == 0)
            candidate = nums[i];
        if(nums[i] == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}

void rotate(int* nums, int numsSize, int k) {
    while(k > numsSize){
        k = k - numsSize;
    }
    for(int i = 0; i < numsSize/2; i++){
        int tmp = nums[i];
        nums[i] = nums[numsSize-1-i];
        nums[numsSize-1-i] = tmp;
    }
    for(int i = 0; i < k/2; i++){
        int tmp = nums[i];
        nums[i] = nums[k-1-i];
        nums[k-1-i] = tmp;
    }
    for(int i = 0; i < (numsSize-k)/2; i++){
        int tmp = nums[k+i];
        nums[k+i] = nums[numsSize-1-i];
        nums[numsSize-1-i] = tmp;
    }
    
}

int maxProfit(int* prices, int pricesSize) {
    int profit = 0, price = prices[0], cost = prices[0];
    for(int i = 0; i < pricesSize; i++){
        price = price < prices[i] ? price : prices[i];
        profit = profit > prices[i]-price ? profit : prices[i]-price;
    }
    return profit;
}

