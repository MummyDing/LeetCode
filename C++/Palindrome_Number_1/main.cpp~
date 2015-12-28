/*
Problem: Palindrome Number
Description: https://leetcode.com/problems/palindrome-number/
Author: MummyDing
Date : 2015-12-27
Run Time: 84 ms
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 ) return false;
       if(x < 10) return true;
       if(x %10 ==0 ) return false;
       int reverseX = 0 , tmpX = x;
       while(tmpX){
            reverseX =  reverseX * 10 + tmpX %10;
            tmpX /= 10;
       }
       if(reverseX == x) return true;
       return false;
    }
};
int main()
{

//    Solution s ;
    //cout<<s.isPalindrome(100001)<<endl;
    return 0;
}
