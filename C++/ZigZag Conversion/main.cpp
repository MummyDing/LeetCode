/*
Problem: ZigZag Conversion
Description: https://leetcode.com/problems/zigzag-conversion/
Author: MummyDing
Date : 2015-12-30
Run Time: 20 ms
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string res = "";
        int len = s.size();
        for(int i=0 ; i<numRows ; i++){
            int col = 0 ;
            for( int j=i ; j<len ; ){
                res += s[j];
                if( i== 0 || i == numRows-1 ){
                    j += (2*numRows - 2);
                }else if(col % 2 == 0){
                    j = ((col*2+2)*(numRows - 1) -j);
                }else {
                    j = ((col+1)*(numRows - 1)*2 -j);
                }
                col++;
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
    //cout<<s.convert("1234567890abcd",6)<<endl;
    return 0;
}

