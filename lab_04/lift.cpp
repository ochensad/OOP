#include "lift.h"

Lift::Lift()
{
    QObject::connect(
           &this->controller, &Controller::controller_departured,
           &cabin, &Cabin::handle_moving
       );
       QObject::connect(
           &this->cabin, &Cabin::cabin_moving,
           &this->controller, &Controller::handle_start_moving
       );
       QObject::connect(
           &this->controller, &Controller::controller_reached_target,
           &cabin, &Cabin::handle_ready_to_board
       );
       QObject::connect(
           &this->cabin, &Cabin::cabin_ready_to_board,
           &this->controller, &Controller::handle_arrival
       );
       QObject::connect(
           &this->cabin, &Cabin::cabin_ready_to_move, &this->controller, &Controller::handle_free
       );
}

void Lift::call(int floor) { controller.new_target(floor); }
