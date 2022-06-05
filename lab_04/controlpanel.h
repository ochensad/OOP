#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H


#include <memory>
#include <vector>
#include <QObject>
#include <QDebug>
#include <iostream>
#include "cabin.h"
#include "constants.h"

class Controller : public QObject
{
Q_OBJECT
public:
    enum Status
    {
        FREE,
        ADDING_CALL,
        DEPARTURE,
        START_MOVING,
        MOVING,
        ARRIVAL,
    };

    Controller();
    void new_target(int floor);

signals:

    void controller_freed();

    void controller_needs_immediate_departure();

    void controller_departured();

    void controller_reached_target(const int floor);

public slots:

    void handle_adding_call(const int floor);

    void handle_departure();

    void handle_start_moving();

    void handle_moving();

    void handle_arrival();

    void handle_free();

private:
    Status status = FREE;
    std::vector<int> targets;
    int current_target = 1;
    int current_floor = 1;
    int direction = 0;
    QTimer floor_timer;
};

#endif // CONTROLPANEL_H
