// 5. 最长回文子串
// https://leetcode-cn.com/problems/longest-palindromic-substring/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// [left, right)
void fuck(char* s, int i, int* left, int* right){
    // a a a; a a a
    // ^    ;  ^

    int j=0;
    for(; i-j>=0 && s[i+j] && s[i-j]==s[i+j]; j++);
    *left = i - j + 1;
    *right = i + j;

    j = 0;
    for(; i-j>=0 && s[i+j+1] && s[i-j]==s[i+j+1]; j++);
    if( *right - *left < j + j){
        *left = i - j + 1;
        *right = i + j + 1;
    }
}

char * longestPalindrome(char * s){
    int max_left = 0, max_right = 0;
    for(int i=0; s[i]; i++){
        int left=0, right=0;
        fuck(s, i, &left, &right);
        if(right - left > max_right - max_left){
            max_left = left;
            max_right = right;
        }
    }
    s[max_right] = 0;
    return s + max_left;
}



int main(int argc, char** argv, char** envp){
    if(argc != 2){
        printf("usage: %s string\n", argv[0]);
        return -1;
    }

    char* s = longestPalindrome(argv[1]);
    printf("longestPalindrome: %s\n", s);
    return 0;
}
