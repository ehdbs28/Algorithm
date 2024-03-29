<div align='center'>

# LV.1
#### 레벨 1 수준 문제들을 모아둔 폴더입니다. <br><br>

### 🔎[**풀고싶은 것 푸는중**]🔎
<br>

<div align='left'>

### 1. 문자열나누기<br>
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/140108)
> [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_StringDivide.cpp)

이 문제는 문자열을 쭉 읽으며 처음으로 읽은 문자 **X**와 다른 글자가 나온 횟수 같은 글자가 나온 횟수가 같아질 때 문자열을 자른 후문자열이 끝날때까지 이를 반복하는 문제이다.

...

이렇게만 설명하면 알아듣기 어려우니 예제를 가져와봤다.

```
input -> "banana"

x = 'b'

b -> 같은 글자 +1
a -> 다른 글자 +1
=> 문자열 자름
---
x = 'n'

n -> 같은 글자 +1
a -> 다른 글자 +1
=> 문자열 자름
---
x = 'n'

n -> 같은 글자 +1
a -> 다른 글자 +1
=> 문자열 자름

answer -> ba | na | na -> 자른 횟수 : 3번
```

간단한 for문을 이용하여 해결하였다.

<br>

### 2. 햄버거 만들기<br>
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/133502)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_MakeAHamberger.cpp)

이 문제는 일정한 int형 배열을 입력받고 햄버거를 얼마나 만들 수 있는지 출력하면 되는 문제였다.

처음에는 
```cpp
for(int element = 0; element < ingredient.size(); element++){
    if(*(first + element) != Recipe[recipeCount])
        recipeCount = 0;

    if(*(first + element) == Recipe[recipeCount]) 
        recipeCount++;
    
    if(recipeCount != 4) continue;

    ingredient.erase(ingredient.begin() + (element - 3), ingredient.begin() + element + 1);
    answer++;
    recipeCount = 0;
    element = -1;
}
```
이런식의 로직을 작성하였다.

인자로 들어온 배열을 쭉 돌며 **넣어야 할 재료와 배열의 값이 맞으면 레시피를 한칸 지워주고** 이런식으로 쭉 레시피를 채워 레시피가 모두 차면 **배열에 해당 부분을 지워주고 다시 이런식으로 반복하는 형식**이었다.

```
input -> 2, 1, 1, 2, 3, 1, 2, 3, 1
Recipe -> [1, 2, 3, 1]

answer = 0

for
    2 -> 재료가 다름
    1 -> 재료가 같음 | Recipe -> [2, 3, 1]
    1 -> 재료가 다름 | Recipe 초기화
         재료가 같음 | Recipe -> [2, 3, 1]
    2 -> 재료가 같음 | Recipe -> [3, 1]
    3 -> 재료가 같음 | Recipe -> [1]
    1 -> 재료가 같음 | Recipe -> []
         레시피를 모두 없앰 | answer + 1
        
    ~~~~

이런식으로
```

정답은 맞게 나왔지만 for문을 게속하여 돌리면서 배열의 값도 지워야해 조금만 배열이 커지게 되면 시간이 매우 많이 걸리는 방식이었다.

곰곰히 생각해보니 배열 순서대로 판단하게 되니<br> 
`2 1 [1 2 3 1]` 이러한 방식으로 **뒤에 4개만 판단해주어도 같은 값이 나오겠다**는 생각이 들었다.

```cpp
for(int element : ingredient){
    recipe.push_back(element);

    if(recipe.size() < 4) continue;

    if(recipe[recipe.size() - 4] == 1 && recipe[recipe.size() - 3] == 2 && recipe[recipe.size() - 2] == 3 && recipe[recipe.size() - 1] == 1){
        recipe = recipe.substr(0, recipe.size() - 4);
        answer++;
    }
} 
```
생각한 방법대로 로직을 짜서 시간문제를 해결하였다.

<br>

### 3. 성격 유형 검사하기<br>
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/118666)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_Checking%20personality%20type.cpp)

이 문제는 MBTI검사처럼 검사지의 n개의 질문을 받고 각각의 질문에 대한 답을 통해 성격유형이 무엇인지 판단하는 문제이다.

