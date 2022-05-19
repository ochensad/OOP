#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include <memory>
#include <time.h>

#include "../exceptions/exceptions.h"
#include "../set/SetNode.h"


template<typename U>
class Set;

template<typename Type>
class ConstIterator: public std::iterator<std::forward_iterator_tag, Type>
{
    public:
        // Конструкторы
        ConstIterator() = default;
        explicit ConstIterator(std::shared_ptr<SetNode<Type>> ptr);

        bool operator ==(const ConstIterator<Type>& b) const;
        bool operator !=(const ConstIterator<Type>& b) const;
        //bool operator >(const ConstIterator<Type>& b) const;
        //bool operator <(const ConstIterator<Type>& b) const;

        // Перегрузка операторов указателей

        const Type& operator*() const;
        const Type& operator->() const;

        // Укарные операторы
        ConstIterator<Type>& operator ++();
        ConstIterator<Type> operator ++(int);

        // Проверка на существование указателя
        bool ExcCheck(int line) const;
    private:
        std::weak_ptr<SetNode<Type>> ptr;
};

#include "const_iterator_imp.hpp"

#endif
