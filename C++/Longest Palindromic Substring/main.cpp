/*
Problem: Longest Palindromic Substring
Description: https://leetcode.com/problems/longest-palindromic-substring/
Author: MummyDing
Date : 2015-01-03
Run Time: TLE
*/
#include <iostream>
#define LEN 1005
using namespace std;

string res = "";
int palindrome[LEN][LEN] = {0};
string maxPaliLen[LEN][LEN] = {""};
string str;
class Solution {
public:
    string longestPalindrome(string s) {
        str = s;
        int len = s.size();
        for(int i=0 ; i<=len;i++)
                for(int j=0 ; j<=len  ;j++) maxPaliLen[i][j] ="";
        if(isPalindrome(0,len-1)) return s;
        return subStrPalindrome(s,0,len-1);
    }
    string subStrPalindrome(string s,int start,int end){
            int len = s.size();
            if(maxPaliLen[start][end] !="") return maxPaliLen[start][end];
            if(isPalindrome(start,end)) {
               maxPaliLen[start][end] =s; return s;
            }
            if(res.size()>= len){
                maxPaliLen[start][end] =res; return res;
             }
            string leftS = s.substr(0,len-1);
            string rightS = s.substr(1,len-1);
            leftS = subStrPalindrome(leftS,start,end-1);
            rightS = subStrPalindrome(rightS,start+1,end);
            int leftLen = leftS.size() , rightLen = rightS.size();
            if(leftLen > rightLen) {
                if(res.size() < leftLen) res = leftS;
                maxPaliLen[start][end] =leftS; return leftS;
            }
            if(res.size() < rightLen) res = rightS;
            maxPaliLen[start][end] =rightS;
            return rightS;
    }

    bool isPalindrome(int start,int end){
        if(start >= end  || palindrome[start][end] == 1) return true;
        if(palindrome[start][end] == -1) return false;
        if(str[start] == str[end] && isPalindrome(start+1,end-1)) {
            palindrome[start][end]  = 1;
            return true;
        }
        palindrome[start][end] = -1;
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.longestPalindrome("9900887867657565656544444445435433454345ŝ")<<endl;
    return 0;
}
