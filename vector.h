#include <iostream>
using namespace std;
///////////////////////////////////
//     VECTOR DATA STRUCTURE     //
///////////////////////////////////
template <class T>
class vector
{
private:
    T *Arr;
    int iCapacity;
    int iCurrent;

public:
    vector();
    ~vector();
    void push_back(T data);
    void push_back(T data, int index);
    void pop_back();
    T at(int index);
    bool empty();
    int size();
    void set(int index, T data);
    int capacity();
    void print();
    T operator[](int index);
};

template <class T>
vector<T>::vector()
{
    this->Arr = new T[1];
    this->iCapacity = 1;
    this->iCurrent = 0;
}
template <class T>
vector<T>::~vector()
{
    delete[] Arr;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : empty
// Description   : It is vector Data Structure and This function is
//                 used to check vector is empty or not
// Parameter     :
// Return Value  : bool
//
////////////////////////////////////////////////////////////////////

template <class T>
bool vector<T>::empty()
{
    if (iCurrent == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is vector Data Structure and This function is
//                 used to push the element at the last index of vector
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data)
{
    if (iCurrent == iCapacity)
    {
        T *temp = new T[2 * iCapacity];

        for (register int i = 0; i < iCapacity; i++)
        {
            temp[i] = Arr[i];
        }

        delete[] Arr;
        iCapacity = iCapacity * 2;
        Arr = temp;
    }

    Arr[iCurrent] = data;
    iCurrent++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : push_back
// Description   : It is vector Data Structure and This function is
//                 used to push the element at the last index of vector
// Parameter     : data and index
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::push_back(T data, int index)
{
    if (index < 0 || index > iCurrent)
    {
        throw out_of_range("invalid index");
    }
    if (index == iCapacity)
    {
        push_back(data);
    }
    else
    {
        Arr[index] = data;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : pop_back
// Description   : It is vector Data Structure and This function is
//                 used to pop(delete) the element at the last index of vector
// Parameter     : data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::pop_back()
{
    if (iCurrent > 0)
    {
        iCurrent--;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : at
// Description   : It is vector Data Structure and This function is
//                 used to return the element at given index
// Parameter     : index
// Return Value  : any data type
//
////////////////////////////////////////////////////////////////////

template <class T>
T vector<T>::at(int index)
{
    // if index is within the range
    if (index >= 0 && index < iCurrent)
    {
        return Arr[index];
    }
    throw out_of_range("out of range");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : size
// Description   : It is vector Data Structure and This function is
//                 used to return the size of vector
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::size()
{
    return iCurrent;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : capacity
// Description   : It is vector Data Structure and This function is
//                 used to return the current capacity of vector
// Parameter     :
// Return Value  : int
//
////////////////////////////////////////////////////////////////////

template <class T>
int vector<T>::capacity()
{
    return iCapacity;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : print
// Description   : It is vector Data Structure and This function is
//                 used to print the data store in vector
// Parameter     :
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::print()
{
    if (empty())
    {
        cout << "vector is empty" << endl;
        return;
    }
    for (register int i = 0; i < iCurrent; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : operator
// Description   : It is vector Data Structure and This function is
//                 used to return the element at gievn index and
//                 this function also overload the [] bracket.
// Parameter     : data
// Return Value  : any data type
//
////////////////////////////////////////////////////////////////////

template <class T>
T vector<T>::operator[](int index)
{
    if (index >= 0 && index < iCurrent)
    {
        return Arr[index];
    }
    throw out_of_range("out of range");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : set
// Description   : It is vector Data Structure and This function is
//                 used to set or update the data on given index
//                 the data
// Parameter     : index and data
// Return Value  : void
//
////////////////////////////////////////////////////////////////////

template <class T>
void vector<T>::set(int index, T data)
{
    if (index >= 0 && index < iCurrent)
    {
        Arr[index] = data;
        return;
    }
}