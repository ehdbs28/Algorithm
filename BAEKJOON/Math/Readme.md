<div align='center'>

# MathProblem
#### 수학 관련 문제들입니다. <br><br>

### ✅[**완료**]✅
<br>

<div align='left'>

### 1. 공약수<br>
> #### [5618번 공약수](https://www.acmicpc.net/problem/5618)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/5618_common%20factor.cpp)

단순히 자연수 n개의 공약수를 구하면 되는 간단한 문제였다.<br>
자연수 n개를 배열에 저장하여 공약수를 구하는 방식을 사용하였다.<br>

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

24시간 동안 번아웃에 걸리지 않고 얼마나 일을 할 수 있는지 구하는 알고리즘 문제로 쉽게 풀었다.
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

24시간 동안의 일을 구해야 함으로 24번 반복문을 돌리고 if문으로 조건을 걸어 일을 할 때와 일을 할 수 없을때를 구분하였다.

<br><br>

### 3. 진수변환
> #### [2745번 진수변환](https://www.acmicpc.net/problem/2745)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/2745_ToDecimal.cpp)

첫번째 줄에 숫자 n과 진수를 입력하여 해당 숫자를 10진수로 변환하는 알고리즘이다. <br>
for문 세개를 각각

```
1. 문자열을 거꾸로 돌리기
2. string값 int값으로 바꾸기
3. 진수 변환 시켜주기
```

이러한 세 단계로 나누어 풀어야겠다 까지는 쉬웠지만 값이 원하는대로 도출되지 않아 조금 어려움을 겪었다 ㅜㅡㅜ.
```cpp
for(int i = 0; i < n.lenght(); i++){ //문자열 거꾸로 쓰기
    char temp = n[n.lenght() - (i + 1)];
    n[i] = temp;
}

for(int i = 0; i < n.lenght(); i++){ //아스키코드를 이용한 형변환
    if(n[i] >= 65 && n[i] <= 90){
        n[i] -= 16;
    }

    nToInt += (n[i] - 48) * pow(b, i); //진수 변환
}
```
처음에는 이런식으로 코드를 만들었다. <br> 하지만 진수가 커지다보니 int형으로는 오버플로우가 일어나서 long long으로 자료형을 수정하였고 <br> 아스키코드로 int형으로 바꿀때 두 자리수가 되면 두 자리수 전부가 넘어가는 것이 아닌 한자리씩 넘어가 이상한 값이 나와서 <br> 아스키코드로 변환한 값을 넣는 int형 벡터를 만들어 문제를 해결하였다.

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

아스키 코드를 이용한 형 변환에 대해서 공부하였고 <br>
math.h 라이브러리를 활용한 제곱계산에 대해서 배웠다.

<br><br>

### 4.더하기 사이클<br>
> #### [1110번 더하기사이클](https://www.acmicpc.net/problem/1110)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/1110_AddCycle.cpp)

아래와 같은 더하기 사이클 로직을 만들어 다시 처음의 값까지 돌아오는 카운트를 구하는 문제이다. <br> 코드 자체는 쉽게 짤 수 있었지만 어떤 방식으로 풀어야 할지 고민하는데에 애를 많이 먹었다 ㅜ 

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

첫 번째 자리는 입력받은 값의 맨 오른쪽 / 두번째 자리는 두 값을 더한 값의 오른쪽을 넣어야 하기 때문에 단순히 위에 코드처럼 생각했지만

<br>

저런 방식을 사용할 경우 코드가 너무 길어져서 이건 아닌거 같아 새로운 방법을 고민하였다.

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

문제 풀이의 메인 로직이다. 두자리 숫자를 기준으로 맨 오른쪽 숫자만을 남기면 되므로 선입선출 방식으로 앞자리 수를 뺄 수 있는 **Queue**를 활용한 로직을 사용하였다.

<br>

입력한 값을 한자리씩 Queue에 담고 **Pop()** 을 이용하여 맨 오른쪽 자릿 수가 맨 앞으로 올 수 있게 하였다.

<br><br>

### 4. 최대공약수와 최소공배수<br>
> #### [2609번 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)
> [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/2609_greatest%20common%20factor%26Least%20Common%20Multiple.cpp)
두 수가 입력되고 두 수의 최대공약수와 최소공배수를 구하면 되는 간단한 수학문제 였다 !
<br>

