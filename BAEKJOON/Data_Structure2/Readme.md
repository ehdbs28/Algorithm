<div align='center'>

# Data Structure 2
#### 자료구조2 문제들입니다. <br><br>

### ⌛[**진행중**]⌛
<br>

<div align='left'>

### 1. 나는 포켓몬마스터 이다솜
> [1620 나는 포켓몬마스터 이다솜](https://www.acmicpc.net/problem/1620)<br>
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/1620_Im_PoketmonMaster_Dasom.cpp)

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
