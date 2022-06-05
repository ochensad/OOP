#include "controlpanel.h"

Controller::Controller()
{
    connect(this, &Controller::controller_needs_immediate_departure, this, &Controller::handle_departure);
    connect(this, &Controller::controller_freed, this, &Controller::handle_departure);

    this->floor_timer.setInterval(CROSSING_FLOOR);
    connect(&this->floor_timer, &QTimer::timeout, this, &Controller::handle_moving);
}

void Controller::handle_adding_call(const int floor)
{
    Status prev_status = this->status;
    this->status = ADDING_CALL;
    this->targets.push_back(floor);
    if (prev_status == FREE)
    {
        qDebug() << "Лифт вызван на этаж №" << floor << ".";
        emit controller_needs_immediate_departure();
    }
    else
    {
        qDebug() << "Вызов лифта на этаж №" << floor << "добавлен в очередь.";
    }
}

void Controller::handle_departure()
{
    if ((this->status == FREE || this->status == ADDING_CALL) && !this->targets.empty())
    {
        this->status = DEPARTURE;
        auto begin = this->targets.begin();
        this->current_target = *begin;
        this->targets.erase(begin);
        qDebug() << "Отправление на этаж №" << this->current_target;
        if (this->current_floor == this->current_target)
        {
            emit controller_reached_target(this->current_target);
        }
        else
        {
            emit controller_departured();
        }
    }
}

void Controller::handle_start_moving()
{
    if (this->status == DEPARTURE || this->status == ADDING_CALL)
    {
        this->status = START_MOVING;
        qDebug() << "Начато движение к этажу №" << this->current_target;
        this->direction = this->current_floor > this->current_target ? -1 : 1;
        this->floor_timer.start();
    }
}

void Controller::handle_moving()
{
    if (this->status != FREE && this->status != ARRIVAL)
    {
        this->status = MOVING;
        qDebug() << "Лифт на этаже №" << this->current_floor;
        if (this->current_floor == this->current_target)
        {
            this->floor_timer.stop();
            emit controller_reached_target(this->current_target);
        }
        else
        {
            this->current_floor += this->direction;
        }
    }
}

void Controller::handle_arrival()
{
    if (this->status == ADDING_CALL || this->status == MOVING || this->status == DEPARTURE)
    {
        this->status = ARRIVAL;
        qDebug() << "Прибытие на этаж №" << this->current_floor;
    }
}

void Controller::handle_free()
{
    if (this->status == ADDING_CALL || this->status == ARRIVAL)
    {
        this->status = FREE;
        qDebug() << "Выполнение вызова на этаж №" << this->current_target << "окончено.";
        emit controller_freed();
    }
}

void Controller::new_target(int floor)
{
    emit handle_adding_call(floor);
}
