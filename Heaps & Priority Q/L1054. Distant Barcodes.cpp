/*
 * Author : Shruti Katyal
 * Date   : 08 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Digit {
    public:
    int count;
    int val;
    Digit(int c, int v) {
        count = c;
        val = v;
    }
};

struct myComp {
    bool operator()(Digit a, Digit b) {
        return a.count == b.count? a.val > b.val :a.count < b.count;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<Digit, vector<Digit>, myComp> pq;
        unordered_map<int,int> count;
        int n = barcodes.size();
        vector<int> res;
        
        for(int n : barcodes) count[n]++;
        
        for(auto pair: count) {
                pq.push(Digit(pair.second,pair.first));
            }
                
        while(pq.size() >= 2) {
            Digit dig1 = pq.top();
            pq.pop();
            Digit dig2 = pq.top();
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
            
            res.push_back(dig1.val);
            res.push_back(dig2.val);
            
            if(--dig1.count > 0)  pq.push(dig1);
            if(--dig2.count > 0)  pq.push(dig2);
            
        }
        
        if(pq.size()>0) {
            res.push_back(pq.top().val);
            pq.pop();
        }
        
        return res;
    }
};




/************************************************************************************************************************************************/
// O(n)
/************************************************************************************************************************************************/
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        short count[10001] = {};
        short max_cnt = 0, max_n = 0, pos = 0;
        
        for(int n : barcodes) {
            max_cnt = max(++count[n], max_cnt);
            max_n = (max_cnt == count[n])? n : max_n;
        }
        
        for(short i = 0; i <= 10000; i++) {
            short n = i == 0 ? max_n : i;
            while(count[n]-- > 0) {
                barcodes[pos] = n;
                pos = pos + 2 < barcodes.size() ? pos + 2 : 1;
            }
        }
        
        return barcodes;
    }
};
