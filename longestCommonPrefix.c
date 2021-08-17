// 14. 最长公共前缀
// https://leetcode-cn.com/problems/longest-common-prefix/



char * longestCommonPrefix(char ** strs, int strsSize){
    char* p = strs[0];
    for(int j=0; *p; p++, j++){
        for(int i=1; i<strsSize; i++){
            if(*p != strs[i][j]){
                *p = 0;
                return strs[0];
            }
        }
    }
    return strs[0];
}

