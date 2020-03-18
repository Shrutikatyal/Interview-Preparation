/*
 * Author : Shruti Katyal
 * Date   : 08 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Letter {
    public:
    int count;
    char val;
    Letter(int c, char v) {
        count = c;
        val = v;
    }
};

struct myComp {
    bool operator()(Letter a, Letter b) {
        return a.count == b.count? a.val > b.val :a.count < b.count;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<Letter, vector<Letter>, myComp> pq;
        vector<int> count(26,0);
        int n = S.size();
        string res = "";
        
        for(char ch : S) count[ch - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(count[i] > 0) {
                if(count[i] > (n+1)/2)
                    return res;
                pq.push(Letter(count[i],'a'+i));
            }
                
        while(pq.size() >= 2) {
            Letter char1 = pq.top();
            pq.pop();
            Letter char2 = pq.top();
            pq.pop();
            
            /*This code turns out to be superfluous, but explains what is happening
            if (ans.length() == 0 || mc1.letter != ans.charAt(ans.length() - 1)) {
                ans.append(mc1.letter);
                ans.append(mc2.letter);
            } else {
                ans.append(mc2.letter);
                ans.append(mc1.letter);
            }*/
            
            // This code is not required because if it is possible to form a string, the letter written second can never be written first in the very next writing.
            
            res += char1.val;
            res += char2.val;
            
            if(--char1.count > 0)  pq.push(char1);
            if(--char2.count > 0)  pq.push(char2);
            
        }
        
        if(pq.size()>0) {
            res += pq.top().val;
            pq.pop();
        }
        
        return res;
    }
};
