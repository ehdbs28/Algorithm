<div align='center'>

# LV.2
#### 레벨 2 수준 문제들을 모아둔 폴더입니다. <br><br>

### ⌛[**해결중**]⌛
<br>

<div align='left'>

### 1. 피보나치 수<br>
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/12945)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_2/LV2_Fibonacci%20numbers.cpp)

피보나치 수는 
```
F(n) = F(n - 1) + F(n - 2) 이 적용되는 수
```
0, 1, 1, 2, 3, 5, ...
<br>이런식으로 이어지는 수열이다.

n번째 피보나치 수를 구하는 문제였는데 피보나치 수열 문제는 워낙 많이 보이는 유형이기도 하여 간단한 로직으로 해결하였다.

```cpp
vector<int> fibonacciNumbers = {0, 1};
int answer = 0;

for(int i = 0; i < n; i++){
    int back = fibonacciNumbers[fibonacciNumbers.size() - 2];
    int front = fibonacciNumbers.back();

    fibonacciNumbers.push_back((back + front) % 1234567);
}

answer = fibonacciNumbers[n];
return answer;
```
