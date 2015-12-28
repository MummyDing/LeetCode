/*
Problem: Palindrome Number
Description: https://leetcode.com/problems/palindrome-number/
Author: MummyDing
Date : 2015-12-27
Run Time: 156 ms
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int count = 1,tmpX = x;
        if(x < 0) return false;
        if(x < 10) return true;

        while(tmpX >= 10){
            tmpX /= 10;
            count ++;
        }
        for(int i = 0 ; i<count/2 ;i++){
            if((x/pow10(count-i-1))%10 != (x/pow10(i))%10)
            return false;
        }
        return true;
    }
    int pow10(int p){
        int sum = 1;
        while(p){
            sum *=10;
            p--;
        }
        return sum;
    }
};
int main()
{

    return 0;
}
