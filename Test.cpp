
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

int main(){
    //insert
    int r_sum;
    vector<int> solution;
    bool quit = false;
    while(quit == false){
        cout << "Enter a number: " << endl;
        cin >> r_sum;
        if(solution.size() < 3){
            if(std::find(solution.begin(), solution.end(), r_sum) == solution.end()){
                solution.insert(solution.begin(), r_sum);
                //greater<int>() is undefinded behavior
                std::sort(solution.begin(), solution.end(),  greater<int>()); 
            }
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
        for(int i = 0; i < (int)solution.size(); ++i){
            cout << solution[i] << " ";
        }
        cout << endl <<"Continue(0 = yes, 1= no)?" << endl;
        cin >> quit;
    }
    return 0;
}