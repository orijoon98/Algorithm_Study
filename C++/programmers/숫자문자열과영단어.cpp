#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans = "";
    for(int i=0;i<s.size();i++) {
        if(s[i] >= '0' && s[i] <= '9') ans += s[i];
        else {
            string tmp = "";
            tmp += s[i];
            for(int j=i+1;j<s.size();j++) {
                tmp += s[j];
                if (tmp == "zero") {
                    ans += '0';
                    i = j;
                    break;
                } else if (tmp == "one") {
                    ans += '1';
                    i = j;
                    break;
                } else if (tmp == "two") {
                    ans += '2';
                    i = j;
                    break;
                } else if (tmp == "three") {
                    ans += '3';
                    i = j;
                    break;
                } else if (tmp == "four") {
                    ans += '4';
                    i = j;
                    break;
                } else if (tmp == "five") {
                    ans += '5';
                    i = j;
                    break;
                } else if (tmp == "six") {
                    ans += '6';
                    i = j;
                    break;
                } else if (tmp == "seven") {
                    ans += '7';
                    i = j;
                    break;
                } else if (tmp == "eight") {
                    ans += '8';
                    i = j;
                    break;
                } else if (tmp == "nine") {
                    ans += '9';
                    i = j;
                    break;
                }
            }
        }
    }
    answer = stoi(ans);
    return answer;
}