#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include "doors.h"

class Cabin : public QObject
{
Q_OBJECT
public:
    enum Status
    {
        READY_TO_BOARD,
        BOARDING,
        READY_TO_MOVE,
        MOVING,
    };

    Cabin();

signals:

    void cabin_ready_to_board();

    void cabin_ready_to_move();

    void cabin_moving();

    void cabin_boarding();


public slots:

    void handle_ready_to_move();

    void handle_moving();

    void handle_ready_to_board();

    void handle_boarding();

private:
    Doors doors;
    Status status = READY_TO_MOVE;
};
#endif // CABIN_H
