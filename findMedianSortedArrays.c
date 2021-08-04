// 4. 寻找两个正序数组的中位数
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define is_even(num) !((num)&1)

int next(int* nums1, int nums1Size, int* nums2, int nums2Size, int *i, int *j){
    if(*i >= nums1Size && *j >= nums2Size)
        return nums1[*i-1] < nums2[*j-1] ? nums1[*i-1] : nums2[*j-1];

    if(*i >= nums1Size && *j < nums2Size){
        return nums2[ (*j)++ ];
    }
    if(*j >= nums2Size && *i < nums1Size){
        return nums1[ (*i)++ ];
    }
    return nums1[*i] < nums2[*j] ? nums1[ (*i)++ ] : nums2[ (*j)++ ];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int m1 = -1, m2 = -1;
    int sumSize = nums1Size + nums2Size;
    if(is_even(sumSize)){
        m1 = sumSize/2 -1;
        m2 = m1 + 1;
    } else {
        m1 = sumSize/2;
    }

    int i=0, j=0;
    for(; i+j < m1; ){
        next(nums1, nums1Size, nums2, nums2Size, &i, &j);
    }

    assert(i+j == m1);
    m1 = next(nums1, nums1Size, nums2, nums2Size, &i, &j);
    if(m2 == -1){
        return m1;
    } else {
        m2 = next(nums1, nums1Size, nums2, nums2Size, &i, &j);
        return (m1 + m2)/ 2.0;
    }
}


int main(int argc, char** argv, char** envp)
{
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    double median = findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(nums1[0]), nums2, sizeof(nums2)/sizeof(nums2[0]));

    printf("median: %f\n", median);

    return 0;
}
