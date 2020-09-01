/*
 * Author : Shruti Katyal
 * Date   : 01 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tens = 0, fives = 0;
        for(int i=0; i < bills.size(); i++)
            if(bills[i]==5)
                fives++;
            else if(bills[i]==10)
                    if(fives <= 0)
                        return false;
                    else
                        fives--,tens++;
            else if(bills[i]==20)
                if(tens > 0 && fives > 0)
                    tens--,fives--;
                else if(fives > 2)
                    fives -= 3;
                else
                    return false;
                
        return true;
    }
};
