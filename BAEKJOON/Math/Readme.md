<div align='center'>

# MathProblem
#### 수학 관련 문제들입니다. <br><br>

### ⌛[**진행중**]⌛
<br>

<div align='left'>

### 1. 공약수<br>
> #### [5618번 공약수](https://www.acmicpc.net/problem/5618)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/5618_common%20factor.cpp)

##### 단순히 자연수 n개의 공약수를 구하면 되는 간단한 문제였다.<br>
##### 자연수 n개를 배열에 저장하여 공약수를 구하는 방식을 사용하였다.<br>

```cs
int maxNum;

    int length;
    cin >> length;

    int *nums = new int[length];

    for(int i = 0; i < length; i++){
        cin >> nums[i];
    }

    maxNum = GetMaxNum(nums, length);

    for(int i = 1; i <= maxNum; i++){
        int same = 0;
        for(int j = 0; j < length; j++){
            if(nums[j] % i == 0){
                same++;
            } 
        }
        if(same >= length) cout << i << endl;
    }
```

<br>
<br>

### 2. 피로도<br>
> #### [22864번 피로도](https://www.acmicpc.net/problem/22864)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/22864_fatigue.cpp)

##### 24시간 동안 번아웃에 걸리지 않고 얼마나 일을 할 수 있는지 구하는 알고리즘 문제로 쉽게 풀었다.
<br>

``` cs
while (day > 0)
{
    fatigue += a; //먼저 피로도를 더해주기
    if(fatigue <= m){
       workAmount += b;
    }
    else{
        fatigue -= a; 
        //피로도가 게속 증가하는것을 막기위해 이미 더한 값을 빼줌
        fatigue -= c;

        if(fatigue < 0) fatigue = 0;
    }

    day--;
}
```

<br>

##### 24시간 동안의 일을 구해야 함으로 24번 반복문을 돌리고 if문으로 조건을 걸어 일을 할 때와 일을 할 수 없을때를 구분하였다.

<br><br>

### 3. 진수변환
> #### [2745번 진수변환](https://www.acmicpc.net/problem/2745)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/2745_ToDecimal.cpp)

##### 첫번째 줄에 숫자 n과 진수를 입력하여 해당 숫자를 10진수로 변환하는 알고리즘이다. <br>
##### for문 세개를 각각

```
1. 문자열을 거꾸로 돌리기
2. string값 int값으로 바꾸기
3. 진수 변환 시켜주기
```

##### 이러한 세 단계로 나누어 풀어야겠다 까지는 쉬웠지만 값이 원하는대로 도출되지 않아 조금 어려움을 겪었다 ㅜㅡㅜ.

![화면 캡처 2022-09-20 125839](https://user-images.githubusercontent.com/98889991/191164377-69049764-f5e9-4a50-9b9b-b6d318dc845c.png)

##### 처음에는 이런식으로 코드를 만들었다. <br> 하지만 진수가 커지다보니 int형으로는 오버플로우가 일어나서 long long으로 자료형을 수정하였고 <br> 아스키코드로 int형으로 바꿀때 두 자리수가 되면 두 자리수 전부가 넘어가는 것이 아닌 한자리씩 넘어가 이상한 값이 나와서 <br> 아스키코드로 변환한 값을 넣는 int형 벡터를 만들어 문제를 해결하였다.

<br>

```cpp
int main(){
    string n = "";
    int b = 0;
    long long nToInt = 0;

    vector<int> vec;

    cin >> n >> b;

    for(int i= 0; i < n.length() / 2; i++){ //문자열 거꾸로 쓰기
        char temp = n[n.length() - (i + 1)];
        n[n.length() - (i + 1)] = n[i];
        n[i] = temp;
    }

    for(int i = 0; i < n.length(); i++){ 
        if(n[i] >= 65 && n[i] <= 90){ //아스키코드를 이용하여 Char형을 Int형으로 바꿔줌
            vec.push_back(n[i] - 55);
        }
        else vec.push_back(n[i] - 48);
    }

    for(int i = 0; i < vec.size(); i++){
        long long _pow = 0;
        _pow = pow(b, i);
        nToInt += vec[i] * _pow; //진수 변환
    }

    cout << nToInt;
}
```

##### 아스키 코드를 이용한 형 변환에 대해서 공부하였고 <br>
##### math.h 라이브러리를 활용한 제곱계산에 대해서 배웠다.

<br><br>

### 4.더하기 사이클<br>
> #### [1110번 더하기사이클](https://www.acmicpc.net/problem/1110)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/1110_AddCycle.cpp)

##### 아래와 같은 더하기 사이클 로직을 만들어 다시 처음의 값까지 돌아오는 카운트를 구하는 문제이다. <br> 코드 자체는 쉽게 짤 수 있었지만 어떤 방식으로 풀어야 할지 고민하는데에 애를 많이 먹었다 ㅜ 

<br>

#### input -> 26

| 현재 카운트 | 숫자 |
|:------:|:------:|
| 1 | 68 |
| 2 | 84 |
| 3 | 42 |
| ***4*** | ***26***|

#### Count(Answer) -> 4

<br><br>

`잘못된 코드`
```cs
answer = temp[1] + to_string(((temp[0] - 48) + (temp[1] - 48))).back();
```

##### 첫 번째 자리는 입력받은 값의 맨 오른쪽 / 두번째 자리는 두 값을 더한 값의 오른쪽을 넣어야 하기 때문에 단순히 위에 코드처럼 생각했지만

<br>

##### 저런 방식을 사용할 경우 코드가 너무 길어져서 이건 아닌거 같아 새로운 방법을 고민하였다.

<br>

`메인 로직`

```cs
do{
    int value1 = queue.front() - '0';
    queue.pop();
    int value2 = queue.front() - '0';

    value1 += value2;

    queue.push(to_string(value1).back());
    cnt++;
}
while(queue.front() != input[0] || queue.back() != input[1]);

cout << cnt;
```

##### 문제 풀이의 메인 로직이다. 두자리 숫자를 기준으로 맨 오른쪽 숫자만을 남기면 되므로 선입선출 방식으로 앞자리 수를 뺄 수 있는 **Queue**를 활용한 로직을 사용하였다.

<br>

##### 입력한 값을 한자리씩 Queue에 담고 **Pop()** 을 이용하여 맨 오른쪽 자릿 수가 맨 앞으로 올 수 있게 하였다.