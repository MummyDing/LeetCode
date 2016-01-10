/*
Problem: Median of Two Sorted Arrays
Description: https://leetcode.com/problems/median-of-two-sorted-arrays/
Author: MummyDing
Date : 2016-01-10
Run Time: 6 ms
*/
public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length , n = nums2.length;
        int [] res = new int[m+n];
        int i=0 ,x=0,y=0;
        while (i<m+n){
            int minX;
            if(x< m){
                minX = nums1[x++];
            }else {
                minX = nums2[y++];
            }
            if(y<n && minX > nums2[y]){
                minX = nums2[y++];
                x--;
            }
            res[i++] = minX;
        }
        return ((double)res[i/2]+(double)res[(i-1)/2])/2.0;
    }
    public static void main(String [] str){
        Solution s = new Solution();
        s.findMedianSortedArrays(new int[]{1,4,5},new int[]{1,2});
    }
}
