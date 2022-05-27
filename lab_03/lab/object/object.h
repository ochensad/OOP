#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <memory>
#include "visible/model/modelstruct/point.h"
#include "visitor/visitor.h"

using namespace std;

class Object;
using ObjectIterator = vector<shared_ptr<Object>>::iterator;

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(shared_ptr<Object>) {return false;};
    virtual bool remove(ObjectIterator &) {return false;};

    virtual ObjectIterator begin() = 0;
    virtual ObjectIterator end() = 0;

    virtual bool isComposite() const {return false;};
    virtual bool isVisible() const {return false;};
    virtual void accept(shared_ptr<Visitor> visitor) = 0;
    virtual void move(const Point &move) = 0;
    virtual void scale(const Point &scale) = 0;
    virtual void rotate(const Point &rotate) = 0;

};

#endif // OBJECT_H
