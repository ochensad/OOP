#include "cabin.h"

Cabin::Cabin()
{
    connect(&this->doors, &Doors::doors_opened, this, &Cabin::handle_boarding);
    connect(&this->doors, &Doors::doors_closed, this, &Cabin::handle_ready_to_move);
    connect(this, &Cabin::cabin_ready_to_board,&this->doors, &Doors::start_opening);
    connect(this, &Cabin::cabin_ready_to_move,&this->doors, &Doors::start_closing);
}

void Cabin::handle_ready_to_move()
{
    if (this->status == BOARDING)
    {
        this->status = READY_TO_MOVE;
        qDebug() << "Кабина готова к отправке.";
        emit cabin_ready_to_move();
    }
}

void Cabin::handle_moving()
{
    if (this->status == READY_TO_MOVE)
    {
        this->status = MOVING;
        qDebug() << "Кабина поехала.";
        emit cabin_moving();
    }
}

void Cabin::handle_ready_to_board()
{
    if (this->status == MOVING || this->status == READY_TO_MOVE)
    {
        this->status = READY_TO_BOARD;
        qDebug() << "Кабина остановлена и готова к погрузке-выгрузке.";
        emit cabin_ready_to_board();
    }
}

void Cabin::handle_boarding()
{
    if (this->status == READY_TO_BOARD)
    {
        this->status = BOARDING;
        qDebug() << "Погрузка-выгрузка.";
        emit cabin_boarding();
    }
}


























