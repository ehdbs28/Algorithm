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


