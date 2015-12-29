/*
Problem: Reverse Integer
Description: https://leetcode.com/problems/reverse-integer/
Author: MummyDing
Date : 2015-12-29
Run Time: 12 ms
*/
#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(-2147483648 == x) return 0;
        bool sign = x >= 0 ,flag = true;
        string num ="";
        if(sign == false) x = -x;
        while(x){
            if(flag){
                if(x%10 == 0){
                    x/=10;
                    continue;
                }
                flag = false;
            }
            num+= x%10+'0';
            x/=10;
        }
        int len = num.size();
        if(len > 10) return 0;
        else if(len == 10 &&(sign == false && num >"2147483648" || sign&&num>"2147483647")) return 0;
        //convert to number
        int resNum =0 ,pow=1;
        for(int i = len-1 ; i>=0  ; i--){
            resNum += (num[i]-'0')*pow;
            pow*=10;
        }
        if(sign == false) return -resNum;
        return resNum;
    }
};
int main()
{
    //Solution s ;
    //cout<<s.reverse(-2147483648)<<endl;
    return 0;
}
