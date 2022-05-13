#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory.h>
#include <time.h>

#include "../exceptions/exceptions.h"

template<class Type>
class Set;

template<typename Type>
class Iterator : public std::bidirectional_iterator_tag
{
    public:
        // Конструкторы
        Iterator(const Iterator<Type>& iter) noexcept;
        Iterator(const Set<Type>& set, const int ind) noexcept;

        // Перегрузка операторов
        Type& operator*();
        const Type& operator*() const;
        Type& operator->();
        const Type& operator->() const;

        // Унарные операторы
        Iterator<Type>& operator ++();
        Iterator<Type> operator ++(int);
        Iterator<Type>& operator --();
        Iterator<Type> operator --(int);

        // Бинарные операторы
        bool operator ==(const Iterator<Type>& b) const;
        bool operator !=(const Iterator<Type>& b) const;
        bool operator >=(const Iterator<Type>& b) const;
        bool operator <=(const Iterator<Type>& b) const;
        bool operator >(const Iterator<Type>& b) const;
        bool operator <(const Iterator<Type>& b) const;

        Iterator<Type>& operator = (const Iterator<Type>&) noexcept;
        Iterator<Type>& operator+=(int n);
        Iterator<Type>& operator-=(int n);
        Iterator<Type> operator+(int n);
        Iterator<Type> operator-(int n);

        // Проверка на существование указателя
        bool ExcCheck(int line) const;
    private:
        std::weak_ptr<Type> ptr;
        int index = 0;
        int num_elem = 0;
    protected:
        Type *GetCurPtr() const;
};

#include "iterator_imp.hpp"

#endif