#include <stdio.h>
#include <stdlib.h>

/*
This Project is directed on using a divide and conquer method on a stock 
finding the most optimal buy and sell day for a list of prices

@author Zelig Garza
@author Katherine Raguini
*/

//Make a merge sort and tweak it

//Merge Sort (For larger information)
void merge(int nums [], int left, int mid, int right){
	int i, j, k;
	int n1 = mid - left - 1;
	int n2 = right - mid;

	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
	//TO DO edit this to search through array
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
       //Write the comparision
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }

}

//Quick Sort (For smaller information)

void quicksort(int nums [], int size, int first, int last){
	int i, j, pivot, tmp;
	if(first < last){
		pivot = first;
		i = first;
		j = last;
		
		while(i < j){
			while(nums[i] < nums[pivot] && i < last)
				i++;
			while(nums[j] > nums[pivot])
				j--;
			if(i<j){
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		tmp = nums[pivot];
		nums[pivot] = nums[j];
		nums[j] = tmp;
		quicksort(nums, size, first, j-1);
		quicksort(nums, size, j+1, last);
	}
}

//Finds max in pointer array
float max(float *arr, int size)
{
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

//Determines the profit of sell-buy
float buysell(float L, float R)
{
	float buy = L, sell = R;
	float profit = 0.0;
	if(buy == sell)
		return buy;
	profit = sell - buy;
return profit;	
}

//Main Driver
int main(int argc, char *argv[])
{
	char *inputfile = "";
	FILE *senor;
	float price1 = 0.0;

	int size = 10;
	int num_read = 0;
	float *left = NULL;
	float *right = NULL;
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
	printf("outside loop\n");	

	//Iterates and reallocates for more memory
	while(fscanf(senor,"%f",&startarr[num_read]) != EOF){
		num_read++;

		/* check size of array */
		if (num_read == size) {
			printf("inside array size\n");	
			size *= 2;
			/*realloc size of array to new capacity */
			startarr = (float*) realloc(startarr, size * sizeof(float));

			if (startarr == NULL){
				printf("Error allocation failed to make tmp array!!!!!\n");
				return -1;
			}
		}
	}

	/*
		printf("input numbers read: %d\n",num_read);
		printf("the start array: %f\n",startarr[0]);
		printf("the start array: %f\n",startarr[1]);
		printf("the start array: %f\n",startarr[2]);
		printf("the start array: %f\n",startarr[3]);
		printf("the start array: %f\n",startarr[4]);
		printf("the start array: %f\n",startarr[5]);
	*/


	if (num_read <= 1) return -1;	
	int n1 = num_read/2; 
	int n2 = num_read/2;

	//Adds more space to n2 if num_read is odd
	if(num_read % 2 != 0) n2++;

	//Allocates space for each pointer
	float *v1 = malloc(n1*sizeof(float)); /* float v1[n1] array */
	float *v2 = malloc(n2*sizeof(float)); /* float v2[n2] array */

	//Divides array in two
	int i = 0;
	for (; i < num_read; i++)
	{
		if (i < n1)
		{
			v1[i] = startarr[i];
		}
		else
		{
			v2[i-n1] = startarr[i];
		}
	}

		/*
		printf("the v1 array: %f\n",v1[0]);
		printf("the v1 array: %f\n",v1[1]);
		printf("the v1 array: %f\n",v1[2]);
		printf("the v2 array: %f\n",v2[0]);
		printf("the v2 array: %f\n",v2[1]);
		printf("the v2 array: %f\n",v2[2]);
		*/
	float newmaxL = max(v1,n1);
	float newmaxR = max(v2,n2);	
/*
	printf("max for left array %f\n", newmaxL);
	printf("max for right array %f\n", newmaxR);
*/

	float newminL = min(v1,n1);
	float newminR = min(v2,n2);	
	float profit = buysell(newminL,newmaxR);	
/*
	printf("min for left array %f\n", newminL);
	printf("min for right array %f\n", newminR);
*/
	printf("Profit for our buying and sell of %s dollars: %f\n",inputfile, profit);

	free(v1);
	free(v2);
	free(startarr);
	fclose(senor);
	return 0;
}

	

