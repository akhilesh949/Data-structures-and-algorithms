#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int min_cost(int **input, int si, int sj, int ei, int ej, int**output)
{
    if(si == ei && sj == ej)
     {
         output[ei][ej] = input[ei][ej];
          return input[ei][ej];
     }
     if(si > ei || sj > ej)
      return INT_MAX;

      if(output[si][sj] > -1)
       return output[si][sj];

    int option1 = min_cost(input, si + 1, sj, ei, ej, output);
	int option2 = min_cost(input, si + 1, sj + 1, ei, ej, output);
	int option3 = min_cost(input, si, sj + 1, ei, ej, output);
    output[si][sj] = input[si][sj] + min(option1, min(option2, option3));
	return output[si][sj];
}
int main() {
	int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;
    int **output = new int*[3];
    for(int i = 0; i < 3; i++)
     output[i] = new int[3];
     memset(output, -1, sizeof(output));

	cout << min_cost(input, 0,0,2,2, output) << endl;
	delete [] input[0];
	delete [] input[1];
	delete [] input[2];
	delete [] input;
}
