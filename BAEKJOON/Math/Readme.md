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
##### 자연수 n개를 배열에 저장하여 공배수를 구하는 방식을 사용하였다.<br>

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
> #### [22864번 공약수](https://www.acmicpc.net/problem/22864)
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


