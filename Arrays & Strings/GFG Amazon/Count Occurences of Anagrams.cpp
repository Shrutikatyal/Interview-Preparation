/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isCountZero(int count[26]){
    
    for(int i=0; i<26; i++)
        if(count[i])
            return false;
    
    return true;
}

int countAnagrams(string text, string word){
    
    int count[26] = {0};
    int N = text.size();
    int n = word.size();
    int ans = 0;
    
    for(int i=0; i< n; i++)
        count[word[i]-'a']++;
        
    for(int i=0; i<n; i++)
        count[text[i]-'a']--;
    
    if(isCountZero(count))
        ans++;
    
    for(int i=n; i < N; i++){
        
        //Remove first character from last window
        count[text[i-n]-'a']++;
        
        //Add last character from current window [i-n+1, i]
        count[text[i]-'a']--;
        
        if(isCountZero(count))
            ans++;
    }
    

    return ans;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    string word,text;
	    
	    cin>>text;
	    cin>>word;
	    
	    cout<<countAnagrams(text, word)<<endl;
	}
	return 0;
}
