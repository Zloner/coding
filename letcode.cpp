#include <stdio.h>
#include <uthash.h>
#include <string.h>
#include <stdlib.h>

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

int maxProfit(int* prices, int pricesSize) {
    int price, profit;
    int dp[pricesSize][2];
    dp[0][0] = 0;  dp[0][1] = -prices[0];
    for(int i = 1; i < pricesSize; i++){
        dp[i][0] = dp[i-1][0] > dp[i-1][1] + prices[i] ? dp[i-1][0] : dp[i-1][1] + prices[i];
        dp[i][1] = dp[i-1][1] > dp[i-1][0] - prices[i] ? dp[i-1][1] : dp[i-1][0] - prices[i];
    }
    return dp[pricesSize-1][0];
}

bool canJump(int* nums, int numsSize) {
    int k = 0;
    for(int i = 0; i < numsSize; i++){
        if(i > k)   return false;
        k = k > i + nums[i] ? k : i + nums[i];
    }
    return true;
}

int jump(int* nums, int numsSize) {
    int step[numsSize];
    memset(step, 0x3f, sizeof(step));
    step[0] = 0;
    
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < i + 1 + nums[i] && j < numsSize; j++){
            step[j] = step[j] < step[i] + 1 ? step[j] : step[i] + 1;  
        }
    }
    return step[numsSize-1];
}

int jump(int* nums, int numsSize) {
    int border = 0;
    int maxposition = 0;
    int step = 0;
    for(int i = 0; i < numsSize - 1; i++){
        maxposition = maxposition > nums[i]+i ? maxposition : nums[i]+i;
        if(i == border){
            border = maxposition;
            step++;
        }
    }
    return step;
}

int hIndex(int* citations, int citationsSize) {
    for (int i = citationsSize-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(citations[j] > citations[j+1]){
                int tmp = citations[j];
                citations[j] = citations[j+1];
                citations[j+1] = tmp;
            }
        }
    }
    int i = 0, h = 0;
    for(i = citationsSize-1; i >= 0 && citations[i] > h; i--, h++);
    return h;
}

#define MAX_NUM_SIZE 10001

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
}HashItem;

bool findHash(const HashItem ** obj, int key){
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if(NULL != pEntry){
        return true;
    }
    return false;
}

int getHash(const HashItem ** obj, int key){
    HashItem * pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if(NULL == pEntry){
        return -1;
    }
    return pEntry->val;
}

void insertHash(HashItem **obj, int key, int val){
    HashItem * pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if(NULL != pEntry)
        return;
    else{
        pEntry = (HashItem*)malloc(sizeof(HashItem));
        pEntry->key = key;
        pEntry->val = val;
        HASH_ADD_INT(*obj, key, pEntry);
    }
}

bool removeHash(HashItem* obj, int key){
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if(NULL != pEntry){
        HSAH_DEL(*obj, pEntry)
        freee(pEntry);
    }
    return true;
}

void freeHash(HashItem** obj){
    HashItem * curr, *tmp;
    HASH_ITER(hh, *obj, curr, tmp){
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    int * num;
    int numSize;
    HashItem* indices;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    srand((unsigned)time(NULL));
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->nums = (int*)malloc(sizeof(int) * MAX_NUM_SIZE);
    obj->numSize = 0;
    obj->indices = NULL;
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    HashItem *pEntry = NULL;
    if(findHash(&obj->indces, val)){
        return false;
    }
    int index = obj->numSize;
    obj->nums[obj->numSize++] = val;
    insertHash(&obj->indices, val, obj->numSize-1, obj->numSize-1);
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    if(!findHash(&obj->indices, val))
        return false;
    int index = getHash(&obj->indices, val);
    int last = obj->nums[obj->numSize-1];
    obj->nums[index] = last;
    insertHash(&obj->indices, last, index);
    obj->numSize--;
    removeHash(&obj->indices, val);
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int randomIndex = rand()%obj->numSize;
    return obj->nums[randomIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    freeHash(&obj->indices);
    free(obj->nums);
    free(obj);
}


int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int left[numsSize], right[numsSize];
    int *answer = (int*)malloc(sizeof(int) * numsSize);
    left[0] = 1;
    right[numsSize-1] = 1;
    *returnSize = numsSize;
    for(int i = 1; i < numsSize; i++){
        left[i] = nums[i-1] * left[i-1];
    }
    for(int j = numsSize-2; j >= 0 ; j--){
        right[j] = nums[j+1] * right[j+1];
    }
    for(int i = 0; i < numsSize; i++){
        answer[i] = left[i] * right[i];
    }
    return answer;
}

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int cnt = 0 , gassum = 0, costsum = 0;
    for(int i = 0; i < gasSize;i = i + 1 + cnt){
        cnt = 0;
        costsum = 0;
        gassum = 0;
        while(cnt < gasSize){
            int j = (i + cnt) % gasSize;
            costsum+=cost[j];
            gassum+=gas[j];
            if(gassum < costsum)
                break;
            cnt++;
        }
        if(cnt == gasSize)
            return i;
    }
    return -1;
}

