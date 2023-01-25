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

##### C++에 **Vector**를 사용하여 문제를 풀었다.
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
<!-- ##### 정답이긴 하였으나 너무 이미 있는 기능을 복붙하는것 같아서...<br> 배열을 사용하는 로직으로 바꾸었다. -->

<br><br>


### 2. 괄호<br>
> #### [9012 괄호](https://www.acmicpc.net/problem/9012)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/9012_Parenthesis%20String.cpp)
##### 괄호로 이루어진 문자열이 VPS 인지 아닌지 판단하는 문제이다.

<br>

```
VPS? -> 한 쌍의 괄호 기호로 된 "()"를 VPS 라고 한다.
        만일 X가 VPS라면 (X)도 VPS가 된다.
```

```
EX). ())(() <- VPS가 아님
     ((())) <- VPS가 맞음
```

```cpp
for(int i = 0; i < lenght; i++){
    if(st[i] == '(' && st[i + 1] == ')'){
        st.erase(st.begin() + i);
        st.erase(st.begin() + i);

        i = -1;
    }
}
```
##### 문자열에서 **"()"** 인 부분을 판단하여 지우고
##### for문이 끝난 후 문자열이 비어있으면 VPS 으로 판단하였다.

<br><br>

### 3. 큐2
> #### [18258 큐2](https://www.acmicpc.net/problem/18258)
> [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/18258_queue2.cpp)

<br>

##### 이 문제는 첫 번째 문제와 비슷한 방법으로 풀면 되지만
##### 괜히 ***에잉 스택으로 풀면 이미 있는 기능 쓰는거잖아;; 배열로 풀어***
##### 라는 말을 해버려서... 꽤나 생각하는데에 힘들었다.

![image](https://user-images.githubusercontent.com/98889991/196065073-8d76f101-4564-4686-bd61-eb677f3e77aa.png)
###### 꽤나 화려한 전적...

<br>

##### 중간중간 시간초과가 뜨는 이슈가 있었는데
```cs
ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
```
##### C와의 sync를 해제하고 cout과 cin를 untie하여 해결하였다.

<br><br>
    
### 4. 요세푸스 문제
> #### [1158 요세푸스 문제](https://www.acmicpc.net/problem/1158)
> #### [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/1158_%20Josephus%20Problem.cpp)
    
##### 이 문제는 N까지의 숫자를 순서대로 K번째 순으로 제거하여<br>제거 된 순서를 출력하는 문제이다.
    
##### 처음에는 배열을 사용하여 풀려고 하였으나.
```
숫자가 모두 제거되었는지 계산.
    
K번째 숫자가 무엇인지 계산.
    
배열을 넘어가면 처음으로 돌아가기.
```
##### 위에 계산을 모두하다보니 당연히 **시간초과** 문제로 고생하였다.<br>계산을 줄이기 위해 **원형 큐**를 만들어서 문제를 해결하였다.
    
```cpp
for(int i = 1; !_queue.empty(); i++){
    if(i % k == 0){
        if(_queue.size() == 1){
            cout << _queue.front();
        }
        else{
            cout << _queue.front() << ", ";
        }

        _queue.pop();
    }
    else{
        int temp = _queue.front();
        _queue.pop();
        _queue.push(temp);
    }
}
```
   
<br><br>

### 5. 카드2
    
> #### [2164 카드2](https://www.acmicpc.net/problem/2164)
> #### [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/2164_Card2.cpp)
    
##### 앞에 문제를 응용하여 이 문제 또한 원형큐를 만들어서 해결하였다.
    
##### 앞에 문제와 로직이 굉장히 비슷한 응용격인 문제라서 굉장히 쉽게 풀 수 있었다.

<br><br>

### 6. 덱
> #### [10866 덱](https://www.acmicpc.net/problem/10866)
> #### [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/10866_Deque.cpp)

##### Deque를 구현하는 문제였다. 한번도 이용해본적없는 자료구조여서 생각하기 힘들었다..
##### 다른 부분은 해결하기 쉬웠지만 ***push_front*** 일 때 배열 앞에 값을 추가시켜주어야 하는데 어떻게 풀어야 할 지 감이 안잡혀서 조금 애먹었다.

```cpp
if(order == "push_front"){
    int n;
    cin >> n;
    for(int i = back; i >= 0; i--){
        deque[i + 1] = deque[i];
    }
    back++;
    deque[front + 1] = n;
}
```
##### for문을 이용하여 배열을 한칸씩 뒤로 밀어주는 방식을 이용해 해결하였다.

<br><br>

### 7. 후위 표기식2
> #### [1935 후위 표기식2](https://www.acmicpc.net/problem/1935)
> #### [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/1935_Postfix2.cpp)

##### 우선 후위 표기식이란?

```
우리가 평소 쓰는 계산식과 다르게 
연산자를 뒤에 붙이는 것을 후위 표기식이라고 한다

순서대로 읽는 컴퓨터가 계산할 때 편한 방법이라고 한다..
```

```
ex)
후위 표기식 -> AB*
중위 표기식 -> A*B
```

##### stack을 사용하여 하나하나 계산해주며 쉽게 해결하였다.

##### 문제를 해결하면서 문자가 알파벳인지 판단해주는 `isalpha()`라는 함수가 있다는 것을 처음알았다.<br>또한 소수점을 조절하는 방법인 `fixed`와`precision`또한 새로 알게 되었다.