#include <QCoreApplication>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include "QtSimpleLog.h"

int main(int argc, char **argv)
{
    QT_SIMPLE_LOG
    QCoreApplication app(argc, argv);
    qDebug()<<"Test Test Test";

    if (output)
        fclose(output);
    return app.exec();
}
