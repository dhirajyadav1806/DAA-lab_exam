void knapsack(int numOfObjects, float weight[], float profit[], int knapsackCapacity) {
   float x[20], tp = 0;
   int i, j, u=knapsackCapacity;

   for(i = 0; i < numOfObjects; i++)
      x[i] = 0.0;

    for (i = 0; i < numOfObjects; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

   if (i < numOfObjects)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nThe result vector is:- ");
   for (i = 0; i < numOfObjects; i++)
      printf("%f\t", x[i]);

   printf("\nMaximum profit is:- %f \n\n", tp);

}



int main()
{

    float weight[20], profit[20], ratio[20], knapsackCapacity;
    int numOfObjects, i, j;
    float  temp;



    printf("How many objects are you going to enter ? : ");
    scanf("%d", &numOfObjects);

    printf("\nEnter the weights and profits of %d objects respectively:-\n", numOfObjects);
    for (i = 0; i < numOfObjects; i++)
        scanf("%f %f", &weight[i], &profit[i]);

    printf("\nEnter the capacity of knapsack:- ");
    scanf("%f", &knapsackCapacity);

    for (i = 0; i < numOfObjects; i++)
        ratio[i] = profit[i] / weight[i];


   for (i = 0; i < numOfObjects; i++) {
      for (j = i + 1; j < numOfObjects; j++) {
         if (ratio[i] < ratio[j])
         {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(numOfObjects, weight, profit, knapsackCapacity);
   return(0);
}
