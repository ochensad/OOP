#include "connect.h"

Connect::Connect(const Connect &con)
{
    this->first_point_index = con.first_point_index;
    this->second_point_index = con.second_point_index;
}

size_t Connect::getFirstPoint() const
{
    return this->first_point_index;
}

size_t Connect::getSecondPoint() const
{
    return this->second_point_index;
}

void Connect::setFirstPoint(const size_t &fst)
{
    this->first_point_index = fst;
}

void Connect::setSecondPoint(const size_t &snd)
{
    this->second_point_index = snd;
}
