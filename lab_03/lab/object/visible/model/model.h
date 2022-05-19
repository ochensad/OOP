#ifndef MODEL_H
#define MODEL_H

#include "object/object.h"
#include "object/visible/model/modelstruct/modelstructure.h"


class Model : public Object
{
public:
    Model() : structure(new ModelStructure) {};
    Model(const shared_ptr<ModelStructure> st) : structure(st) {};
    Model(const Model &model);
    ~Model() = default;

    //unique_ptr<Model> clone();
    const shared_ptr<ModelStructure> getStructure() const {return this->structure;}

    void addPoint(const Point &point);
    void addConnect(const Connect &connect);

    virtual ObjectIterator begin() override {return ObjectIterator();}
    virtual ObjectIterator end() override {return ObjectIterator();};

    virtual bool isComposite() const override {return false;};
    virtual bool isVisible() const override {return true;};
    virtual void transform(const Point &move, const Point &scale, const Point &rotate) override;
    virtual void accept(shared_ptr<Visitor> visitor) override;
private:
    shared_ptr<ModelStructure> structure;
};

#endif // MODEL_H
