#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "constants.h"

typedef enum {
    OPENING,
    OPENED,
    CLOSING,
    CLOSED
} doors_state;

class Doors : public QObject
{
  Q_OBJECT

public:
  explicit Doors();

signals:
    void doors_closed();
    void doors_opened();

public slots:
    void start_opening();
    void start_closing();

private slots:
    void opened();
    void closed();

private:
    doors_state cur_state;
    QTimer doors_open_timer;
    QTimer doors_stay_timer;
    QTimer doors_close_timer;
};
#endif // DOORS_H
