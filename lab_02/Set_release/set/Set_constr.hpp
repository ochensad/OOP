#ifndef CONSTR_H
#define CONSTR_H

#include "Set.h"

namespace set_s
{
    template<typename Type>
    Set<Type>::Set()
    {
        head = nullptr;
        tail = nullptr;
        amount = 0;
    }

    template<typename Type>
    Set<Type>::Set(unsigned size_n, ...) : base_container()
    {
        va_list arg;
        va_start(arg, size_n);
        this->amount = 0;
        this->head = nullptr;
        this->tail = nullptr;
        Type elem;
        for (; size_n; --size_n)
        {
            elem = va_arg(arg, Type);
            this->add(elem);
        }
        va_end(arg);
    }

    template<typename Type>
    Set<Type>::Set(const Type *arr, size_t size)
    {
        this->amount = 0;
        this->head = nullptr;
        this->tail = nullptr;
        for(size_t i = 0; i < size; i++)
            this->add(arr[i]);
    }

    template<typename Type>
    Set<Type>::Set(std::initializer_list<Type> list) :base_container()
    {
        this->amount = 0;
        this->head = nullptr;
        this->tail = nullptr;
        for(auto &iter: list)
        {
            this->add(iter);
        }
    }

    template<typename Type>
    Set<Type>::Set(const Type& elem)
    {
        this->amount = 0;
        this->head = nullptr;
        this->tail = nullptr;
        this->add(elem);
    }

    template<typename Type>
    Set<Type>::Set(const Set& s)
    {
        this->amount = s.amount;

        for (auto it = s.cbegin(); it != s.cend(); ++it)
        {
            this->add(*it);
        }
    }

    template<typename Type>
    Set<Type>::Set(const Set<Type>&& s) noexcept
    {
        this->amount = s.amount;
        this->head = s.head;
        this->tail = s.tail;
    }

    template<typename Type>
    Set<Type>::Set(const ConstIterator<Type>& begin, const ConstIterator<Type>& end)
    {
        for(auto it = begin; it != end; it++)
            this->add(*it);
    }
    //Деструктор

    template<typename Type>
    Set<Type>::~Set()
    {
        head.reset();
        tail.reset();
    }

}
#endif
