#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object/object.h"

class Composite : public Object
{
public:
    Composite() = default;
    Composite(shared_ptr<Object> &component);
    Composite(vector<shared_ptr<Object>> vector);

    size_t size() const;

    virtual bool add(shared_ptr<Object> com) override;
    virtual bool remove(ObjectIterator &iter) override;

    virtual ObjectIterator begin() override;
    virtual ObjectIterator end() override;

    virtual bool isComposite() const override;
    virtual bool isVisible() const override {return false;};
    virtual void move(const Point &move) override;
    virtual void scale(const Point &scale) override;
    virtual void rotate(const Point &rotate) override;
    virtual void accept(std::shared_ptr<Visitor> visitor) override;
    std::vector<std::shared_ptr<Object>> getObjects() { return objects; };
private:
    vector<shared_ptr<Object>> objects;
};

#endif // COMPOSITE_H
