<div align='center'>

# Data Structure 2
#### Map, Set, Priority Queu의 자료구조를 이용해서 해결하는 문제들이 있습니다. <br><br>

### ⌛[**진행중**]⌛
<br>

<div align='left'>

### 1. 나는 포켓몬마스터 이다솜
> #### [1620 나는 포켓몬마스터 이다솜](https://www.acmicpc.net/problem/1620)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/1620_Im_PoketmonMaster_Dasom.cpp)

처음에는 문자열 전체를 인수로 받아서<br>문자열이 알파벳으로 이루어져 있는지 아닌지를 판단하는 함수를 직접 만들어 구현하는 방법을 사용하였다.

```cpp
bool IsOnlyAlphabet(string value){
    for(char ch : value){
        if(!isalpha(ch))
            return false;
    }

    return true;
}
```

하지만 이러한 방식을 사용하다 보니 범위기반 for문을 많이 사용하게 되어 시간초과 이슈가 자주 발생하였다.

생각해보니 문자열 전체를 굳이 판단하지 않고 문자열에 앞자리가 **숫자인지 알파벳인지** 정도만 파악해도 굳이 상관없는 문제였다.<br>문자가 숫자인지 판단해주는 `isdight`함수를 사용하여 로직을 이에 맞게 변경하였다.

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

<br><br>

### 3. 최대 힙
> #### [11279 최대 힙](https://www.acmicpc.net/problem/11279)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/11279_Max%20Heap.cpp)

이 문제는 최대 힙을 이용하여 배열에서 가장 큰 수를 출력하는 문제이다.

완전이진트리 구조로 큰수가 무조건 위로 올라오게 되는 `priority queue`를 사용하여 문제를 해결하였다.

```cpp
if(input == 0){
    if(!heap.empty()){
        answer = heap.top();
        heap.pop();
    }
    cout << answer << "\n";
}
else{
    heap.push(input);
}
```
priority queue의 자료구조만 알고있다면 간단하게 풀 수 있는 쉬운 문제였다.

<br><br>

### 4. 절대값 힙
> #### [11286 절대값 힙](https://www.acmicpc.net/problem/11286)
> #### [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/11286_%20Absolute%20Heap.cpp)

이 문제는 위에 문제와 비슷한 문제인데 이번에는 절대값이 가장 작은 수를 출력하는 문제이다.

위와 같은 로직으로 구성하였지만 **priority queue의 정렬기준을 다르게 주어** 절대값순으로 queue가 구성되도록 하여 문제를 해결하였다.

```cpp
// priority queue의 정렬 로직
struct Absolute
{
    bool operator()(int t, int u){
        if(abs(t) > abs(u)){
            return true;
        }
        else if(abs(t) == abs(u)){
            return u < 0;
        }
        else{
            return false;
        }
    }
};
```

<br><br>

### 5. 이중 우선순위 큐
> #### [7662 이중 우선순위 큐](https://www.acmicpc.net/problem/7662)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure2/7662_Double%20Priority%20Queue.cpp)

이 문제를 간단하게 설명한다면 단순히 가장 큰 값과 가장 작은 값에 접근 할 수 있는 priority queue를 만드는 문제이다.

문제를 보자마자 priority queue를 활용하여 푸는 문제인가 싶었지만 그러자기엔 맨 앞에 인덱스에 접근하기가 어렵기 때문에 기본적으로 오름차순으로 정렬되는 set 자료구조를 활용하여 문젤를 해결하기로 하였다.

이 문제를 통해서 반복자에 관해 몰랐던 점을 한가지 알게 되었는데

```
[ 5 ], [ 3 ], [ 2 ]
```

이러한 vector형 배열에서 v.end()를 사용해 반복자를 가져오게 되면 배열에 마지막 값 다음 값을 반환한다는 것은 속히 알고있는 사실이다.

그렇다면 **마지막 값을 가져오려면 어떻게 해야할가?**

나는 당연히 **v.end() - 1을 하게되면 마지막 값이 받아와지는 줄 알았지만 이상한 값이 반환되었다**.

```cpp
cout << *(v.end() - 1); // output : ?
cout << *(--v.end()); // output : 2
```

그 이유를 알기 위해선 연산자의 차이에 대해 다시 한 번 생각해봐야 하는데
```cpp
int a = 2;

cout << a - 1; // output : 1
cout << a; // output : 2

----------------------

cout << --a; //output : 1
cout << a; //output : 1
```
이처럼 단지 `-1`을 해주는 것은 원본 값은 바뀌지 않는 반면 `--`연산자는 원본 값에 실제로 적용이 되는 연산자이다.

반복자에도 같은 개념이 적용되는데 이로인해 `--`연산자를 사용하여 실제 한 칸전에 값을 **적용**해주어야 원하는데로 마지막 값에 접근할 수 있었다. 

새로운 지식을 얻어갈 수 있는 문제였다.