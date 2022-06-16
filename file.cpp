/*Juliana Marcelino 99261 e Madalena Cunha 99267*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int max(int a, int b);
vector<int> vectorInput();
vector<int> vectorInput(vector<int> x);
void problemOne(vector<int> x);
void problemTwo(vector<int> x, vector<int> y);

int main(){
    string problem;
    vector<int> x, y;
    getline(cin, problem);

    if (problem == "1"){
        x = vectorInput();
        problemOne(x);
    }

    else if(problem == "2"){
        x = vectorInput();
        y = vectorInput(x);
        problemTwo(x, y);
    }

    return 0;
}

int max(int a, int b){
    return a > b ? a : b;
}

vector<int> vectorInput(){
    vector<int> v;
    string input, strnum;
    stringstream copy;

    getline(cin, input);
    copy << input;
    while(!copy.eof()){
        copy >> strnum;
        stringstream number(strnum);
        int x = 0;
        number >> x;
        v.push_back(x);
    }
    return v;
}

vector<int> vectorInput(vector<int> v){
    vector<int> y;
    string input, strnum;
    stringstream copy;
    sort(v.begin(), v.end());

    getline(cin, input);
    copy << input;
    while(!copy.eof()){
        copy >> strnum;
        stringstream number(strnum);
        int x = 0;
        number >> x;
        if(binary_search(v.begin(), v.end(), x)){
            y.push_back(x);
        }
    }
    return y;
}

void problemOne(vector<int> vec){
    int c = 1, t = 1;
    int size = vec.size();
    int len[size], cou[size];
    bool equal = true;

    if(size == 1){
        cout << t << ' ' << c << endl;
        return;
    }
    else{
        t = 0;
        c = 0;
    }
    
    for(int i = 0; i < size; i++){
        len[i] = 1;
        cou[i] = 1;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(vec[j] < vec[i] && len[j] + 1 > len[i]){
                len[i] = len[j] + 1;
                cou[i] = cou[j];
                t = max(len[i], t);
            }
            else if(vec[j] < vec[i] && len[j] + 1 == len[i]){
                cou[i] += cou[j];
            }
            if(vec[j] != vec[i]){
                equal = false;
            }
        }
    }

    if(equal == true){
        c = vec.size();
        t = 1;
    }
    else{
        for(int i = 0; i < size; i++){
            if(len[i] == t){
                c += cou[i];
            }
        }
    }
    
    cout << t << ' ' << c << endl;
}

void problemTwo(vector<int> x, vector<int> y){
    int aux = 0, t = 0;
    int sizeX = x.size();
    int sizeY = y.size();
    int sizeMax = max(sizeX, sizeY);
    int vec[sizeMax];
    
    for(int i = 0; i < sizeMax; i++){
        vec[i] = 0;
    }

    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            if (x[i] == y[j]){
                vec[j] = max(aux + 1, vec[j]);
            }
            else if(x[i] > y[j]){
                aux = max(aux, vec[j]);
            }
        }
        aux = 0;
    }

    for(int i = 0; i < sizeMax; i++){
        t = max(t, vec[i]);
    }

    cout << t << endl;
}