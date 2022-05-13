#ifndef SET_NODE_H
#define SET_NODE_H

#include <memory>

template<typename Type>
class SetNode final
{
    private:
        std::shared_ptr<SetNode<Type>> next;
        Type data;
    public:
        explicit SetNode(const Type& data);

        Type& getValue() noexcept;
        std::shared_ptr<SetNode<Type>> getNext() const noexcept;
        void setNext(std::shared_ptr<SetNode<Type>> next) noexcept;
        bool isLast() const noexcept;
};

#include "SetNode_imp.hpp"

#endif