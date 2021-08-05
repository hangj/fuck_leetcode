// 189. 旋转数组
// https://leetcode-cn.com/problems/rotate-array/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


static void reverse(int* nums, int from, int to) {
  for (; from < to; from++, to--){
      int tmp = nums[from];
      nums[from] = nums[to];
      nums[to] = tmp;
  }
}

/*
** Let x = AB, where A is a prefix of length 'n'. Then,
** rotate x n == BA. But BA == (A^r . B^r)^r.
*/
void rotate(int* nums, int numsSize, int k){
    if(numsSize < 2 || k < 1) return;
    k = k % numsSize;
    if(k == 0) return;

    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}


// -------------------------------------------------------------------------

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

void rotate(int* nums, int numsSize, int k){
    if(numsSize < 2 || k < 1) return;
    k = k % numsSize;
    if(k == 0) return;

    int count = gcd(numsSize, k);

    for(int i=0; i < count; i++){
        // nums[ (i+k) % numsSize ] = nums[i];
        int v = nums[i];
        int j=(i+k)%numsSize;
        for(; j != i; j=(j+k)%numsSize){
            int tmp = nums[j];
            nums[j] = v;
            v = tmp;
        }
        nums[j] = v;
    }
}

// --------------------------------------------------------------------------


void rotate(int* nums, int numsSize, int k){
    if(numsSize <= 1) return;
    k = k % numsSize;
    if(k <= 0) return;

    // nums[ (i+k) % numsSize ] = nums[i];
    // nums[i] = nums[ (i + numsSize - k) % numsSize ];

    int s = numsSize - k;
    int *hash = malloc(sizeof(int) * s);
    memcpy(hash, nums, sizeof(int) * s);

    for(int i=0; i < numsSize; i++){
        int j = (i + numsSize - k) % numsSize;
        nums[i] = j >= 0 && j < s ? hash[ j ] : nums[j];
    }
}

void rotate(int* nums, int numsSize, int k){
    if(k <= 0 || numsSize <= 1) return;
    k = k % numsSize;
    if(k == 0) return;

    int s = numsSize - k;
    int left = 0;
    int right = s;
    int tmp_size = s;

    int start = 0;
    int diff = 1;
    int end = numsSize;

    if(k < s){
        left = s;
        right = numsSize;
        tmp_size = k;

        start = numsSize-1;
        diff = -1;
        end = -1;
    }

    int *hash = (int*)malloc(sizeof(int) * tmp_size);
    memcpy(hash, nums + left, sizeof(int) * tmp_size);

    for(int i=start; i != end; i += diff){
        int j = (i + numsSize - k) % numsSize;
        nums[i] = j >= left && j < right ? hash[ j-left ] : nums[j];
    }
}


int main(int argc, char** argv, char** envp)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};

    rotate(nums, sizeof(nums)/sizeof(nums[0]), 3);

    for(int i=0; i < sizeof(nums)/sizeof(nums[0]); i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
