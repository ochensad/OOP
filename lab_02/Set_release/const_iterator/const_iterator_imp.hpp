#ifndef CONST_ITERATOR_IMP_H
#define CONST_ITERATOR_IMP_H

#include "const_iterator.hpp"

// Проверка на существование указателя
template <class Type>
bool ConstIterator<Type>::ExcCheck(int line) const
{
    if (!ptr.expired())
        return true;
    time_t t_time = time(NULL);
    throw DeletedObjectException(__FILE__, typeid(*this).name(), line, ctime(&t_time));
}

// Конструкторы
//template <class Type>
//ConstIterator<Type>::ConstIterator(const ConstIterator<Type>& iter) noexcept
//{
    //index = iter.index;
    //num_elem = iter.num_elem;
    //ptr =iter.data_list;
//}

template <typename Type>
ConstIterator<Type>::ConstIterator(std::shared_ptr<SetNode<Type>> ptr)
{
    this->ptr = ptr;
}

// Перегрузка операторов указателей
template <class Type>
const Type& ConstIterator<Type>::operator*() const
{
    ExcCheck(__LINE__);
    return this->ptr.lock()->getValue();
}

template <class Type>
const Type& ConstIterator<Type>::operator->() const
{
    ExcCheck(__LINE__);
    return &this->ptr.lock()->getValue();
}

// Унарные операторы
template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator++()
{
    this->ptr = this->ptr.lock()->getNext();

    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int)
{
    ConstIterator<Type> iterator = *this;
    this->ptr = this->ptr.lock()->getNext();

    return iterator;
}

template <class Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type>& b) const
{
    ExcCheck(__LINE__);
    return this->ptr.lock() == b.ptr.lock();
}

template <class Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type>& b) const
{
    //ExcCheck(__LINE__);
    return this->ptr.lock() != b.ptr.lock();
}

#endif
