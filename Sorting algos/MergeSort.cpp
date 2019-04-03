#include<iostream>
using namespace std;

void merge(int input[], int si, int ei)
{
  int* output = new int[ei - si + 1];
  int mid = (si + ei)/2;
  int i = si;
  int j = mid + 1;
  int k = 0;
  while( i <= mid && j <= ei)
  {
    if(input[i] >= input[j])
    {
      output[k] = input[j];
      k++;
      j++;
    }
    if(input[i] < input[j])
    {
      output[k] = input[i];
      i++;
      k++;
    }
    
  }
  while(i <= mid)
  {
    output[k] = input[i];
    k++;
    i++;
  }
  while(j <= ei)
  {
    output[k] = input[j];
    k++;
    j++;
  }
  for(int l = 0; l < k; l++)
  {
    input[si++] = output[l];
  }
  delete output;
  
}

void mergeSortHelper(int input[], int si, int ei)
{
  if(si >= ei)
    return;

  int mid = (si + ei)/2;

  mergeSortHelper(input, si, mid);
  mergeSortHelper(input, mid + 1, ei);
  merge(input, si, ei);
  
}

void mergeSort(int input[], int size){
	mergeSortHelper(input, 0, size - 1);
        
}
int main()
{
  int n;
  cin >> n;
  int* arr = new int[n];
  for(int i = 0; i < n; i++)
   cin >> arr[i];

   mergeSort(arr, n);
}
