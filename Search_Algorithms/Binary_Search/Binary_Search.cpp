/*** Binary Search ***/

#include <iostream>
using namespace std;


// Class
template <class type>
class arrayBin
{
public:
    int static const length = 5;
    int list[length];
    binarySearch(const type);
};


// binarySearch Function
template <class type>
int arrayBin<type>::binarySearch(const type item)
{
    int first = 0;
    int last = length-1;
    int mid;
    bool found = false;

    while(first <= last && !found)
    {
        mid = (first + last)/2;

        if(list[mid] == item)
            found = true;
        else if(list[mid]>item)
            last = mid-1;
        else
            first = mid+1;
    }

    if(found)
        return mid;
    else
        return -1;
}


// Main
int main()
{
    arrayBin<int> bin;
    int x;

    for(int i=0; i<bin.length; i++)
        bin.list[i] = i;  // list[5] = {0,1,2,3,4}

    cout<<"Enter Number You Want To Search : ";
    cin>>x;

    if(bin.binarySearch(x) != -1)
        cout<<"Item Found! With Location "<<bin.binarySearch(x)<<"\n";
    else
        cout<<"Item doesn't Founded!\n";

    return 0;
}
