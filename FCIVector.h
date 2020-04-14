#ifndef FCIVECTOR_H                                                 //Eman Mahmoud Mostafa Talha - 20180064 - Group 4
#define FCIVECTOR_H

#include <iostream>

using namespace std;

template <class T>
class FCIVector
{
    private:
        T* ptr;                                //Pointer
        int sizeOfVector;                      //Vector size
        int capacity;                          //Vector capacity
    public:
        FCIVector();                           //Constructor for vector without initial size
        ~FCIVector();                          //Destructor
        void push_Back(T t);                   //To add a value to the vector
        void pop_Back();                       //To remove the last element of the vector
        void insert_V(T* p, T t);              //To add new element before a specific position
        void erase_V(T* p);                    //To erase a specific element
        void clear_V();                        //To remove all vector elements
        T* begin_V();                          //To return a pointer to the first element
        T& front_V();                          //To display the first element
        T& back_V();                           //To display the last element
        T& operator[](int j);                  //To display vector at specific position
        int size_V();                          //To display vector size
        int capacity_V();                      //To display vector capacity
        bool empty_V();                        //To know if the vector is empty or not
};

template <class T>
FCIVector<T>::FCIVector()
{
    sizeOfVector = 0;
    capacity = 0;
    ptr = new T [1];
}

template <class T>
FCIVector<T>::~FCIVector()
{
    delete ptr;
}

template <class T>
void FCIVector<T>::push_Back(T t)
{
    if (capacity==0)
        capacity = 1;
    if (sizeOfVector==capacity)
    {
        capacity *= 2;
        T* newptr = new T [capacity];
        for (int i=0 ; i<sizeOfVector ; i++)
            newptr[i] = ptr[i];
        delete[] ptr;
        ptr = newptr;
    }
    ptr[sizeOfVector] = t;
    sizeOfVector++;
}

template <class T>
void FCIVector<T>::pop_Back()
{
    if (sizeOfVector!=0)
        sizeOfVector--;
}

template <class T>
void FCIVector<T>::insert_V(T* p, T t)
{
    bool flag = false;
    int s = 0;
    for (int i=sizeOfVector-1 ; i>=s ; i--)
    {
        if (flag)
        {
            ptr[i+1] = ptr[i];
        }
        else if (ptr+i == p)
        {
            s = i;
            i = sizeOfVector-1;
            flag = true;
        }
    }
    if (sizeOfVector==capacity)
    {
        capacity*=2;
        T* newptr = new T [capacity];
        for (int i=0 ; i<sizeOfVector ; i++)
            newptr[i] = ptr[i];
        delete[] ptr;
        ptr = newptr;
    }
    ptr[sizeOfVector] = ptr[sizeOfVector-1];
    *(ptr+s) = t;
    sizeOfVector++;
}

template <class T>
void FCIVector<T>::erase_V(T* p)
{
    T* newptr= new T [capacity];
    for (int i=0, j=0 ; i<sizeOfVector-1 ; i++, j++)
    {
        if (ptr+i == p)
            j++;
        newptr[i]=ptr[j];
    }
    delete[] ptr;
    ptr = newptr;
    sizeOfVector--;
}

template <class T>
void FCIVector<T>::clear_V()
{
    sizeOfVector = 0;
}

template <class T>
T* FCIVector<T>::begin_V()
{
    return ptr;
}

template <class T>
T& FCIVector<T>::front_V()
{
    if (sizeOfVector!=0)
        return ptr[0];
}

template <class T>
T& FCIVector<T>::back_V()
{
    if (sizeOfVector!=0)
        return ptr[sizeOfVector-1];
}

template <class T>
T & FCIVector<T>::operator[](int j)
{
    if (j < sizeOfVector)
        return ptr[j];
}

template <class T>
int FCIVector<T>::size_V()
{
    return sizeOfVector;
}

template <class T>
int FCIVector<T>::capacity_V()
{
    return capacity;
}

template <class T>
bool FCIVector<T>::empty_V()
{
    if (sizeOfVector == 0)
        return true;
    else
        return false;
}

#endif // FCIVECTOR_H
