<div align='center'>

# Data Structure
#### 자료구조 문제들입니다. <br><br>

### ⌛[**진행중**]⌛
<br>

<div align='left'>

### 1. 스택<br>
> #### [10828 스택](https://www.acmicpc.net/problem/10828)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/10828_Stack.cpp)

##### C++에서 스트링으로 switch문을 사용하지 못한다는 것을 알았다.<br><br>

##### 처음에는 C++에 **Vector**를 사용하여 문제를 풀었다.
```cpp
string command;
cin >> command;

if(command == "push"){
    int n;
    cin >> n;
    stack.push_back(n);
}
else if(command == "pop" || command == "top"){
    if(stack.empty()) cout << -1;
    else {
        cout << stack[stack.size() - 1];
        if(command == "pop") stack.erase(stack.begin() + stack.size() - 1);
    }
}
else if(command == "size"){
    cout << stack.size();
}
else if(command == "empty"){
    cout << (int)stack.empty();
}
```
##### 정답이긴 하였으나 너무 이미 있는 기능을 복붙하는것 같아서...<br> 배열을 사용하는 로직으로 바꾸었다.