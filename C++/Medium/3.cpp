/*
Given a string s, find the length of the longest substring
without duplicate characters.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string substr = "";
        int count = 0;

        for (char c : s) {
            while (substr.find(c) != string::npos) {
                substr.erase(0, 1);
            }
            substr.push_back(c);
            count++;
        }

        return count;
    }
};