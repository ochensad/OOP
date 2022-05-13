#ifndef ITER_H
#define ITER_H

#include "Set.h"

namespace set_s
{
    template <typename Type>
    ConstIterator<Type> Set<Type>::begin() const
    {
        return ConstIterator<Type>(this->head);
    }

    template <typename Type>
    ConstIterator<Type> Set<Type>::end() const
    {
        return ConstIterator<Type>(nullptr);
    }

    template <typename Type>
    ConstIterator<Type> Set<Type>::cbegin() const
    {
        return ConstIterator<Type>(this->head);
    }

    template <typename Type>
    ConstIterator<Type> Set<Type>::cend() const
    {
        return ConstIterator<Type>(nullptr);
    }

    template <typename Type>
    std::ostream& operator<<(std::ostream& stream, const Set<Type>& set)
    {
        for (auto it = set.cbegin(); it != set.cend(); ++it)
        {
            stream << *it << " ";
        }

        return stream;
    }

    template <typename Type>
    std::istream& operator>>(std::istream& stream, Set<Type>& set)
    {
        int count;
        stream >> count;

        for (int i = 0; i < count; i++)
        {
            Type value;
            stream >> value;

            set.append(value);
        }

        return stream;
    }
}
#endif
