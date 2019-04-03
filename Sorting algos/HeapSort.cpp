
void inplaceHeapSort(int input[], int n)
{
  //build heap within the array
  
  
  for(int i = 1; i < n; i++)
  {
    int ci = i; 
    while(ci > 0)
    {
      int pi = (ci - 1)/2;

      if(input[ci] < input[pi])
      {
        int temp = input[ci];
        input[ci] = input[pi];
        input[pi] = temp;
      }
      else break;
      ci = pi;
    }
    
  }
  //down-heapifying elements
  
  int size = n;
  
 while(size > 1)
 {
  int temp = input[0];
  input[0] = input[size - 1];
  input[size - 1] = temp;
  size--;
  
  int pi = 0;

    int li = 2*pi + 1;
    int ri = 2*pi + 2;
   
  while(li < size)
  {
  
    
    int mi = pi;
    
    if(input[mi] > input[li])
      mi = li;
    
    if(input[mi] > input[ri] && ri < size)
      mi = ri;

    if(mi == pi)
      break;
    
    int t = input[mi];
    input[mi] = input[pi];
    input[pi] = t;
    
     pi = mi;
     li = 2*pi + 1;
     ri = 2*pi + 2;
    
    }
 }
  
}
