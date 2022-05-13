#ifndef SETNODE_HPP
#define SETNODE_HPP

template <typename Type>
SetNode<Type>::SetNode(const Type& data)
    : data(data)
    , next(nullptr)
{
}

template <typename Type>
Type& SetNode<Type>::getValue() noexcept
{
    return this->data;
}

template <typename Type>
std::shared_ptr<SetNode<Type>> SetNode<Type>::getNext() const noexcept
{
    return this->next;
}

template <typename Type>
void SetNode<Type>::setNext(std::shared_ptr<SetNode<Type>> next) noexcept
{
    this->next = next;
}

template <typename Type>
bool SetNode<Type>::isLast() const noexcept
{
    return this->next.get() != nullptr;
}

#endif // SETNODE_HPP
