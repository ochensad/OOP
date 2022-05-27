#include "composite.h"

Composite::Composite(shared_ptr<Object> &component)
{
    this->objects.push_back(component);
}

Composite::Composite(vector<shared_ptr<Object>> vector)
{
    this->objects = vector;
}

size_t Composite::size() const
{
    return this->objects.size();
}

bool Composite::add(shared_ptr<Object> com)
{
    this->objects.push_back(com);
    return true;
}

bool Composite::remove(ObjectIterator &iter)
{
    this->objects.erase(iter);
    return true;
}

ObjectIterator Composite::begin()
{
    return this->objects.begin();
}

ObjectIterator Composite::end()
{
    return this->objects.end();
}

bool Composite::isComposite() const
{
    return true;
}

void Composite::move(const Point &move)
{
    for(auto obj : this->objects)
        obj->move(move);
}

void Composite::scale(const Point &scale)
{
    for(auto obj : this->objects)
        obj->scale(scale);
}

void Composite::rotate(const Point &rotate)
{
    for(auto obj : this->objects)
        obj->rotate(rotate);
}

void Composite::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
