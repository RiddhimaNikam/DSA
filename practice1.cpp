#include <iostream>
#include <cstring>
//#include <cctype>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2);
};
string Solution::mergeAlternately(string word1, string word2) {
    string result="";
    int l1=word1.length() ;
    int l2=word2.length();
    int l=max(l1,l2);

            for (int i=0;i<=l;i++) {
                if(i<word1.length() && islower(word1[i]) ) {
                    result+=word1[i];
                }
                if(i<word2.length() && islower(word2[i])) {
                    result+=word2[i];
                }
             }
        return result;
    } 
    


int main() {
    Solution s ;
    string word1;
    string word2;
    cout<<"enter string: "<<endl;
    cout<<"word1: ";
    cin>>word1;
    cout<<"word2: ";
    cin>>word2;
    cout<<"merged: "<<s.mergeAlternately(word1,word2);
    return 0;
}