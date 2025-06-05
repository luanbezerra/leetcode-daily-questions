#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UnionFind{

    vector<int> parent = vector<int>(26, -1);

public:
    UnionFind(){

        for (int i = 0; i < 26; i++){
            parent[i] = i;
        }
    }

    int findSet(int x){

        if (parent[x] == x)
            return x;
        return parent[x] = findSet(parent[x]);
    }

    void uniteSet(int x, int y){

        x = findSet(x);
        y = findSet(y);

        if (x != y){
            if (x < y)
                parent[y] = x;
            else
                parent[x] = y;
        }
    }
};

class Solution{

public:
    string smallestEquivalentString(string s1, string s2, string baseStr){

        UnionFind dsu = UnionFind();

        for (int i = 0; i < s1.size(); i++){
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            dsu.uniteSet(x, y);
        }
        string result = "";
        for (char c : baseStr){
            int x = c - 'a';
            result += (char)(dsu.findSet(x) + 'a');
        }
        return result;
    }
};

int main(){
    
    Solution sol;
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}