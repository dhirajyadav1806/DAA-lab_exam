void binarySearch(int array[], int first, int last, int searchElement)
{
    int middle = (first + last) / 2;     // middle is the index number of the array


    while (first <= last)   // ensuring at least 1 element in the list
    {

        if (array[middle] < searchElement)
            first = middle + 1;
        else
            if (array[middle] == searchElement)
            {
                printf("\n\n%d is present at the %dth place of the array\n", searchElement, (middle + 1));
                return;
            }
            else
                last = middle - 1;

        middle = (first + last) / 2;
    }



    printf("\n\nNot found! %d is not present in the list.\n", searchElement);


    return;
}



int main()
{
   int i, sizeOfArray, searchElement, array[25];

   printf("How many elements are u going to enter ? : ");
    scanf("%d",&sizeOfArray);

   printf("Enter %d elements in sorted forms:\n", sizeOfArray);
    for (i = 0; i < sizeOfArray; i++)
        scanf("%d",&array[i]);

   printf("Enter the search element:\n");
    scanf("%d", &searchElement);

   binarySearch(array, 0, sizeOfArray-1, searchElement);    // 0 = first, sizeOfArray-1 = last

   return 0;
}