int candy(int* ratings, int ratingsSize) {
    int leftright[ratingsSize];
    leftright[0] = 1;
    for(int i = 1; i < ratingsSize; i++){
        if(ratings[i]>ratings[i-1]){
            leftright[i] = leftright[i-1]+1;
        }
        else{
            leftright[i] = 1;
        }
    }
   
    leftright[ratingsSize-1] = 1 > leftright[ratingsSize-1] ? 1 : leftright[ratingsSize-1];
    int sum = leftright[ratingsSize-1];
    for(int i = ratingsSize-2; i >=0; i--){
        if(ratings[i]>ratings[i+1])
            leftright[i] = leftright[i+1]+1 > leftright[i] ? leftright[i+1]+1 : leftright[i];
        else
            leftright[i] = 1 > leftright[i] ? 1 : leftright[i];
        sum += leftright[i];
    }
    return sum;
}

int trap(int* height, int heightSize) {
    int rain[heightSize];
    int max = height[0];
    for(int i = 0; i < heightSize; i++){
        if(height[i] > max)
            max = height[i];
        rain[i] = max - height[i];
    }
    int sum = 0;
    max = height[heightSize-1];
    for(int i = heightSize-1; i >= 0; i--){
        if(height[i] > max)
            max = height[i];
        rain[i] = max - height[i] < rain[i] ? max - height[i] : rain[i];
        sum += rain[i];
    }
    return sum;
}

int getvalue(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
int romanToInt(char* s) {
    int pre;
    int sum = 0;
    pre = getvalue(s[0]);
    for(int i = 1; i < strlen(s); i++){
        int num = getvalue(s[i]);
        if(pre < num)
            sum -= pre;
        else
            sum += pre;
        pre = num;
    }
    sum += pre;
    return sum;
}

int lengthOfLastWord(char* s) {
    if(strlen(s) == 0)
        return 0;
    int i = 0, count = 0;
    for(i = strlen(s)-1; i >= 0; i--){
        if(count == 0 && s[i] == ' ')
            continue;
        if(count != 0 && s[i] == ' ')
            break;
        count++;
    }
    return count;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    char * str = (char*)malloc(sizeof(char) * 200);
    strcpy(str, strs[0]);

    if(strsSize == 0)
        return "";

    int length1 = strlen(strs[0]);
    for(int i = 0; i < length1; i++){
        char c = strs[0][i];
        for(int j = 1; j < strsSize; j++){
            if(i == strlen(strs[j]) || strs[j][i] != c){
                str[i] = '\0';
                return str;
            }
        }
    }
    return str;
}

char* reverseWords(char* s) {
    char tmp[10001];
    int k = 0;
    for(int i = strlen(s)-1; i > 0; i--){
        if(s[i] != ' ' && s[i-1] == ' '){
            tmp[k++] = s[i];
            tmp[k++] = ' ';
        }
        else if(s[i] == ' ')
            continue;
        else if(s[i] != ' '){
            tmp[k++] = s[i];
        }
    }

    if(s[0] != ' ')
        tmp[k++] = s[0];
    tmp[k++] = '\0';
    printf("%s\n", tmp);
    

    int left = 0, right = 0;
    for(int i = 0; i < k; i++){
        if(tmp[i] != ' ' && tmp[i] != '\0'){
            right++;
        }
        else{
            int j, m = 0;
            for(j = right-1, m = left; j >= left; j--, m++){
                s[m] = tmp[j];
            }
            s[m++] = '\0';
            left = m;
            right = m;
        }
        if(tmp[i] == ' ')
            s[i] = ' ';
    }
    if(s[strlen(s)-1] == ' ')
        s[strlen(s)-1] = '\0';

    printf("%s\n", s);
    return s;
}

char* convert(char* s, int numRows) {
    if(numRows == 1 || numRows >= strlen(s)){
        return s;
    }
    int t = 2*numRows-2;
    int col = ((strlen(s)+t-1)/t) * (numRows-2+1);
    char ** arr = (char**)malloc(sizeof(char*) * numRows);
    for(int i = 0; i < numRows; i++){
        arr[i] = (char*)malloc(sizeof(char) * col);
        memset(arr[i], 0, sizeof(char)*col);
    }
    
    int x = 0, y = 0;
    for(int i = 0; i < strlen(s); i++){
        if(i%t < numRows - 1){
            arr[x][y] = s[i];
            x++;
        }
        else{
            arr[x][y] = s[i];
            x--; y++;
        }
    }

    int k = 0;
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j]){
                s[k] = arr[i][j];
                k++;
            }
        }
    }
    return s;
}

