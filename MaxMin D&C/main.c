int max(int arr[], int first, int last)
{
	//if one element in the array
	if(last - first + 1 == 1)
        return arr[first];

	//if two elements in the array
	if(last - first + 1 == 2)
	{
		if(arr[first] < arr[last])
            return arr[last];
		else
            return arr[first];
	}


	int middle = first + (last-first)/2;

	int max1 = max(arr, first, middle);
	int max2 = max(arr, middle+1, last);

	if(max1 < max2)
        return max2;
	else
        return max1;
}



int min(int arr[], int first, int last)
{
	//if one element in the array
	if(last - first + 1 == 1)
        return arr[first];


    //if two elements in the array
	if(last - first + 1 == 2)
	{
		if(arr[first] < arr[last])
            return arr[first];
		else
            return arr[last];
	}


	int middle = first + (last-first)/2;

	int min1 = min(arr, first, middle);
	int min2 = min(arr, middle+1, last);

	if(min1 < min2)
        return min1;
	else
        return min2;
}



int main()
{
    int i, sizeOfArray, arr[25];

    printf("How many elements are u going to enter ? : ");
     scanf("%d",&sizeOfArray);

    printf("Enter %d elements :\n", sizeOfArray);
     for (i = 0; i < sizeOfArray; i++)
         scanf("%d", &arr[i]);



	int maximum = max(arr, 0, sizeOfArray-1);       // 0 = first, sizeOfArray-1 = last,   0 & sizeOfArray-1  is indices of array
        printf("Maximum Elements - %d\n", maximum);

	int minimum = min(arr, 0, sizeOfArray-1);
        printf("Minimum Elements - %d\n", minimum);



    return 0;
}
