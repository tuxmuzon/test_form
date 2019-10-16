#include "dialog.h"
#include "QFile"
#include "QPushButton"
#include "QHBoxLayout"
#include "QMessageBox"
#include "QTextStream"
#include "QApplication"
#include "QTextCodec"

Dialog::Dialog(QObject *parent) : QDialog()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QPushButton *dialogRun = new QPushButton("Save and Close");
    mainLayout->addWidget(dialogRun);
    this->setLayout(mainLayout);
    connect(dialogRun, &QPushButton::clicked,[&](){
        QFile m_file("file.txt");

        if(!m_file.open(QIODevice::ReadWrite))
            QMessageBox::warning(this, tr("Ошибка"),
                                 tr("Ошибка открытия файла"),
                                 QMessageBox::Ok );
        else {
            QTextStream stream( &m_file );
            stream << tr("Миру мир!") << endl;
            m_file.close();
            QApplication::exit(0);
        }

    });
}
