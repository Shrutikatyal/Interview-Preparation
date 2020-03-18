/*
 * Author : Shruti Katyal
 * Date   : 08 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Word {
    public:
        int count;
        string val;
        Word(int c, string v) {
            count = c;
            val = v;
        }
};

struct myComp {
    
    bool operator() (Word w1, Word w2) {
        if(w1.count != w2.count)
            return w1.count > w2.count;
        return w1.val < w2.val;
    }
    
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> count;
        vector<string> res;
        priority_queue<Word, vector<Word>, myComp> pq;  //Min Heap
        
        for(auto word : words) count[word]++;
        
        for(auto pair : count) {
            pq.push(Word(pair.second, pair.first));
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty()) {
            res.insert(res.begin(),pq.top().val);
            pq.pop();
        }
        
        return res;
    }
};
