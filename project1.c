#include <stdio.h>
#include <stdlib.h>

/*
This is the main file
@author Zelig Garza
@author Katherine Raguini
*/

//Make a merge sort and tweak it

//Merge Sort (For larger information)



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

	if (startarr==NULL) {
	printf("No memory available");
	}	

	if (argc < 1) {
		printf("Not enough arguments");
			return 1;
	}

	inputfile = argv[1];
	if ((senor = fopen(inputfile,"r")) == NULL){
			printf("Program cannot open the file\n");
			return -1; /* exit program */
			}
	printf("outside loop\n");	
	while(fscanf(senor,"%f",&startarr[num_read]) != EOF){
		num_read++;

		/* check size of array */
		if (num_read == size)
		{
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
		if(num_read%2 != 0) n2++;
		float *v1 = malloc(n1*sizeof(float)); /* float v1[n1] array */
		float *v2 = malloc(n2*sizeof(float)); /* float v2[n2] array */
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


	free(v1);
	free(v2);
	free(startarr);
	fclose(senor);
return 0;
}

	

