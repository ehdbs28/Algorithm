#include<iostream>

using namespace std;

void merge_sort(int* array, int start, int end, int findIndex);
void merge(int* array, int start, int split, int end, int findIndex);

int count = 0;

int main(){
    int array[500000];
    int arraySize, findIndex;

    cin >> arraySize >> findIndex;

    for(int i = 0; i < arraySize; i++)
        cin >> array[i];

    merge_sort(array, 0, arraySize, findIndex);

    if(count < findIndex) cout << "-1";
}

void merge_sort(int* array, int start, int end, int findIndex){
    if((end - start) > 1){
        int split = abs((start + end + ((start + end) & 2 != 0)) / 2);
        merge_sort(array, start, split, findIndex);
        merge_sort(array, split, end, findIndex);
        merge(array, start, split, end, findIndex);
    }
}

void merge(int* array, int start, int split, int end, int findIndex){
    int temp[500000];

    int start_index = start, split_index = split, temp_index = 0;

    while(start_index < split && split_index < end){
        if(array[start_index] <= array[split_index]){
            temp[temp_index++] = array[start_index++];
        }
        else{
            temp[temp_index++] = array[split_index++];
        }
    }

    while(start_index < split){
        temp[temp_index++] = array[start_index++];
    }
    while(split_index < end){
        temp[temp_index++] = array[split_index++];
    }

    for(int i = start; i < end; i++){
        ++count;
        if(count == findIndex){
            cout << temp[i - start];
            return;
        }
        array[i] = temp[i - start];
    }
}