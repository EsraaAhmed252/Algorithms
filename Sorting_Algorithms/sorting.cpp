#include <iostream>
using namespace std;

template <class type>
class arrayListType
{

public:
    void SelectionSorting(); //Time = O(n^2)
    void InsertionSorting(); //Time = O(n^2)
    void BubbleSorting();    //Time = O(n^2)
    void QuickSorting();     //Time = O(nlog n)
    void HeapSorting();      //Time = O(nlog n)
    void MergeSorting();     //Time = O(nlog n)
    void Print();
    void insert(type);
    void print1 ()
    {
        for(int i=0 ; i<size ; i++)
            cout<<List[i]<<"\t";
    }

private:
    int size = 0;
    type List[1000];
    void swap(int, int);
    int MinLoc(int, int);
    void BubbleUp(int, int);
    void recQuick(int, int);
    int partition(int, int);
    void heapify(int, int);
    void buildHeap();
    void Merge(int, int, int, int);
    void reMergeSorting(int, int);
};
/////////////
///Insert
template <class type>
void arrayListType<type>::insert(type x)
{
    List[size] = x;
    size++;
}
/////////////
///Print
template <class type>
void arrayListType<type>::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << List[i] << "\t";
    }
}
/////////////
///Swap
template <class type>
void arrayListType<type>::swap(int first, int second)
{
    type temp;
    temp = List[first];
    List[first] = List[second];
    List[second] = temp;
}
/////////////
///Selection
template <class type>
int arrayListType<type>::MinLoc(int first, int last)
{
    int minIndex;

    minIndex = first;

    for (int loc = first + 1; loc <= last; loc++)
        if (List[loc] < List[minIndex])
            minIndex = loc;
    return minIndex;
}

template <class type>
void arrayListType<type>::SelectionSorting()
{
    int minIndex;
    cout<<"Iteration are :"<<"\n";
    for (int loc = 0; loc < size - 1; loc++)
    {
        minIndex = MinLoc(loc, size - 1);
        swap(loc, minIndex);
        for(int i=0;i<size ;i++)
            cout<<List[i]<<"\t";
            cout<<"\n";
    }
}
/////////////
///Bubble
template <class type>
void arrayListType<type>::BubbleUp(int startindex, int endindex)
{
    for (int idx = startindex; idx < endindex; idx++)
    {
        if (List[idx] > List[idx + 1])
            swap(idx, idx + 1);
    }
}