```cpp
for(int i = 0; i < surveys.size(); i++){
    string survey = surveys[i];
    int choice = choices[i];
    int value = 0;
    int type = 0;
    
    string sortSurvey = survey;
    sort(sortSurvey.begin(), sortSurvey.end());

    value = choice - 4;

    switch(sortSurvey.front()){
        case 'R':
            type = 0;
            break;
        case 'C':
            type = 1;
            break;
        case 'J':
            type = 2;
            break;
        case 'A':
            type = 3;
            break;
    }

    if(sortSurvey.front() != survey.front()) value *= -1;
    types[type] += value;
}
```

이러한 로직을 사용하여 문제를 해결하였는데 이 로직은 **우선 문제를 정렬한 후 앞 문제를 비교하여 어떠한 유형을 검사하는 문제인지 부터 파악하였다**.
<br>
문제에 대한 **응답에서 4를 빼서 계산할 경우 -3 ~ 3 까지 점수를 얻을 수 있다**는 것을 알아내어 이러한 방법으로 점수를 계산해 성격유형을 계산하였다.

<br>

### 4. 없는 숫자 더하기
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/86051)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_Add%20a%20missing%20number.cpp)

이 문제는 주어진 문자열에서 빠진 숫자를 찾아내어 그 숫자를 더한 값을 출력만 해주면 되는 간단한 문제였다.

```cpp
int answer = 0;

sort(numbers.begin(), numbers.end());

for(int i = 0; i < 10; i++){
    if(numbers.front() == i)
        numbers.erase(numbers.begin());
    else{
        answer += i;
        continue;
    }
}

return answer;
```

주어진 문자열을 정렬한 다음 for문을 돌며 없는 문자를 찾아내었다.

<br>

### 5. 나머지가 1이 되는 수 찾기
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/87389)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_Find%20a%20number%20that%20leaves%201.cpp)

문제를 보자마자 `이렇게 쉬운 문제를 풀고 올려도 되나..?` `문제 잘못 골랐나 ..?` 라는 생각이 드는 문제였지만 일단 풀기로 하였다. <br>

이 문제는 말 그대로 숫자 n이 주어지고 나머지가 1이 되는 최소 수를 찾는 문제였는데 기초적인 for문과 if문을 이용하여 해결하였다.

<br>

### 6. 기사단원의 무기
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/136798)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_A%20knightly%20weapon.cpp)

이 문제는 **기사의 수**, **공격력 제한**, **제한수치 초과 시 공격력** 을 인수로 받아서 모든 기사의 무기를 만드는데에 철괴 몇개가 사용되는지 알아내는 문제이다. <br>

기사는 1번 부터 `기사의 수` 번 까지 번호를 할당받고 각 번호의 약수의 갯수로 공격력이 정해진다.<br>이 때 기사의 공격력이 `공격력 제한`을 초과한다면 해당 기사의 공격력은 `제한수치 초과 시 공격력`으로 치환된다.<br><br>기사의 무기를 만드는데에는 기사의 공격력1당 철괴 하나가 사용된다.

```
knight number = 5, limit = 3, limit power = 2

-----

1 | 1
2 | 1, 2
3 | 1, 3
4 | 1, 2, 4
5 | 1, 5

필요한 철괴 = 1 + 2 + 2 + 3 + 2 = 10
```

간단하게 소인수 분해를 이용하여 약수의 갯수를 구해주고 계산하는 방식을 사용했지만 시간초과가 떠서 좀 더 효율적인 소인수 분해 알고리즘에 대해 공부해보았다.

먼저 일반적인 약수 구하기의 로직은 이와 같다.
```cpp
for(int i = 1; i <= n; i++){
    if(n % i == 0) answer++;
}
```

하지만 생각해보면 3의 약수 `1, 3` 처럼 n의 약수가 i이면 다른 약수는 n / i 가 된다. <br> 그렇다면 굳이 약수를 구할 때 n의 끝까지 for문을 돌리지 않아도 된다는 얘기다.

```cpp
for(int i = 1; i * i <= n; i++){
    if(i * i == n) answer++;
    else if(n % i == 0) answer += 2;
}
```

이런식으로 로직을 교체하게 되면 시간복잡도 또한 `O(√n)`으로 방법 1보다 빨라지게 된다.

<br>

### 7. 부족한 금액 계산하기
> #### [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/82612)
> #### [문제풀이](https://github.com/ehdbs28/Algorithm/blob/main/PROGRAMMERS/Level_1/LV1_Calc%20the%20money.cpp)

간단한 수학 계산문제로 손쉽게 풀 수 있었다.