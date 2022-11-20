int removeDuplicates(int* nums, int numsSize){
    int* left = &nums[0]; 
    int* right = &nums[1];
    int newSize = numsSize;
    while (right != &nums[numsSize]) {
        if (*right == *left) {
            right++;
            newSize--;
        }
        else {
            *(++left) = *right;
            right++;
        }
    }
    return newSize;
}