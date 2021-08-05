// 191. 位1的个数
// https://leetcode-cn.com/problems/number-of-1-bits/

int hammingWeight(uint32_t n) {
    uint32_t count = 0;
    uint32_t i = 1;

    for(;n;){
        if(n & i) count++;

        n &= ~i; // 消除后面的 1
        i = (i << 1) + 1;
    }

    return count;
}


int hammingWeight(uint32_t n) {
    uint32_t count = 0;

    for(;n;){
        n &= n-1; // 消去最后一位 1 
        count++;
    }

    return count;
}




