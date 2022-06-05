#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "basebuilder.h"
#include "object/visible/model/model.h"
#include "exeptions/exeptions.h"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() : model_ptr(nullptr) {};
    ~ModelBuilder() = default;

    virtual bool isBuild() const override;
    virtual void build() override;

    void buildPoint(const double &x, const double &y, const double &z) override;
    void buildConnect(const size_t &p_1, const size_t &p_2) override;

    shared_ptr<Model> get() override;
private:
    shared_ptr<Model> model_ptr;
};

#endif // MODELBUILDER_H
