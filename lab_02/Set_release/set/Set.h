#ifndef SET_H
#define SET_H

#include <stdarg.h>
#include <iostream>
#include <memory>

#include "../base/base_container.h"
//#include "../iterator/iterator.h"
//#include "../const_iterator/const_iterator.hpp"
#include "../exceptions/exceptions.h"
#include "SetNode.h"

using namespace std;

template<typename U>
class ConstIterator;

namespace set_s
{
    template<typename Type>
    class Set : public base_container
    {
        public:
            //friend class ConstIterator<Type>;
            // Конструкторы
            Set(); // +
            explicit Set(unsigned size, ...); // +
            Set(const Type *arr, size_t size);//+
            Set(std::initializer_list<Type> list);
            Set(const Type& elem);//+
            Set(const Set& s); // +
            Set(const Set<Type> &&s) noexcept; // +
            Set(const ConstIterator<Type>& begin, const ConstIterator<Type>& end);

            // Деконструктор
            virtual ~Set();

            // Операторы присваивания

            Set<Type>& operator=(const Set<Type>& s);//+
            Set<Type>& operator=(const Set<Type>&& s);//+

            friend class ConstIterator;
            ConstIterator<Type> begin() const;
            ConstIterator<Type> end() const;
            ConstIterator<Type> cbegin() const;
            ConstIterator<Type> cend() const;

            //Операции над множеством
            Set<Type>& set_union(const Set<Type>& s1); // +
            Set<Type>& operator +=(const Set<Type>& s2);// +
            Set<Type>& operator |=(const Set<Type>& s2);// +
            Set<Type> operator +(const Set<Type>& right) const;// +
            Set<Type> operator |(const Set<Type>& right) const;// +

            Set<Type>& set_dif(const Set<Type>& s1); // +
            Set<Type>& operator -=(const Set<Type>& s2);// +
            Set<Type>& operator /=(const Set<Type>& s2);// +
            Set<Type> operator -(const Set<Type>& right) const;// +
            Set<Type> operator /(const Set<Type>& right) const;// +

            Set<Type>& set_cross(const Set<Type>& s1); // +
            Set<Type>& operator *=(const Set<Type>& s2);// +
            Set<Type>& operator &=(const Set<Type>& s2);// +
            Set<Type> operator *(const Set<Type>& right)const;// +
            Set<Type> operator &(const Set<Type>& right)const;// +

            Set<Type>& set_sym_dif(const Set<Type>& s1); // +
            Set<Type>& operator %=(const Set<Type>& s2);// +
            Set<Type>& operator ^=(const Set<Type>& s2);// +
            Set<Type> operator %(const Set<Type>& right) const;// +
            Set<Type> operator ^(const Set<Type>& right) const;// +

            // Бинарные операторы

            bool operator ==(const Set<Type>& s2); // +
            bool operator !=(const Set<Type>& s2); // +
            bool operator >=(const Set<Type>& s2); // +
            bool operator <=(const Set<Type>& s2); // +
            bool operator >(const Set<Type>& s2); // +
            bool operator <(const Set<Type>& s2); // +

            // Работа с множеством
            bool add(const Type& elem); // +
            bool exist(const Type& elem) const; // +
            bool erase(const Type& elem); // +
            bool is_subsetof(const Set<Type>& s1) const; // +
            bool contains(const Type& val) const;

            virtual bool is_empty() const override; // +
            virtual size_t get_size() const override; // +

        private:
            std::shared_ptr<SetNode<Type>> head;
            std::shared_ptr<SetNode<Type>> tail;

    };
}

#include "../const_iterator/const_iterator.hpp"

#include "Set_bool.hpp"
#include "Set_constr.hpp"
#include "Set_func.hpp"
#include "Set_iter.hpp"
#include "Set_oper.hpp"

#endif
