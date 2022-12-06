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