![image](https://user-images.githubusercontent.com/98889991/191399295-6e86eca8-4fae-4b26-8861-6a604002b586.png)
최대공약수와 최소공배수를 구하는 공식은 이미 알고있었기에<br> 이 공식을 코드로 구현하여 문제를 해결하였다 !

<br>

`메인로직`

```cs
for(int i = 2; i <= max; i++){ //max 값 까지의 소수 구하기
    for(int j = 2; j <= i; j++){
        if(i % j == 0){
            if(i == j){ // i는 소수
                if(input1 % i == 0 && input2 % i == 0){ //최대공약수, 최소공배수 계산
                    GCF *= i;
                    LCM *= i;
                    input1 /= i;
                    input2 /= i;
                        
                    i = 1;
                }
            }
            break;
        }
    }
}
LCM *= input1 * input2;
```

로직에 문제는 없었지만 소인수분해를 for문으로 표현하다 보니 동일한 소인수로 연속으로 나눠지는 상황에서 재대로 된 소인수분해가 이루어지지 않아 몇몇 테스트케이스에서 답이 틀리게 나왔다.

<br>

소인수분해가 된 상황에서 **i를 초기화** 해주어서 해결하였다.

<br><br>

### 5.최소공배수<br>
> #### [1934번 최소공배수](https://www.acmicpc.net/problem/1934)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/1934_LCM.cpp)
위 문제와 동일하게 최소공배수만 출력하면 된다고 생각하여 <br> 위 문제를 응용 ~~(복붙)~~ 하려고 했었지만 시간초과가 떠버렸다... 위 문제는 소수를 먼저 구하고 그 소수와 소인수분해까지 시켜주는 과정을 한번에 돌리기 떄문에 당연히 시간초과라고 생각하여... 다시 풀어보았다.

<br>

이 문제를 해결하기 위해서 ***"유클리드 호제법"*** 을 사용하였다.

`유클리드 호제법이란?`

```
a와 b중 큰 수를 작은수로 나누었을때

나누어 떨어지면
    : 최대공약수는 b

나누어 떨어지지 않으면
    : b를 나머지를 다시 나눈 후 나머지 비교

<예제>

input => 1071, 1029

1071 / 1029 ---> 나머지 : 42
1029 / 42 ---> 나머지 : 21
42 / 21 ---> 나누어 떨어짐 !

answer => 1071과 1029의 최대공약수는 21
```

<br>

유클리드 호제법을 이용하여 재귀함수를 만들어 문제를 해결하였다 !

```cpp
int Get_GCD(int a, int b){
    int remain = a % b;

    if(remain == 0){
        return b;
    }
    else{
        return Get_GCD(b, remain);
    }
}
```

최대공약수를 구하는 새로운 방법인 유클리드 호제법에 대해서 공부할 수 있는 좋은 문제였다 !

<br><br>

### 6. 소수<br>
> #### [2581번 소수](https://www.acmicpc.net/problem/2581)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/2581_PrimeNum.cpp)
간단한 이중 for문으로 구할 수 있는 소수 문제여서 쉽게 풀었다.

```cpp
for(int i = min; i <= max; i++){
    for(int j = 2; j <= i; j++){
        if(i % j == 0){
            if(i == j) primeNums.push_back(i);
            break;
        }
    }
}
```

<br><br>

### 7. 소인수분해<br>
> #### [11653번 소인수분해](https://www.acmicpc.net/problem/11653)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/11653_Factorization.cpp)
앞서 푼 문제들과 똑같이 먼저 소수를 구한뒤에 소수로 나눠주는 작업을 해야겠다 ! 라고 생각했지만 무수한 실패와 시간초과를 경험하고 도저히 생각이 안난다 싶어서 다른 사람의 코드를 조금 참고하여 푼 문제이다.

<br>

```cpp
while(n > 1){
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            cout << i << endl;
            n /= i;
            break;
        }
    }
}
```

다른 사람의 코드를 보고 나니 내가 문제 해결 방식에 접근을 아예 잘못하고 있었단 것을 깨달았다 !.. <br> 
```
소인수 분해는 그 수가 소수로 나눠지지 않을때까지 소수로 나누는것
```
이었지만 나는 소수를 먼저 쭉 구하고 그 수를 나누려고 하고 있었다.. <br> 문제풀이에 대한 사고방식 능력을 더욱 길러야 겠다고 생각한 문제였다..

<br><br>

### 8. 소수 찾기
> #### [1978번 소수 찾기](https://www.acmicpc.net/problem/1978)
> [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/1978_FindPrimeNum.cpp)
주어진 숫자중 소수가 몇개인지 출력하는 문제로 쉽게 풀은 문제였다.

<br>

```cpp
for(int i = 0; i < cnt; i++){
    int n = 0;
    cin >> n;
    primeNum += Get_PrimeNum(n);
}
```

<br><br>

### 9. 에라토스테네스의 체
> #### [2960번 에라토스테네스의 체](https://www.acmicpc.net/problem/2960)
> [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/2960_Sieve%20of%20Eratosthenes.cpp)

처음 문제를 봤을 때 먼가 이름부터 심상치 않아보이고 굉장한 고난이 예상되었지만.<br>예상보다 많이 쉽게 풀었다?

<br>

에레스토테네스를 잘 표현한 GIF를 가져와봤다.

![117607794-b46aac80-b197-11eb-9106-7b5567fdb357](https://user-images.githubusercontent.com/98889991/192254843-2c8aa21b-f80e-4022-8968-af4131c62c12.gif)

에라토스 테네스의 체는 소수를 구하는 알고리즘중 하나인데
시간복잡도가 O(n log(logn))으로 굉장히 빠른 듯 하다.

<br>

```cpp
while(!nums.empty()){
    int temp = nums.front();

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % temp == 0){
            if(--k == 0){
                    cout << nums[i];
                    return 0;
                }

                nums.erase(nums.begin() + i);
            }
        }
    }
```

알고리즘 설명에 나온대로 풀어서 쉽게 풀 수 있었다 !
~~실력이 조금은 늘었을지도..?~~

<br><br>

### 10. LCM
> #### [5347번 LCM](https://www.acmicpc.net/problem/5347)
> [문제 풀이](https://github.com/ehdbs28/Algorithm/blob/main/BAEKJOON/Math/5347_LCM.cpp)
저번에 풀었던 최소공배수문제에서 테스트케이스의 맥스값만 인지하고 있으면 쉬운문제라 어려움은 없었다.

```cpp
for(int i = 0; i < cnt; i++){
    long long a, b = 0;
    cin >> a >> b;

    if(a < b) swap(a, b);

    cout << a * b / Get_LCM(a, b) << "\n";
}
```
                                     
<br><br>                                     
