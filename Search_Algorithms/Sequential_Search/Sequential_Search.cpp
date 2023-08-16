/*** Sequential Search ***/

#include <iostream>
using namespace std;


// Class
template <class type>
class arraySeq
{
public:
    int static const length = 5;
    int list[length];
    seqSearch(const type);
};


// SeqSearch Function
template <class type>
int arraySeq<type>::seqSearch(const type item)
{
    int loc;
    bool found = false;

    for (loc=0; loc<length; loc++)
        if(list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
}


// Main
int main()
{
    arraySeq<int> seq;
    int x;

    for(int i=0; i<seq.length; i++)
        seq.list[i] = i;  // list[5] = {0,1,2,3,4}

    cout<<"Enter Number You Want To Search : ";
    cin>>x;

    if(seq.seqSearch(x) != -1)
        cout<<"Item Found! With Location "<<seq.seqSearch(x)<<"\n";
    else
        cout<<"Item doesn't Founded!\n";

    return 0;
}
