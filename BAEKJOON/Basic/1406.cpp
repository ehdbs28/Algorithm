#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    list<char> clist;
    string input;

    cin >> input;

    for(int i = 0; i < input.length(); i++)
        clist.push_back(input[i]);

    list<char>::iterator iter = clist.end();
    int cnt;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        char order;
        char cinput;

        cin >> order;

        switch(order){
        case 'L':
            if(iter != clist.begin())
                --iter;
        break;
        case 'D':
            if(iter != clist.end())
                ++iter;
        break;
        case 'B':
            if(iter != clist.begin()){
                --iter;
                iter = clist.erase(iter);
            }
        break;
        case 'P':
            cin >> cinput;
            clist.insert(iter, cinput);
        break;
        }
    }

    for(iter = clist.begin(); iter != clist.end(); ++iter){
        cout << *iter;
    }
}