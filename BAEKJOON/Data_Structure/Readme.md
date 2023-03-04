<div align='center'>

# Data Structure
#### Queue, Stack, Deck의 자료구조를 이용해서 해결하는 문제들이 있습니다. <br><br>

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

<br><br>

### 8. 프린터 큐
> #### [1966 프린터 큐](https://www.acmicpc.net/problem/1966)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/1966_Printer%20Que.cpp)

이 문제는 일반적인 프린터 처럼 순차적으로 출력하는 것이 아닌 특정 규칙에 따라 출력하는 프린터를 만드는 문제이다.

```
1. 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
```

중요도를 체크하기 위하여 **큐의 내용물을 정렬시킨 리스트** 만들고 **현재 큐의 맨 첫번째 값과 정렬된 리스트의 마지막 값을 비교**하는 식으로 로직을 만들었다.

```cpp
while(!printerQueue.empty())
{
    if(printerQueue.front() == v.back()){ // 이게 제일 큰수
        if(index == 0)
            return (arraySize - printerQueue.size()) + 1;

        printerQueue.erase(printerQueue.begin());
        v.erase(v.begin() + v.size() - 1);
    }
    else{
        printerQueue.push_back(printerQueue.front());
        printerQueue.erase(printerQueue.begin());

        if(index == 0)
            index = printerQueue.size();
        
    }

    index--;
}
```

<br><br>

### 9. 풍선 터뜨리기
> #### [2346 풍선 터뜨리기](https://www.acmicpc.net/problem/2346)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/2346_Popping%20Balloon.cpp)

이 문제는 1부터 n까지의 풍선을 규칙에 맞게 터뜨리고 터뜨린 순서를 출력하는 문제이다.<br>규칙은 다음과 같다.

```
1. 제일 처음에는 1번 풍선을 터뜨린다.
2. 풍선 안에 있는 종이를 꺼내어 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다.
3. 종이의 숫자가 양수일 경우 오른쪽으로 음수일 경우 왼쪽으로 이동한다.
4. 이미 터진 풍선은 지나쳐서 이동한다.
```

예를 들어 다섯 개의 풍선에 차례대로 `3, 2, 1, -3, -1`이 적혀 있다면 **3이 적힌 1번 풍선**, 이동 후 **-3이 적혀 있는 4번 풍선** 이동 후 **-1이 적혀 있는 5번 풍선** ・・・

이러한 과정을 반복하여 `1, 4, 5, 3, 2` 순서로 풍선이 터지게 된다.

풍선의 이동은 `FindAIndex` 라는 함수를 만들어서 구현하였다.

```cpp
int FindAIndex(int max, int currentIndex, int value){
    int checkValue = 0;
    for(int i = ((value > 0) ? 1 : -1); ((value > 0) ? i <= value : i >= value); ((value > 0) ? i++ : i--)){
        checkValue = currentIndex + i;

        while(checkValue > max || checkValue <= 0){
            if(checkValue > max)
                checkValue -= max;
            else if(checkValue <= 0)
                checkValue = max - abs(checkValue);
        }

        if(check[checkValue - 1]){
            currentIndex += (value > 0) ? 1 : -1;
            (value > 0) ? --i : ++i;
        }
    }

    check[checkValue - 1] = true;
    return checkValue;
}
```

우선 현재 인덱스에서 목표 인덱스까지 한칸 씩 이동하며 그 칸으로 이동이 가능한지 확인하였다.

만약 이동한 칸이 이미 터진 풍선이라면 현재 인덱스를 한칸 옮겨주고 for문을 한번 더 돌리는 방식으로 구현하였다.

<br><br>

### 10. 쇠막대기

> #### [10799 쇠막대기](https://www.acmicpc.net/problem/10799)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/10799_Iron%20bar.cpp)

이 문제는 온전히 내 힘으로 풀지 못하여서 알고리즘 능력을 더욱 길러야겠다는 생각을 들게 해준 문제이다.

괄호를 이용하는 문제라 `이 문제는 Stack을 이용하여 풀어야겠다!` 라고 생각하였지만 꽤나 고생하게되었다.
스택의 pop과 push를 활용해서 어느정도 맞는 로직 정도는 짤 수 있었지만 90%만 맞을 뿐 자꾸 어디선가 버그가 있어서 100%는 맞지 못하였다.

그렇게 고민을 하던 중 스택을 사용하는것이 아닌 변수 2개만을 사용하여 문제를 해결하였다는 글을 보게되었고 **스택 사용** 이라는 관점에서 벗어나 생각해보니 답을 찾아낼 수 있었다.

스택을 사용하지 않은 아래의 로직을 사용하여 문제를 해결하였다.

```cpp
for(int i = 0; i < input.length(); i++){
    if(input[i] == '('){
        bar_count++;
    }
    else{
        bar_count--;

        if(input[i - 1] == '('){
            answer += bar_count;
        }
        else{
            answer++;
        }
    }
}
```

<br><br>

### 11. 탑
> #### [2493 탑](https://www.acmicpc.net/problem/2493)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Data_Structure/2493_Top.cpp)

이 문제는 높이가 다른 n개의 탑에서 각각 레이저를 발사하는데 어느시점에서 레이저가 막히는지 알아내는 문제이다.

레이저의 높이를 담고있는 배열구조를 만듬 다음 각각 레이저를 발사하여 레이저가 막히는 시점이 어디인지 찾아내는 방법으로 구현해야겠다고 생각했다.

처음 생각해본 방법으로는
```cpp
1. 각 탑의 높이를 담은 배열 생성
2. 배열을 돌리며 레이저 계산하기
    ㄴ 배열을 돌며 제일 큰 탑을 저장해두기
    ㄴ 현재 입력된 탑이 가장 높은 탑이라면 0 반환
    ㄴ 아니라면 가장 높은 탑에서 막히도록
3. 답 출력
```
하지만 이 로직으로는 가장 큰 탑을 지정해두고 계산을 하기 때문에 
배열이 `9, 7, 4` 이런식으로 있는 경우 4가 7에서 막혀야 하지만 9에서 막히는 등 버그가 생겼다.

가장 큰 탑을 지정하는 것이 아닌 for문을 돌려 찾는다고 해도 시간복잡도가 늘어나 문제를 해결할 순 없어서 새로운 방법을 찾아냈다.

```cpp
1. pair<int, int>를 담는 stack을 만들기
2. 레이저 계산
    ㄴ pair의 first에는 탑의 높이, second에는 탑의 인덱스 번호를 넣게 됨
    ㄴ 레이저가 막힐 때까지 pop을 시켜주며 답 추출
```

이런식으로 구현하니 시간복잡도도 줄이면서 문제도 해결할 수 있었다.