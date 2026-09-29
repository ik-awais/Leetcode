/*
Given a string s, find the length of the longest substring
without duplicate characters.
*/
#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::string substr = "";
        int count = 0;

        for (char c : s) {
            while (substr.find(c) != std::string::npos) {
                substr.erase(0, 1);
            }
            substr.push_back(c);
            if ((int)substr.size() > count) {
                count = substr.size();
            }
        }

        return count;
    }
};