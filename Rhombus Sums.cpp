#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        
        vector<int> solution;
        int r_sum = 0;
        int x = 0; int y = 0;
        
        for(int i = 0; i < (int)g.size();++i){
            for(int j = 0; j < (int)g[0].size();++j){
                // j + 2 * area <= g[0].size() has a possible bug
                // condition is rhombus can't go past left wall and bottom wall
                // assume rhombus always starts on the left
                for(int size = 0; i + size < (int)g.size() && j + 2*size < (int)g[0].size() && i - size >= 0; ++size){
                //for (int size = 0; i + size < (int)g.size() && i - size >= 0 && j + 2 * size < (int)g[0].size(); ++size) { // this piece of code errors out the executable
                    x = i; y = j; r_sum = 0;
                    // x is up down, y is left right
                    //sum up diagonal right-down
                    do r_sum += g[x++][y++]; while(x < i + size);
                    if(size > 0){ // no diagonals in rhombus of zero area
                        // sum up diagonal up right
                        do r_sum += g[x--][y++]; while(x > i); //******
                        // sum up diagonal up left
                        do r_sum += g[x--][y--]; while(x > i - size);
                        // sum up diagonal down left
                        do r_sum += g[x++][y--]; while(x < i );
                    } 
                    //insert
                    if(solution.size() < 3){
                        //std::find in <algorithm>, checks if solution contains r_sum
                        if(std::find(solution.begin(), solution.end(), r_sum) == solution.end()){ // checks if r_sum is not in solution
                            solution.insert(solution.begin(), r_sum);
                            sort(solution.begin(), solution.end(),  greater<int>()); 
                        }
                        //greater<int>() is undefinded behavior
                    }
                    else{
                        if(std::find(solution.begin(), solution.end(), r_sum) == solution.end()){
                            for(int i = 0; i < 3; ++i){
                                if(r_sum > solution[i]){
                                    solution.insert(solution.begin() + i,r_sum );
                                    solution.pop_back();
                                    break;
                                }
                            }
                        }         
                    }
                }
            }
        }
        return solution;
    }
};

int main(){
    //vector<vector<int>> g = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    vector<vector<int>> g = {{7,7,7}};
    Solution object;
    vector<int> answer;
    int temp;
    answer = object.getBiggestThree(g);
    for(int i = 0; i < (int)answer.size(); ++i){
        std::cout << answer[i] << " ";
    }
    //std::cout << std::endl;
    cin >> temp;
    return 0;
}


//BUG Log:
// 1. i + size < g.size; changed 2*size to just size; i is center of rhombus
// 2. changed do r_sum += g[x++][y--]; while(x < i + 2*size);, switched x++ & y-- to x-- & y++; x > i
// 3. do r_sum += g[x--][y--]; while(x > i + size); switch to x > i - size
// 4. do r_sum += g[x--][y++]; while(x > i ); switched x-- & y++ to x++ & y--; while x < i


