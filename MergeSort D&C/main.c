void merge(int arr[], int low, int middle, int high)
{
    int i, j, k;
    int n1 = middle - low + 1;  // n1 is the index of left partioned array
    int n2 = high - middle; // n2 is the index of right partioned array

    int LeftArr[n1], RightArr[n2];


    for(i = 0; i < n1; i++)
        LeftArr[i] = arr[low + i];
    for(j = 0; j < n2; j++)
        RightArr[j] = arr[middle + 1 + j];


    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            arr[k] = LeftArr[i];
            i++;
        }
        else
        {
            arr[k] = RightArr[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}



void mergeSort(int arr[], int low, int high)
{
    if (low < high) {     //checking for at least two element
        int middle =  low + (high - low)/2; //(low + high)/2

        mergeSort(arr, low, middle);
        mergeSort(arr, middle + 1, high);

        merge(arr, low, middle, high);//After sorting seperately we have to merge those 2 lists
    }
}



void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}



int main()
{
    int sizeOfArray, arr[25], i;

    printf("How many elements are u going to enter ? : ");
     scanf("%d", &sizeOfArray);

    printf("Enter %d elements:\n", sizeOfArray);
     for (i = 0; i < sizeOfArray; i++)
        scanf("%d",&arr[i]);




    printf("\nGiven array is \n");
     printArray(arr, sizeOfArray);

    mergeSort(arr, 0, sizeOfArray - 1); //left = 0, right = sizeOfArray-1

    printf("\nSorted array is \n");
    printArray(arr, sizeOfArray);


    return 0;
}
