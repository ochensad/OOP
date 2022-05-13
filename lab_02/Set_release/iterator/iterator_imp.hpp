#ifndef ITERATOR_IMP_H
#define ITERATOR_IMP_H

#include "iterator.h"

// Protected
template <class Type>
Type* Iterator<Type>::GetCurPtr() const
{
    std::shared_ptr<Type> copy_ptr = ptr.lock();
    return copy_ptr.get() + index;
}

// Конструкторы
template <class Type>
Iterator<Type>::Iterator(const Iterator<Type>& iter) noexcept
{
    index = iter.index;
    num_elem = iter.num_elem;
    ptr =iter.data_list;
}

template <class Type>
Iterator<Type>::Iterator(const Set<Type>& set, const int ind) noexcept
{
    index = ind;
    num_elem = set.num_elem;
    ptr =set.data_list;
}

// Проверка на существование указателя
template <class Type>
bool Iterator<Type>::ExcCheck(int line) const
{
    if (!ptr.expired())
        return true;
    time_t t_time = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(), line, ctime(&t_time));
}

// Операторы указателей

template <class Type>
Type& Iterator<Type>::operator*()
{
    ExcCheck(__LINE__);
    std::shared_ptr<Type> copy_ptr = ptr.lock();
    return *GetCurPtr();
}

template <class Type>
const Type& Iterator<Type>::operator*() const
{
    ExcCheck(__LINE__);
    std::shared_ptr<Type> copy_ptr = ptr.lock();
    return *GetCurPtr();
}

template <class Type>
Type& Iterator<Type>::operator->()
{
    ExcCheck(__LINE__);
    return GetCurPtr();
}

template <class Type>
const Type& Iterator<Type>::operator->() const
{
    ExcCheck(__LINE__);
    return GetCurPtr();
}

// Унарные операторы

template <class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    ExcCheck(__LINE__);
    ++index;
    return(*this);
}

template <class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    ExcCheck(__LINE__);
    ++(*this);
    return(*this);
}

template <class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    ExcCheck(__LINE__);
    --index;
    return(*this);
}

template <class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    ExcCheck(__LINE__);
    --(*this);
    return(*this);
}

// Бинарные операторы

template <class Type>
bool Iterator<Type>::operator==(const Iterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return ptr == b.ptr;
}

template <class Type>
bool Iterator<Type>::operator!=(const Iterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return ptr != b.ptr;
}

template <class Type>
bool Iterator<Type>::operator>=(const Iterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return ptr >= b.ptr;
}

template <class Type>
bool Iterator<Type>::operator<=(const Iterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return ptr <= b.ptr;
}

template <class Type>
bool Iterator<Type>::operator>(const Iterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return ptr > b.ptr;
}

template <class Type>
bool Iterator<Type>::operator<(const Iterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return ptr < b.ptr;
}

template <class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter) noexcept
{
    ExcCheck(__LINE__);
    ptr = iter.ptr;
    return(*this);
}

template <class Type>
Iterator<Type>& Iterator<Type>::operator+=(int n)
{
    ExcCheck(__LINE__);
    index +=n;
    return(*this);
}

template <class Type>
Iterator<Type>& Iterator<Type>::operator-=(int n)
{
    ExcCheck(__LINE__);
    index -=n;
    return(*this);
}

template <class Type>
Iterator<Type> Iterator<Type>::operator+(int n)
{
    ExcCheck(__LINE__);
    Iterator<Type> iter(*this);
    iter += n;
    return(iter);
}

template <class Type>
Iterator<Type> Iterator<Type>::operator-(int n)
{
    ExcCheck(__LINE__);
    Iterator<Type> iter(*this);
    iter -= n;
    return(iter);
}

#endif