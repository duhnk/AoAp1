#include <stdio.h>
#include <stdlib.h>

/*
This Project is directed on using a divide and conquer method on a stock 
finding the most optimal buy and sell day for a list of prices

@author Zelig Garza
@author Katherine Raguini
*/

//Finds max in pointer
float buysell(float L, float R)
{

	float buy = L, sell = R;
	float profit = 0.0;
	if(buy == sell)
		return buy;
	profit = sell - buy;
return profit;	
}

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
	for ( ; i < size; i++)
	{
		if (curr > arr[i])
		{
			curr = arr[i];
		}
	}

	return curr;
}
float sort(float vec[], int n){

	float profit1,profit2,profit3;
	if (n <= 1) return;	
	int n1 = n/2; 
	int n2 = n/2;

	//Adds more space to n2 if num_read is odd
	if(n % 2 != 0) n2++;

	//Allocates space for each pointer
	float *v1 = malloc(n1*sizeof(float)); /* float v1[n1] array */
	float *v2 = malloc(n2*sizeof(float)); /* float v2[n2] array */
	int iminL = 0,imaxL = 0,iminR = 0,imaxR = 0;
	//Divides array in two
	int i = 0;
	int min1 = vec[0];
	int max1 = vec[0];
	int min2 = vec[n1]; 
	int max2 = vec[n1]; 
	for (; i < n; i++)
	{
		if (i < n1)
		{
			v1[i] = vec[i];
			if (min1 > vec[i])
			{
				min1 = vec[i];
				iminL = i;
			}
			else if(max1 < vec[i])
				imaxL = i;	
		}
		else
		{
			v2[i-n1] = vec[i];
			if (min2 > vec[i])
			{
				max2 = vec[i];
				iminR = i;
			}
			else if(max2 < vec[i])
			{
				max2 = vec[i];
				imaxR = i;
			}				
		}
	}

	float minL = min(v1,n1);
	float maxL = max(v1,n1);
	float minR = min(v2,n2);
	float maxR = max(v2,n2);
	float *minAL = &minL;
	float *maxAL = &maxL;
	float *minAR = &minR;
	float *maxAR = &maxR;
	if(&minAR < &maxAR )
		printf("TRUE\n");
	else
		printf("FALSE\n");
	if(&maxAL < &maxAR)
		printf("TRUE\n");

	printf("minL = %.2f maxL = %.2f minR = %.2f maxR = %.2f\n",minL,maxL,minR,maxR);
	printf("iminL = %d imaxL = %d iminR = %d imaxR = %d\n",iminL,imaxL,iminR,imaxR);
	profit1 = buysell(minL,maxR);
	profit2 = buysell(minL,maxL);	
	profit3 = buysell(minR,maxR);
	float sortL = sort(v1,n1);
	float sortR = sort(v2,n2);
	printf("profit1 = %.2f profit2 = %.2f profit3 = %.2f\n",profit1,profit2,profit3);
	printf("sortL = %.2f sortR = %.2f \n",sortL,sortR);

	if ( profit1 < profit3 && (&minAR < &maxAR))
		return profit1;
	else if (profit1 > profit3)
	      return profit1;
	else
		return profit3;	

	free(v1); free(v2);
}
/*
float buysell(float L, float R)
{
	float buy = L, sell = R;
	float profit = 0.0;
	if(buy == sell)
		return buy;
	profit = sell - buy;
return profit;	
}
*/
//Main Driver
int main(int argc, char *argv[])
{
	char *inputfile = "";
	FILE *senor;
	float price1 = 0.0;

	int size = 10;
	int num_read = 0;
	float *startarr;
	startarr =(float*) malloc(size * sizeof(float));

	if (startarr==NULL) {
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
	float index = sort(startarr,num_read);	
	/*
		printf("input numbers read: %d\n",num_read);
		printf("the start array: %f\n",startarr[0]);
		printf("the start array: %f\n",startarr[1]);
		printf("the start array: %f\n",startarr[2]);
		printf("the start array: %f\n",startarr[3]);
		printf("the start array: %f\n",startarr[4]);
		printf("the start array: %f\n",startarr[5]);
	*/


//	if (num_read <= 1) return -1;	
//	int n1 = num_read/2; 
/*	int n2 = num_read/2;

	//Adds more space to n2 if num_read is odd
	if(num_read % 2 != 0) n2++;
*/
	//Allocates space for each pointer

//	float *v1 = malloc(n1*sizeof(float));  float v1[n1] array 
//	float *v2 = malloc(n2*sizeof(float));  float v2[n2] array 

	//Divides array in two
/*	int i = 0;
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
*/
		/*
		printf("the v1 array: %f\n",v1[0]);
		printf("the v1 array: %f\n",v1[1]);
		printf("the v1 array: %f\n",v1[2]);
		printf("the v2 array: %f\n",v2[0]);
		printf("the v2 array: %f\n",v2[1]);
		printf("the v2 array: %f\n",v2[2]);
		*/
/*	float newmaxL = max(v1,n1);
	float newmaxR = max(v2,n2);	
*/
/*
	printf("max for left array %f\n", newmaxL);
	printf("max for right array %f\n", newmaxR);
*/

//	float newminL = min(v1,n1);
//	float newminR = min(v2,n2);	
//	float profit = buysell(newminL,newmaxR);	
/*
	printf("min for left array %f\n", newminL);
	printf("min for right array %f\n", newminR);
*/
	printf("Profit for our buying and sell of %s dollars: %.2f\n",inputfile, index);

	free(startarr);
	fclose(senor);
	return 0;
}

	

