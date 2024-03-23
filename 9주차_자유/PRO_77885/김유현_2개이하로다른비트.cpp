#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers) {
        if (num % 2 == 0) {
            answer.push_back(num + 1);
        } else {
            long long b = 1;
            while(true) {
                if ((num & b) == 0) {
                    break;
                }    
                b *= 2; 
            }
            
            answer.push_back(num + (b/2));
        }
    }    

    return answer;
}