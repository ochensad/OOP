#include "fileloader.h"

shared_ptr<Object> FileLoader::load(shared_ptr<ModelBuilder> builder)
{
    builder->build();

    size_t points_count;

    this->file >> points_count;

    for(size_t i = 0; i < points_count; i++)
    {
        double x, y, z;
        this->file >> x >> y >> z;
        builder->buildPoint(x, y, z);
    }

    size_t connect_count;

    this->file >> connect_count;

    for(size_t i = 0; i < connect_count; i++)
    {
        size_t p1, p2;
        this->file >> p1 >> p2;
        builder->buildConnect(p1, p2);
    }

    return builder->get();
}

void FileLoader::open(std::string &fname)
{
    try
    {
        this->file.open(fname);
    }
    catch (std::ifstream::failure &error)
    {
        error.what();
    }
}

void FileLoader::close()
{
    try
    {
        this->file.close();
    } catch (std::ifstream::failure &error)
    {
        error.what();
    }
}
