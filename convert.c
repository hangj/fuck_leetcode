
// 6. Z 字形变换
// https://leetcode-cn.com/problems/zigzag-conversion/


// 返回第 row 行的第 nth 个字符，在原字符串的坐标
int cal_index_by_row(int numRows, int row, int nth){
    if(row == 0 || row == numRows - 1){
        return row + nth * (2*numRows - 2);
    }

    return row  +  (nth/2) * (2*numRows - 2)  +  (nth % 2) * (2*(numRows - row) - 2);
}

char * convert(char * s, int numRows){
    if(numRows <= 1) return s;

    int len = strlen(s);
    char* res = malloc(len+1);
    res[len] = 0;

    int ri = 0;
    for(int r=0; r < numRows && ri < len; r++){
        int nth = 0;

        for(int i = cal_index_by_row(numRows, r, nth++); 
            i < len && ri < len; 
            i = cal_index_by_row(numRows, r, nth++)
        ){
            res[ri++] = s[i];
        }
    }
    return res;
}