template <class type>
void arrayListType<type>::BubbleSorting()
{
    int _size = size;
    _size--;
    cout<<"Iteration are :"<<"\n";
    while (_size > 0)       //size positive and not 0(still there are elements in the array)
    {
        BubbleUp(0, _size);
        _size--;
        for(int i=0;i<size ;i++)
            cout<<List[i]<<"\t";
            cout<<"\n";
    }
}
/////////////
///Insertion
template <class type>
void arrayListType<type>::InsertionSorting()
{
    int firstOutOfOrder, loc;
    type temp;
    cout<<"Iteration are :"<<"\n";
    for (firstOutOfOrder = 1; firstOutOfOrder < size; firstOutOfOrder++)
        {if (List[firstOutOfOrder] < List[firstOutOfOrder - 1])
        {
            temp = List[firstOutOfOrder];
            loc = firstOutOfOrder;
            do
            {
                List[loc] = List[loc - 1];    //move slot down
                loc--;
            } while (loc > 0 && List[loc - 1] > temp);   //loc positive and elem before it > temp
            List[loc] = temp;
        }
        for(int i=0;i<size ;i++)
            cout<<List[i]<<"\t";
            cout<<"\n";
        }
}
/////////////
///Quick
template <class type>
int arrayListType<type>::partition(int first, int last)
{
    type pivot;
    int smallIndex;      // index of the last elem. of lowerSubList (last elem.<pivot)
    int index;          // index of the next elem. that needs to be moved in lower or upperSubList
    swap(first, (first + last) / 2);
    pivot = List[first];
    smallIndex = first;
    cout<<"Iteration are :"<<"\n";
    for (index = first + 1; index <= last; index++)
        if (List[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    swap(first, smallIndex);
    for(int i=0;i<size ;i++)
        cout<<List[i]<<"\t";
        cout<<"\n";
    return smallIndex;
}

template <class type>
void arrayListType<type>::recQuick(int first, int last)
{
    int pivotloc;
    if (first < last)
    {
        pivotloc = partition(first, last);
        recQuick(first, pivotloc - 1);
        recQuick(pivotloc + 1, last);
    }

}

template <class type>
void arrayListType<type>::QuickSorting()
{
    recQuick(0, size - 1);
}
/////////////
///Heap
template <class type>
void arrayListType<type>::heapify(int low, int high)
{
    type temp = List[low];   //copy the root node of the subtree
    int largeIndex = 2 * low + 1;     //index of the left child
    while (largeIndex <= high)   //high contains index of the last item in the list.
    {
        if (largeIndex < high && List[largeIndex] < List[largeIndex + 1])
            largeIndex += 1;       //index of largest child.

        if (temp > List[largeIndex])  // if root node > its larger child
            break;                     // do not do anything!
        else
        {
            List[low] = List[largeIndex];   // move the larger child to the root
            low = largeIndex;     //go to the subtree to restore the heap
            largeIndex = 2 * low + 1;
        }
    }
    List[low] = temp;
}

template <class type>
void arrayListType<type>::buildHeap()
{
    for (int index = (size / 2) - 1; index >= 0; index--)
        heapify(index, size - 1);
}

template <class type>
void arrayListType<type>::HeapSorting()
{
    type temp;

    buildHeap();

    for (int i = size - 1; i >= 0; i--) // i = lastOutOfOrder
    {
        temp = List[i];
        List[i] = List[0];
        List[0] = temp;
        heapify(0, i - 1);
    }
}
/////////////
///Merge
template <class type>
void arrayListType<type>::Merge(int leftFirst, int leftLast, int rightFirst, int rightLast)
{
    type tempArray[1000];
    int index = leftFirst;
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (List[leftFirst] < List[rightFirst])
        {
            tempArray[index] = List[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = List[rightFirst];
            rightFirst++;
        }
        index++;
    }
    while (leftFirst <= leftLast)
    {
        tempArray[index] = List[leftFirst];
        leftFirst++;
        index++;
    }
    while (rightFirst <= rightLast)
    {
        tempArray[index] = List[rightFirst];
        rightFirst++;
        index++;
    }
    for (index = saveFirst; index <= rightLast; index++)
        List[index] = tempArray[index];
}

template <class type>
void arrayListType<type>::reMergeSorting(int First, int Last)
{
    if (First < Last)
    {
        int middle = (First + Last) / 2;
        reMergeSorting(First, middle);
        reMergeSorting(middle + 1, Last);
        Merge(First, middle, middle + 1, Last);
    }
}

template <class type>
void arrayListType<type>::MergeSorting()
{

    reMergeSorting(0, size - 1);
}
/////////////
///Main
int main()
{
    arrayListType<int> ar;
    int num, x;
    cout << "Enter numbers [End with -999] : " << endl;
    cin >> num;

    while (num != -999)
    {
        ar.insert(num);
        cin >> num;
    }

    cout << "List before Sorting:" << endl;
    ar.print1();
    cout << "\n \n Enter the ID Number : \n 1. Selection Sorting: \n 2. Bubble Sorting: \n 3. Insertion Sorting: \n 4. Quick Sorting: \n 5. Heap Sorting: \n 6. Merge Sorting: " << endl;
    cin >> x;

    switch (x)
    {
     case 1:
    {
        cout << "Welcome in Selection Sorting !!" << endl;
        ar.SelectionSorting();
        cout << "\n List after Selection Sorting is :" << endl;
        ar.Print();
        break;
    }
     case 2:
    {
        cout << "Welcome in Bubble Sorting !!" << endl;
        ar.BubbleSorting();
        cout << "\nList after Bubble Sorting is :" << endl;
        ar.Print();
        break;
    }
     case 3:
    {
        cout << "Welcome in Inserstion Sorting !!" << endl;
        ar.InsertionSorting();
        cout << "\nList after Insertion Sorting is :" << endl;
        ar.Print();
        break;
    }
     case 4:
    {
        cout << "Welcome in Quick Sorting !!" << endl;
        ar.QuickSorting();
        cout << "\nList after Quick Sorting is :" << endl;
        ar.Print();
        break;
    }
     case 5:
    {
        cout << "Welcome in Heap Sorting !!" << endl;
        ar.HeapSorting();
        cout << "\nList after Heap Sorting is :" << endl;
        ar.Print();
        break;
    }
     case 6:
    {
        cout << "Welcome in Merge Sorting !!" << endl;
        ar.MergeSorting();
        cout << "\nList after Merge Sorting is :" << endl;
        ar.Print();
        break;
    }

     default :
    {
        cout << "Envalid ID Number" << endl;
        break;
    }

    return (0);
}
}
