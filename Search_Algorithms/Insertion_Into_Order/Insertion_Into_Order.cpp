/*** Insertion Into Order ***/

#include <iostream>
using namespace std;


// Class
template <class type>
class arrayIns
{
public:
    int length , maxSize;
    int *list;

    // Constructor
    arrayIns()
    {
        int x;
        cout<<"Enter Size Of list : ";
        cin>>x;
        length = x;
        maxSize = x+2;
        cout<<" * Hint: Max Size Allowed * = "<<maxSize<<"\n";
        list = new type[x];
    }

    void insertOrd(const type);
    void insertAt(int , const type);
};


// insertOrd Function
template <class type>
void arrayIns<type>::insertOrd(const type item)
{
    int first = 0;
    int last = length-1;
    int mid;
    bool found = false;

    if(length == 0)  // List Is Empty
    {
        list[0] = item;
        length++;
    }

    else if (length == last)
        cout<<"Cannot Insert Into A Full List!\n";

    else
    {
        // Binary Search
        while(first <= last && !found)
        {
            mid = (first + last)/2;

            if(list[mid] == item)
                found = true;
            else if(list[mid]>item)
                last = mid-1;
            else
                first = mid+1;

            if(found)
                cout<<"The Item Is Already In The List\n";
            else
            {
                if(list[mid]<item)
                    mid++;
                insertAt(mid,item);
            }
        }
    }
}


// insertAt Function
template <class type>
void arrayIns<type>::insertAt(int location, const type insertItem)
{
    if(location<0 || location>=length)
        cout<<"The Position Is Out Of Range\n";
    else
    {
        for(int i=length; i>location; i--)
            list[i] = list[i-1];  // Move Elements Down

        list[location] = insertItem;  // Insert Item To Specified Position

        length++;
    }
}


// Main
int main()
{
    arrayIns<int> ins;
    int x,loc;

    for(int i=0; i<ins.maxSize; i++)
    {
        cout<<endl;
        cout<<"Enter Number You Want To Insert : ";
        cin>>x;
        cout<<"Enter Location : ";
        cin>>loc;
        ins.insertAt(loc,x);

        for(int k=0; k<ins.maxSize; k++)
        cout<<ins.list[k]<<" ";
    }

    return 0;
}
