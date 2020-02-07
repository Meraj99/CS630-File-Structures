#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){

    int n, blocks[50], key, lower, upper, middle;
    
    cout << "Enter the number of blocks." << endl;
    cin >> n;
    
    cout << "Enter the data." << endl;
    for(int i = 0; i < n; i++)
        cin >> blocks[i];
        
    cout << "Data:" << endl;
    for(int i = 0; i < n; i++)
        cout << blocks[i] << "\t";
    cout << endl;
    
    sort(blocks, blocks + n);
    
    cout << "Sorted data:" << endl;
    for(int i = 0; i < n; i++)
        cout << blocks[i] << "\t";
    cout << endl;
    
    cout << "Enter data to search for." << endl;
    cin >> key;
    
    lower = 0;
    upper = n - 1;
    while(upper >= lower){
        middle = (lower + upper) / 2;
        if(key < blocks[middle])
            upper = middle - 1;
        else if(key > blocks[middle])
            lower = middle + 1;
        else if(key == blocks[middle]){
            cout << "Data found at position " << middle + 1 << "." << endl;
            break;
        }
    }
    
    if(upper < lower)
        cout << "Data not present." << endl;
    
    

    return 0;
}
