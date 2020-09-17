#ifndef REGISTERSLAVES_H
#define REGISTERSLAVES_H

#include <QMainWindow>

namespace Ui {
class registerSlaves;
}

class registerSlaves : public QMainWindow
{
    Q_OBJECT

public:
    explicit registerSlaves(QWidget *parent = nullptr);
    ~registerSlaves();

private:
    Ui::registerSlaves *ui;
};

#endif // REGISTERSLAVES_H
