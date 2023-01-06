<div align='center'>

# LV.1
#### 레벨 1 수준 문제들을 모아둔 폴더입니다. <br><br>

### ⌛[**해결중**]⌛
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