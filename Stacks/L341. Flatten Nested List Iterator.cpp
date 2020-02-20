/*
 * Author : Shruti Katyal
 * Date   : 17 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger> list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1;i>=0;i--)
            list.push(nestedList[i]);
    }

    int next() {
        int res = list.top().getInteger();
        list.pop();
        return res;
    }

    bool hasNext() {
        while(!list.empty()){
            
            NestedInteger curr = list.top();
            if(curr.isInteger())
                return true;
            list.pop();
            
            vector<NestedInteger>& adjs = curr.getList();
            int size = adjs.size();
            for(int i=size-1;i>=0;i--)
                list.push(adjs[i]);    
            
        }
    
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
