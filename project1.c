#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
/*
This Project is directed on using a divide and conquer method on a stock 
finding the most optimal buy and sell day for a list of prices

@author Zelig Garza
@author Katherine Raguini
*/


//Finds max in pointer array

float max(float *arr, int size) {
	if (arr == NULL)
	{
		printf("No array!\n");
		return -1;
	}
	float curr = arr[0];
	int i = 0;
	for ( ; i < size; i++)
	{
		if (curr < arr[i])
		{
			curr = arr[i];
		}
	}

	return curr;
}

//Finds min in array

float min(float *arr, int size)
{
	if (arr == NULL)
	{
		printf("No array!\n");
		return -1;
	}
	float curr = arr[0];
	int i = 0;
	for ( ; i < size; i++)//O(n)
	{
		if (curr > arr[i])
		{
			curr = arr[i];
		}
	}

	return curr;
}
//Finds max in pointer

float buysell(float L[], int size)
{
	int n1 = size/2; 
	int n2 = size/2;
	//Adds more space to n2 if num_read is odd
	if(size % 2 != 0) n2++;

	float *buy = malloc(n1 * sizeof(float));  
	float *sell  =	malloc(n2 * sizeof(float)); 
	float profit = 0.0;
	if(size <= 2)
		return 0;
	int ndx = 0;
	for (; ndx < size; ndx++)
	{
		if (ndx < n1)
		{
			buy[ndx] = L[ndx];
		}
		else
		{
			sell[ndx-n1] = L[ndx];
		}
	}
	float minL = min(buy,n1);
	float maxR = max(sell,n2);
	profit = maxR - minL;	
return profit ;	
}
/*
float sort(float vec[], int n){

	float profit = 0.0,profit1 = 0.0 , profit2 = 0.0;
	float sortL = 0.0; 
	float sortR = 0.0; 
	float minL = 0.0 ,maxL = 0.0 ,minR = 0.0,maxR = 0.0; 
	if (n <= 3)
	{
		printf("end of base case\n");
			
	}	


	int n1 = n/2; 
	int n2 = n/2;
	int mid = (n) /2;
	//Adds more space to n2 if num_read is odd
	if(n % 2 != 0) n2++;

	//Allocates space for each pointer
	float *v1 = malloc(n1*sizeof(float)); 
	float *v2 = malloc(n2*sizeof(float)); 
	int iminL = 0,imaxL = 0,iminR = 0,imaxR = 0;
	
	//Divides array in two
	int ndx = 0;
	for (; ndx < n; ndx++)
	{
		if (ndx < n1)
		{
			v1[ndx] = vec[ndx];
			minL = min(v1,n1);
			maxL = max(v1,n1);
		}
		else
		{
			v2[ndx-n1] = vec[ndx];
			minR = min(v2,n2);
			maxR = max(v2,n2);
		}
	profit = buysell(min(v1,n1),max(v2,n2));

	}

		
	sortL = sort(v1,n1);
	sortR = sort(v2,n2);

	if ( profit > sortL && profit > sortR)
		return profit;
	else if ( sortL > sortR && sortL > profit)
		return sortL;
	else 
		return sortR;
		
	free(v1); free(v2);
}

*/
float maxSubArray(float center[], int size)
{
	int n = size;
	float leftSum = 0.0;
	float rightSum = 0.0;
	float centerSum = 0.0;
	int n1 = n/2; 
	int n2 = n/2;
	//Adds more space to n2 if num_read is odd
	if(n % 2 != 0) n2++;

	//Allocates space for each pointer
	float *v1 = malloc(n1*sizeof(float)); 
	float *v2 = malloc(n2*sizeof(float)); 
	if (n  <= 3){
		leftSum = buysell(v1,n1);
		rightSum = buysell(v2,n2);
		centerSum = buysell(center,n);
		return centerSum;
	}	
	
	//Divides array in two
	int ndx = 0;
	for (; ndx < n; ndx++)
	{
		if (ndx < n1)
		{
			v1[ndx] = center[ndx];
		}
		else
		{
			v2[ndx-n1] = center[ndx];
		}
	}
	
	 maxSubArray(v1,n1);
	 maxSubArray(v2,n2);
	leftSum = buysell(v1,n1);
	rightSum = buysell(v2,n2);
	centerSum = buysell(center,n);
	if (centerSum > rightSum)
		return centerSum;
	else if(leftSum > rightSum)
		return leftSum;
	else
		return rightSum;
	n--;	
}
//Main Driver
int main(int argc, char *argv[])
{
	char *inputfile = "";
	FILE *senor;

	int size = 10;
	int num_read = 0;
	float *startarr;
	startarr =(float*) malloc(size * sizeof(float));

	if (startarr == NULL) {
	printf("No memory available");
	}	

	if (argc < 1) {
		printf("Not enough arguments");
			return 1;
	}

	//Reads File
	inputfile = argv[1];
	if ((senor = fopen(inputfile,"r")) == NULL){
		printf("Program cannot open the file\n");
		return -1; /* exit program */
	}

	//Iterates and reallocates for more memory
	while(fscanf(senor,"%f",&startarr[num_read]) != EOF){
		num_read++;

		/* check size of array */
		if (num_read == size) {
			size *= 2;
			/*realloc size of array to new capacity */
			startarr = (float*) realloc(startarr, size * sizeof(float));

			if (startarr == NULL){
				printf("Error allocation failed to make tmp array!!!!!\n");
				return -1;
			}
		}
	}
	float index = maxSubArray(startarr,num_read);
	//float index = sort(startarr,num_read);
	//printf("max subarray indices: %d, %d\n",maxlow,maxhigh);
	//printf("max subarray sum: %d\n",maxsum);	
	printf("Profit for our buying and sell of %s dollars: %.2f\n",inputfile, index);

	free(startarr);
	fclose(senor);
	return 0;
}

	

