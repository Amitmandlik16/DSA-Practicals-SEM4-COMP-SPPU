public class MergeSort {

    public static void Merge(int arr[] ,int low ,int mid ,int high)
    {
        int brr[] = new int[high - low +1];  // +1 because indexing starts from zero
        int i = low;
        int j = mid+1;
        int k=0;

        while(i<=mid && j<=high)
        {
            if (arr[i] < arr[j])
            {
                brr[k] = arr[i];
                i++;
                k++;   
            }
            else
            {
                brr[k] = arr[j];
                j++;
                k++;
            }
        }
        while (i<=mid) 
        {
            brr[k] = arr[i];
            i++;
            k++;    
        }
        while (j<=high) 
        {
            brr[k] = arr[j];
            j++;
            k++;    
        }

        //copying brr in arr
        k=0;
        for(i=low;i<=high;i++)
        {
            arr[i] = brr[k];
            k++;
        }
    }

    public static void Divide(int arr[] ,int low , int high)
    {
         if(low<high)
         {
              int mid = (low + high) / 2;
              Divide(arr, low, mid);
              Divide(arr, mid+1 , high);
              Merge(arr,low,mid,high);
         }
    }
    public static void main(String args[]){
        int arr[]= {6,3,9,5,2,8};
        int n = arr.length;

        Divide(arr, 0, n-1);
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i]);
        }
    }
    
}

/*
    javac Mergesort.java
    java Mergesort

 */