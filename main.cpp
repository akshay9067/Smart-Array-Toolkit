#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr)
{
    cout << "[ ";
    for(int x:arr){
        cout << x << " ";
    }
    cout << " ]" << endl;
}

void checkSorted(vector<int>& arr,int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        {
            cout << "Array is Not Sorted." << endl;
            break;
        }
    }
    if(i==n)cout << "Array is Sorted" << endl;
}
void largest(vector<int>& arr,int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)max=arr[i];
    }
    cout << "Largest Element: " << max << endl;
}

void secLargest(vector<int>& arr,int n)
{
    int max=arr[0];
    int max2=INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {   
            max2=max;
            max=arr[i];
        }
        else if(arr[i] < max && arr[i]>max2)
        {
            max2=arr[i];
        }

    }
    if(max2==INT_MIN)cout << "Second Largest Element doesn't exist " << endl;
    else{
        cout << "Second Largest Element: " << max2 << endl;
    }
}

void moveZeroes(vector<int>& arr,int n){
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[k]=arr[i];
            k++;
        }
    }
    for(int i=k;i<n;i++)
    {
        arr[i]=0;
    }
}  

void leftRotate(vector<int>& arr, int d,int n) {
    
    
    int e = d % n;
    reverse(arr.begin(), arr.begin() + e);
    reverse(arr.begin() + e, arr.end());
    reverse(arr.begin(), arr.end());
}
void rightRotate(vector<int>& arr,int d,int n)
{
    int e = d % n;
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(), arr.begin() + e);
    reverse(arr.begin() + e, arr.end());
}

void selectionSort(vector<int>& arr,int n)
{
    int i,min,j;
    for(i=0;i<(n-1);i++)
    {
        min=i;
        for(j=i;j<n;j++)
        {
            if(arr[j]<arr[min])min=j;
        }
        swap(arr[min],arr[i]);
    }
    cout << "Array is Sorted "<< endl;
}

void bubbleSort(vector<int>& arr, int n)
{
    for(int i = n - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


void insertionSort(vector<int>& arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;     
        }
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];   // pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}


int main()
{
    int n,choice;
    char proceed='y';
    cout << "Enter no. of elements in Array: ";
    cin >> n;
    if(n==0)cout << "No. of elements should be greate than one!" << endl;
    vector<int> arr(n);
    cout << "Enter " << n << " Elements : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    while(proceed=='y')
    {
        cout << string(20,'*') << endl << "Smart Array Toolkit" << endl << string(20,'*');
        cout << endl << "Current Array :" << endl;
        printArray(arr);
        cout << endl << "1.Check if Sorted" << endl << "2.Find Largest number" << endl<< "3.Find Second largest element";
        cout << endl << "4.Move Zeros to End" << endl << "5.Left Rotate by D" << endl<< "6.Right Rotate by D";
        cout << endl << "7.Selection Sort" << endl << "8.Bubble Sort" << endl<< "9.Insertion Sort" << endl << "10.WQ Sort";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:checkSorted(arr,n);
            break;
            case 2:largest(arr,n);
            break;
            case 3:secLargest(arr,n);
            break;
            case 4:moveZeroes(arr,n);
            break;
            case 5:{
                    int d;
                    cout << "Enter no. of places to move left: ";
                    cin >> d;
                    leftRotate(arr,d,n);
                    break;}
            case 6:{
                    int d;
                    cout << "Enter no. of places to move left: ";
                    cin >> d;
                    rightRotate(arr,d,n);
                    break;}
            case 7:selectionSort(arr,n);
            break;
            case 8:bubbleSort(arr,n);
            break;
            case 9:insertionSort(arr,n);
            break;
            case 10:quickSort(arr,0,n-1);
            break;
            default:cout << "Enter correct value!";
        }
        cout << "Do you Want to proceed(y/n): ";
        cin >> proceed;


    }
    return 0;
}
