#include <stdio.h>

void maxResourceUtilization(int resources[], int n, int constraint) 
{
    int start = 0, curr_sum = 0, max_sum = 0;
    int best_start = -1, best_end = -1;

    for (int end = 0; end < n; end++) 
    {
        curr_sum += resources[end];

        while (curr_sum > constraint && start <= end) 
        {
            curr_sum -= resources[start];
            start++;
        }

        if (curr_sum > max_sum) 
        {
            max_sum = curr_sum;
            best_start = start;
            best_end = end;
        }
    }

    if (best_start == -1) 
    {
        printf("No feasible subarray found under the constraint.\n");
    } 
    else 
    {
        printf("Maximum resource utilization: %d\n", max_sum);
        printf("Optimal subarray: [ ");
        for (int i = best_start; i <= best_end; i++) 
        {
            printf("%d ", resources[i]);
        }
        printf("]\n");
    }
}

int main() 
{
    int n, constraint;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int resources[n];
    printf("Enter resource requirement for each task:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &resources[i]);
    }

    printf("Enter resource constraint: ");
    scanf("%d", &constraint);

    maxResourceUtilization(resources, n, constraint);

    return 0;
}
