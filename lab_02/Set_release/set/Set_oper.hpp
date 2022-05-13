#ifndef OPER_H
#define OPER_H

#include "Set.h"

namespace set_s
{
    template<typename Type>
    Set<Type>& Set<Type>::operator=(const Set<Type>&& s)
    {
        this->amount = s.amount;
        this->head = s.head;
        this->tail = s.tail;
        return *this;
    }

    template<typename Type>
    Set<Type>& Set<Type>::operator=(const Set<Type>& s)
    {
        if (this != &s)
        {
            this->amount = 0;
            this->head.reset();
            auto ptr = s.head;
            for(size_t i = 0; i < s.amount; i++)
            {
                this->add(ptr->getValue());
                ptr = ptr->getNext();
            }
        }
        return *this;
    }
        template <typename Type>
    Set<Type>& Set<Type>::operator+=(const Set<Type>& s2)
    {
        this->set_union(s2);
        return *this;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator|=(const Set<Type>& s2)
    {
        this->set_union(s2);
        return *this;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator +(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_union(right);
        return res;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator |(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_union(right);
        return res;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator-=(const Set<Type>& s2)
    {
        this->set_dif(s2);
        return *this;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator -(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_dif(right);
        return res;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator/=(const Set<Type>& s2)
    {
        this->set_dif(s2);
        return *this;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator /(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_dif(right);
        return res;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator*=(const Set<Type>& s2)
    {
        this->set_cross(s2);
        return *this;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator&=(const Set<Type>& s2)
    {
        this->set_cross(s2);
        return *this;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator *(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_cross(right);
        return res;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator &(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_cross(right);
        return res;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator%=(const Set<Type>& s2)
    {
        this->set_sym_dif(s2);
        return *this;
    }

    template <typename Type>
    Set<Type>& Set<Type>::operator^=(const Set<Type>& s2)
    {
        this->set_sym_dif(s2);
        return *this;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator %(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_sym_dif(right);
        return res;
    }

    template <typename Type>
    Set<Type> Set<Type>::operator ^(const Set<Type>& right) const
    {
        Set<Type> res = (*this);
        res.set_sym_dif(right);
        return res;
    }
} // namespace set_s


#endif
