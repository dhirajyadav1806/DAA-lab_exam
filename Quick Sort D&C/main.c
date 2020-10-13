void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of the left most element

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)// If current element is smaller than the pivot
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)     // ensuring at least two element in the list
	{
		int pi = partition(arr, low, high);  // pi is partitioning index, arr[pi] is now at right place

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
    int i, sizeOfArray, array[25];

    printf("How many elements are u going to enter ? : ");
     scanf("%d",&sizeOfArray);

    printf("Enter %d elements:\n", sizeOfArray);
     for(i = 0; i < sizeOfArray; i++)
        scanf("%d",&array[i]);




    printf("\nGiven array is \n");
    printArray(array, sizeOfArray);

    quickSort(array, 0, sizeOfArray-1);     // sending low = 0, high = sizeOfArray-1

    printf("Order of Sorted elements: ");
    printArray(array, sizeOfArray);

    return 0;
}
