/*
 * Author : Shruti Katyal
 * Date   : 04 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
     /*
     1. Sort courses by the end date, this way, when we're iterating through the courses, we can switch out         any previous course with the current one without worrying about end date.
     2. Next, we iterate through each course, if we have enough days, we'll add it to our priority queue. If        we don't have enough days, then we can either
        2.1 ignore this course OR
        2.2 We can replace this course with the longest course we added earlier.*/   
        
        auto comp = [](const vector<int> &v1, const vector<int> &v2){return v1[1] < v2[1];};
        
        sort(courses.begin(),courses.end(),comp);
        
        //Max priority queue
        priority_queue<int> pq;
        int time = 0;
        
        for(auto &course:courses){
            
            //Push duration of course into heap;
            pq.push(course[0]);
            
            time += course[0];  
            
            //If pushing a new course increases the time then pop the longest course
            if(time > course[1]){
                time -= pq.top();
                pq.pop();
            }
            
        }
        
        return pq.size();
    }
};
