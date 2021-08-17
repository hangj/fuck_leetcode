// 11. 盛最多水的容器
// https://leetcode-cn.com/problems/container-with-most-water/

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int maxArea(int* height, int heightSize){
    int max = 0;
    for(int i=0,j=heightSize-1; i<j; ){
        max = MAX(max, (j-i)*MIN(height[i], height[j]));
        height[i] < height[j] ? i++ : j--;
    }
    return max;
}
