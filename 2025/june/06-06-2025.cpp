#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    
    char getMinChar(map<char, int>& freq) {
        for (auto x : freq) {
            if (x.second > 0)
                return x.first;
        }
        return 'a';
    }

    string robotWithString(string s) {
        stack<char> str;
        string answer = "";
        map<char, int> freq;

        for (char c : s)
            freq[c]++;
        
        for (char c : s) {
            str.push(c);
            freq[c]--;

            while (!str.empty() && str.top() <= getMinChar(freq)) {
                answer += str.top();
                str.pop();
            }
        }

        while (!str.empty()) {
            answer += str.top();
            str.pop();
        }

        return answer;
    }
};

int main() {
    Solution solution;
    string s = "bdda";
    cout << "Output: " << solution.robotWithString(s) << endl;
    return 0;
}