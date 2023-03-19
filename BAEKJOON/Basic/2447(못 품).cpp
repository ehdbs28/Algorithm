// #include<iostream>
// #include<string>
// #include<vector>

// using namespace std;

// string GetTemplete(int n);

// string templete = "*";

// int main(){
//     int n;
    
//     cin >> n;

//     GetTemplete(n);
//     cout << templete;
// }

// string GetTemplete(int n){
//     if(n <= 1) return "";

//     string returnValue = "";
//     int center = n / 3;

//     for(int i = 0; i < n; i += (n / 3)){
//         for(int j = 0; j < n; j += (n / 3)){
//             for(int k = j * (n / 3); k < j * (n / 3) + (n / 3); k++){
//                 if(i == center && j == center){
//                     returnValue += " ";
//                 }
//                 else{
//                     returnValue += templete[k];
//                 }
//             }
//         }
//         if(i < n - (n / 3)){
//             returnValue += "\n";
//         }
//     }

//     templete = returnValue;
//     return GetTemplete(n / 3);
// }