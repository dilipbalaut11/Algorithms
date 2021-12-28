// A Recursive solution
// for subset sum problem
#include <stdio.h>
#include <stdbool.h> 
// Returns true if there is a subset of set[]
// with sum equal to given sum
isSubsetSum(int set[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n == 0)
		return false;
	if (set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

//TODO dynamic programming
isSubsetSumDP(int set[], int n, int sum)
{
}

//print all subset
printsubsetset()
{
	int i;
	int sum = 0;

	for (i = 0; i < length; i++)
	{
		sum += localset[i];
		printf("%d ", localset[i]);
	}
	printf("sum=%d\n", sum);
}

//get all the subsets
void
subset(int *set, int n, int sum)
{
	if (sum == 0)
		return printsubsetset();
	if (n == 0)
		return;
	if (sum < set[n-1])
		return subset(set, n-1, sum);

	subset(set, n-1, sum);

	localset[length++] = set[n-1];
	subset(set, n-1, sum - set[n-1]);
	length--;
}


// Driver code
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 35;
    bool dp[50][50];
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
