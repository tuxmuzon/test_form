#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>
#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DIALOG_H
