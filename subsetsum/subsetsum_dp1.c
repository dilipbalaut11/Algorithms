// A Recursive solution
// for subset sum problem
#include <stdio.h>
#include <stdbool.h> 

int count = 0;
// Returns true if there is a subset of set[]
// with sum equal to given sum
isSubsetSum(int set[], int n, int sum)
{
	count++;
	if (sum == 0)
		return true;
	if (n == 0)
		return false;
	if (set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int SS[50][50] = {0};
bool SS1[50][50] = {false};
//int count = 0;
//TODO dynamic programming
isSubsetSumDP(int set[], int n, int sum)
{
	bool result;

	
	if (SS[n][sum] != 0)
	{
		printf("exit early count=%d sum=%d\n", n, sum);
		if (SS[n][sum] == 1)
			return true;
		else
			return false;
	}

	count++;
	
	if (sum == 0)
                result = true;
        else if (n == 0)
		result = false;
        else if (set[n-1] > sum)
        	result = isSubsetSumDP(set, n-1, sum);
	else
        	result =  isSubsetSumDP(set, n-1, sum) || isSubsetSumDP(set, n-1, sum-set[n-1]);
	if (result)
		SS[n][sum] = 1;
	else
		SS[n][sum] = 2;
	return result;
}

isSubsetSumDP1(int set[], int n, int sum)
{
        bool result;
	int i, j;

	   // If sum is 0, then answer is true
	   for (i = 0; i <= n; i++)
	   	SS1[i][0] = true;
	   //
	   //                 // If sum is not 0 and set is empty,
	   //                     // then answer is false
	   for (i = 1; i <= sum; i++)
	   	SS1[0][i] = false;

	for (i =1; i <= n; i++)
	{
		for (j = 1; j <= sum; j++)
		{
			if (j < set[i - 1])
				SS1[i][j] = SS1[i-1][j];
			SS1[i][j] = SS1[i-1][j] || SS1[i-1][j-set[i-1]];			
		}
		
	}
	return SS1[n][sum]; 
}

int localset[100];
int length = 0;
//print all subset

void
printsubsetset()
{
	int i;
	int sum = 0;

	printf("\n[");
	for (i = 0; i < length; i++)
	{
		sum += localset[i];
		printf("%d ", localset[i]);
	}
	printf("]");
}

//get all the subsets
void
subset(int *set, int n, int sum)
{
	if (n == 0)
		return printsubsetset();
	if (n == 0)
		return;
	if (sum < set[n-1])
		subset(set, n-1, sum);

	subset(set, n-1, sum);

	localset[length++] = set[n-1];
	subset(set, n-1, sum - set[n-1]);
	length--;
}


// Driver code
int main()
{
    int set[] = { 3, 7, 8, 4};
    int sum = 30;
    bool dp[50][50];
    int n = sizeof(set) / sizeof(set[0]);
 
   subset(set, n, sum);
   return;
   count = 0;	
   if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum count=%d", count);
    else
        printf("No subset with given sum count %d", count);

  count = 0;
   if (isSubsetSumDP1(set, n, sum) == true)
        printf("Found a subset with given sum count %d", count);
    else
        printf("No subset with given sum count %d", count);
 
   return 0;
}
