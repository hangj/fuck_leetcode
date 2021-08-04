// 3. 无重复字符的最长子串
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include<stdio.h>

int lengthOfLongestSubstring(char * s){
    int hash[256] = {0};
    for(int i=0; i < sizeof(hash)/sizeof(hash[0]); i++) hash[i]=-1;

    int i = 0;
    int start = 0;
    int max = 0;
    for(char* p=s; *p; p++, i++){
        char c = *p;

        if(hash[c] >= start){
            start = hash[c] + 1;
        }

        hash[c] = i;
        int len = i - start + 1;
        max = len > max ? len : max;
    }
    return max;
}


int main(int argc, char** argv, char** envp)
{
    if(argc != 2){
        printf("usage: %s string\n", argv[0]);
        return -1;
    }
    int l = lengthOfLongestSubstring(argv[1]);
    printf("l: %d\n", l);
    return 0;
}

