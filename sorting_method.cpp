//
//  main.cpp
//  bubble_sort
//
//  Created by LiuRenxi on 2019/4/17.
//  Copyright © 2019年 Liu Renxi. All rights reserved.
//

#include <iostream>

// bubble sort

void bubblesort(int arr[], int len){
    int temp, i, j;
    for(i=1; i<=len-1; i++)
    {
        for(j=1; j<=len-i; j++)
        {
            if(arr[j-1]>arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

//交换两个变量函数，输入两个变量地址指针

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//选择排序

void selectsort(int arr[], int len)
{
    int temp, i, j;
    for(i=1; i<=len-1; i++){
        temp = i-1;
        for(j=i; j<=len-1; j++){
            if(arr[temp] > arr[j]) temp = j;
        }
        swap(&arr[i-1], &arr[temp]);
    }
}

//insertion sort

void insertionsort(int arr[], int len){
    int temp, i, j;
    for(i=1; i<=len-1; i++){
        temp = arr[i];
        j = i;
        while(arr[j-1]>temp){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}

void printlist(int arr[], int len){
    int i;
    for(i=1; i<=len; i++) printf("%d ", arr[i-1]);
    printf("\n");
}

// Quick sort

void quicksort(int arr[], int l, int r){
    int i, j, temp;
    if(l<r){
    i = l; j = r;
    temp = arr[l];
    while(i<j){
        while(i<j && arr[j]>temp) j--;
        if(i<j) {
            arr[i] = arr[j];
            i++;
        }
        while(i<j && arr[i]<temp) i++;
        if(i<j){
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = temp;
    quicksort(arr, l, i-1);
    quicksort(arr, i+1, r);
    }
}

int main(){
    int i;
    int arr[] = {3, 5, 1, 4, 10, 12, 9, 2, 4, 1, 6, 7, 3}, list[] = {3, 5, 1, 4, 10, 12, 9, 2, 4, 1, 6, 7, 3};
    int len = 13;
    for(i=1; i<=len; i++) printf("%d ", arr[i-1]);
    printf("\n");
    bubblesort(arr, len);
    printf("经过bubble sort的结果为\n");
    printlist(arr, len);
    
    for(i=1; i<=len; i++) arr[i-1] = list[i-1];
    printlist(arr, len);
    selectsort(arr, len);
    printf("经过选择排序的结果为\n");
    printlist(arr, len);
    
    for(i=1; i<=len; i++) arr[i-1] = list[i-1];
    printlist(arr, len);
    insertionsort(arr, len);
    printf("经过插入排序的结果为\n");
    printlist(arr, len);
    
    for(i=1; i<=len; i++) arr[i-1] = list[i-1];
    printlist(arr, len);
    quicksort(arr, 0, len-1);
    printf("经过快速排序的结果为\n");
    printlist(arr, len);
}
