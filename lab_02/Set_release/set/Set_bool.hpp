#ifndef BOOL_H
#define BOOL_H

#include "Set.h"

namespace set_s
{
    template <typename Type>
    bool Set<Type>::operator==(const Set<Type>& s2)
    {
        return this->is_subsetof(s2) && s2.is_subsetof(*this);
    }

    template <typename Type>
    bool Set<Type>::operator !=(const Set<Type>& s2)
    {
        return !(this->is_subsetof(s2) && s2.is_subsetof(*this));
    }

    template <typename Type>
    bool Set<Type>::operator>=(const Set<Type>& s2)
    {
        return s2.is_subsetof(*this);
    }

    template <typename Type>
    bool Set<Type>::operator<=(const Set<Type>& s2)
    {
        return this->is_subsetof(s2);
    }

    template <typename Type>
    bool Set<Type>::operator>(const Set<Type>& s2)
    {
        return !this->is_subsetof(s2) && s2.is_subsetof(*this);
    }

    template <typename Type>
    bool Set<Type>::operator<(const Set<Type>& s2)
    {
        return this->is_subsetof(s2) && !s2.is_subsetof(*this);
    }
}

#endif