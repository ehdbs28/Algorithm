<div align='center'>

# Data Structure 2
#### Map, Set, Priority Queu의 자료구조를 이용해서 해결하는 문제들이 있습니다. <br><br>

### ⌛[**진행중**]⌛
<br>

<div align='left'>

### 1. 나는 포켓몬마스터 이다솜
> #### [1620 나는 포켓몬마스터 이다솜](https://www.acmicpc.net/problem/1620)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/1620_Im_PoketmonMaster_Dasom.cpp)

##### 처음에는 문자열 전체를 인수로 받아서<br>문자열이 알파벳으로 이루어져 있는지 아닌지를 판단하는 함수를 직접 만들어 구현하는 방법을 사용하였다.

```cpp
bool IsOnlyAlphabet(string value){
    for(char ch : value){
        if(!isalpha(ch))
            return false;
    }

    return true;
}
```

##### 하지만 이러한 방식을 사용하다 보니 범위기반 for문을 많이 사용하게 되어 시간초과 이슈가 자주 발생하였다.

##### 생각해보니 문자열 전체를 굳이 판단하지 않고 문자열에 앞자리가 **숫자인지 알파벳인지** 정도만 파악해도 굳이 상관없는 문제였다.<br>문자가 숫자인지 판단해주는 `isdight`함수를 사용하여 로직을 이에 맞게 변경하였다.

```cpp
if(isdigit(problemInput[0])){ //is number
    cout << name[stoi(problemInput) - 1] << "\n";
}
else{ // is alphabet
    cout << PokeDex.at(stoi(problemInput) - 1) << "\n";
    cout << pokemonMap.at(problemInput) + 1 << "\n";
}
```

<br><br>

### 2. 문자열 집합
> #### [14425 문자열 집합](https://www.acmicpc.net/problem/14425)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/14425_stringSet.cpp)

이 문제는 문자열을 입력받고 해당 문자열이 문자열 집합에 존재하는지 아닌지 확인해주면 되는 간단한 문제이다.

처음에 생각한 방법은 벡터를 활용한 로직으로 푸는 방법이였다.

```cpp
for(int i = 0; i < stringSetLenght; i++){
    string input;
    cin >> input;
    stringSet.push_back(input);
}

for(int i = 0; i < answerLenght; i++){
    string input;
    cin >> input;

    if(find(stringSet.begin(), stringSet.end(), input) != stringSet.end())
        ++answer;
} 
```
이러한 로직을 활용해 해결하여 하였지만 O(n)의 시간복잡도를 가지는`find()`함수를 활용한 로직이기 때문에 전체 시간복잡도가 O(n^2)로 시간초과 문제가 게속해서 일어났다.

key를 통하여 value를 찾는 구조로 되있는 map은 어떤 값을 찾든 O(1)의 시간 복잡도를 가지기 때문에 map을 사용하여 문제를 해결하기로 하였다.

```cpp
for(int i = 0; i < answerLenght; i++){
    string input;
    cin >> input;

    if(stringSet.find(input) != stringSet.end())
        ++answer;
} 
```
로직을 수정하여 문제를 해결하였다.
