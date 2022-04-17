#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> list;

int main(){
    string str_list;
    cout << "Your list (1,2,3 ...): ";
    cin >> str_list;
    string tempstr;
    for(char letra : str_list){
        if(letra != ','){
            tempstr += letra;
        }else{
            stringstream ss; 
            int num;
            ss << tempstr;
            ss >> num;
            list.push_back(num);
            tempstr = "";
        }
    }
    stringstream ss; 
    int num;
    ss << tempstr;
    ss >> num;
    list.push_back(num);

    int max_sum;
    int start;
    int end;
    int max_sum_arr_sum;
    int max_sum_arr_sum_start;
    int max_sum_arr_sum_end;
    for(int i = 0; i < list.size(); i ++){
        if(i == 0){
            max_sum = list[i];
            start = 1;
            end = 1;
            cout << max_sum << ",";
        }
        else{
            if(max_sum + list[i] > list[i]){
                max_sum = max_sum + list[i];
                end++;
                cout << max_sum << ",";
            }
            else{
                max_sum = list[i];
                start = i + 1;
                end = i + 1;
                cout << max_sum << ",";
            }
        }
        if(max_sum > max_sum_arr_sum){
            max_sum_arr_sum = max_sum;
            max_sum_arr_sum_start = start;
            max_sum_arr_sum_end = end;
        }
    }

    cout << "The sum is " << max_sum_arr_sum << " in the interval " << max_sum_arr_sum_start << " to " << max_sum_arr_sum_end;

    
}