/*
Problem: String to Integer (atoi)
Description: https://leetcode.com/problems/string-to-integer-atoi/
Author: MummyDing
Date : 2015-12-29
Run Time: 12 ms
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
            //filter the number
            int len = str.size(),startX=-1,endX = -1;
            bool sign = true;
            for(int i=0 ; i<len ; i++){
                if(startX == -1){
                    if(str[i] == ' ') continue;
                    if(str[i] == '+' || str[i] == '-'  || str[i]>='0' && str[i]<='9'){
                        startX = i;
                    }else {
                        return 0;
                    }
                }else if((str[i]>='0' && str[i]<='9') == false){
                    endX = i;
                    break;
                }
                if(endX == -1 && len-1 == i){
                        endX = i+1;
                }
            }
            if(startX == -1 || endX == -1) return 0;
            //cout<<str.substr(startX,endX-startX)<<endl;
            if(str[startX] == '-'){
                sign = false;
                startX++;
            }else if(str[startX] == '+'){
                startX++;
            }
            string res = str.substr(startX,endX-startX);
            int lenR = res.size() , resNum = 0, pow = 1;

            // int  -2147483648 ~ 2147483647
            if(sign && (res>"2147483647" && lenR ==10 || lenR>10)){
                return 2147483647;
            }else if(sign ==false && res >"2147483648" && lenR ==10 || lenR>10){
               return  -2147483648;
            }

            // convert string to num
            for(int i = lenR-1 ; i>=0 ; i--){
                resNum += ((res[i]-'0')*pow);
                pow *=10;
            }
            if(sign) return resNum;
            else return -resNum;
    }
};
int main()
{
   // Solution s;
   // cout<<s.myAtoi(" 444-11228552307")<<endl;
    return 0;
}
