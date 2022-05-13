#ifndef FUNC_H
#define FUNC_H

#include "Set.h"

namespace set_s
{
    template <typename Type>
    Set<Type>& Set<Type>::set_union(const Set<Type>& s1)
    {
        for (auto it = s1.cbegin(); it != s1.cend(); ++it)
        {
            this->add(*it);
        }
        return *this;
    }

    template <typename Type>
    Set<Type>& Set<Type>::set_dif(const Set<Type>& s1)
    {
        auto next = this->cbegin();
        for (auto it = this->cbegin(); it != this->cend(); it = next)
        {
            ++next;
            if (s1.contains(*it))
                this->erase(*it);
        }
        return *this;
    }

    template <typename Type>
    Set<Type>& Set<Type>::set_cross(const Set<Type>& s1)
    {
        auto next = this->cbegin();
        for (auto it = this->cbegin(); it != this->cend(); it = next)
        {
            ++next;
            if (!s1.contains(*it))
                this->erase(*it);
        }
        return *this;
    }

    template <typename Type>
    Set<Type>& Set<Type>::set_sym_dif(const Set<Type>& s1)
    {
        *this = (*this / s1) + (s1 / (*this));
        return (*this);
    }

    template <typename Type>
    bool Set<Type>::is_empty() const
    {
        return this->head == nullptr;
    }

    template<typename Type>
    bool Set<Type>::exist(const Type& elem) const
    {
        if (this->is_empty())
            return false;
        auto ptr = this->head;
        while (ptr->getNext() != nullptr)
        {
            if (ptr->getValue() == elem)
            {
                return true;
            }
            ptr = ptr->getNext();
        }
        return false;
    }

    template<typename Type>
    bool Set<Type>::add(const Type& elem)
    {
        if (this->exist(elem))
            return false;
        auto newPtr = std::make_shared<SetNode<Type>>(elem);
        if (this->get_size() == 0)
        {
            this->head = newPtr;
            this->tail = newPtr;
        }
        else
        {
            auto ptr = this->tail;
            ptr->setNext(newPtr);
            this->tail = newPtr;
        }
        this->amount++;
        return true;
    }

    template<typename Type>
    bool Set<Type>::erase(const Type& elem)
    {
        if (this->head->getValue() == elem)
        {
            this->head = this->head->getNext();
            this->amount--;
            return true;
        }

        auto ptr = this->head;
        while (ptr->getNext() != nullptr)
        {
            if (ptr->getNext()->getValue() == elem)
            {
                ptr->setNext(ptr->getNext()->getNext());
                this->amount--;
                return true;
            }

            ptr = ptr->getNext();
        }
        return true;
    }

    template <typename Type>
    bool Set<Type>::is_subsetof(const Set<Type>& s1) const
    {
        if (this->is_empty())
            return true;
        size_t i = 0;
        bool res = true;
        auto ptr = this->head;
        while (ptr->getNext() != nullptr)
        {
            if (res == false || i >= this->amount)
                break;
            if (!s1.exist(ptr->getValue()))
            {
                res = false;
            }

            ptr = ptr->getNext();
        }
        return res;
    }

    template <typename Type>
    bool Set<Type>::contains(const Type& val) const
    {
        for (auto it = this->cbegin(); it != this->cend(); ++it)
        {
            if (*it == val)
            {
                return true;
            }
        }

        return false;
    }

    template <typename Type>
    size_t Set<Type>::get_size() const
    {
        return this->amount;
    }
}

#endif