char* convert(char* s, int numRows) {
    if(numRows == 1 || numRows > strlen(s))
        return s;
    char *ans = (char*)malloc(sizeof(char)*1001);
    int t = 2*numRows - 2;
    int col = (strlen(s)+t-1)/t * (numRows-1);
    int k = 0;
    for(int i = 0; i < numRows; i++){
        for(int j = 0; i + j < strlen(s); j+=t){
            ans[k++] = s[i+j];
            if(i > 0 && i < numRows - 1 && j + t - i < strlen(s)){
                ans[k++] = s[j + t - i];
            }
        }
    }
    ans[k] = '\0';
    return ans;
}

int strStr(char* haystack, char* needle) {
    char * ans = strstr(haystack, needle);
    if(ans == NULL){
        return -1;
    }
    else{
        return ans-haystack;
    }
}

bool isSubsequence(char* s, char* t) {
    int i = 0, j = 0;
    while(j < strlen(t)){
        if(t[j] == s[i]){
            i++;
        }
        j++;
    }
    if(i == strlen(s))
        return true;
    else
        return false;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int * ret = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;

    int left = 0, right = numbersSize-1;
    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            ret[0] = left+1;
            ret[1] = right+1;
            return ret;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    ret[0] = -1;
    ret[1] = -1;
    return ret;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int * ret = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;

    for(int i = 0; i < numbersSize; i++){
        int left = i+1, right = numbersSize-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(numbers[mid] == target - numbers[i]){
                ret[0] = i+1;
                ret[1] = mid+1;
                return ret;
            }
            else if(numbers[i] + numbers[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
    return ret;
}

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize-1;
    int vol = (right - left) * fmin(height[left], height[right]);
    
    while(left < right){
        if(height[left] < height[right])
            left++;
        else
            right--;
        int tmp = (right - left) * fmin(height[left], height[right]);
        vol = fmax(vol, tmp);
    }
    return vol;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int k = n - 1;
            int target = -nums[i];

            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                
                while(j < k && nums[j] + nums[k] > target)
                    k--;
                if(j == k)
                    break;
                if(nums[j] + nums[k] == target)
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum+=nums[j];
                if(sum >= target){
                    len = min(len, j-i+1);
                    break;
                }
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int len = n+1;
        int begin = 0, ends = 0;
        int sum = 0;
        while(ends < n){
            sum+=nums[ends];
            while(sum >= target){
                len = (ends - begin + 1) < len ? (ends - begin + 1) : len;
                sum-=nums[begin];
                begin++;
            }
            ends++;
        }

        return len == n+1 ? 0 : len;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int len = 1;
        for(int i = 1; i < n; i++){
            int flag = -1;

            for(int j = left; j <= right; j++){
                if(s[j] == s[i]){
                    flag = j;
                    break;
                }
            }

            if(flag == -1){
                right++;
            }
            else{
                right++;
                left = flag + 1;
            }

            len = len > (right - left + 1) ? len : (right - left + 1);
        }

        return len;
    }
};

