// 66. 加一
// https://leetcode-cn.com/problems/plus-one/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* result = malloc(sizeof(int)*(digitsSize+1));
    int carry = 1;
    for(int i=digitsSize-1; carry && i >= 0; i--){
        int tmp = digits[i] + carry;
        digits[i] = tmp % 10;
        carry = tmp / 10;
    }

    int* p = result;
    *returnSize = digitsSize;
    if(carry){
        *returnSize = digitsSize + 1;
        p = result + 1;
        result[0] = carry;
    }
    
    for(int i=0; i < digitsSize; i++, p++){
        *p = digits[i];
    }

    return result;
}


// 目前网上最流行的解法貌似是 https://leetcode-cn.com/problems/plus-one/solution/java-shu-xue-jie-ti-by-yhhzw/
// 看起来很酷，但是这种解法并不通用，比如一旦 plusOne 改成了 plusTwo，它的整个算法都要调整
