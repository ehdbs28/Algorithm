#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    cin.tie(NULL);
    //cpp에서의 cin과 cout은 기본적으로 묶여 있음 ex. cout << "이름을 입력" cin >> name
    //이면 먼저 이름을 입력이 출력되고 입력 받음
    //.tie(NULL)은 그 묶음을 풀어주는 용도 -> 위 예시 상황일때 입력을 먼저 받고 출력될 수도 있음

    ios_base::sync_with_stdio(false); 
    //sync_with_stdio 구문은 c의 stdio와 cpp의 iostream을 동기화 시켜주는 역할
    //false를 시켜줌에 따라 cpp만의 독립적인 버퍼 생성 -> 속도 빨라짐
    //단 C 문법을 사용할 경우 엉뚱한 결과 값 도출

    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int a, b;
        cin >> a >> b;
        cout << a + b << "\n";
    }
}