#include <QGuiApplication>
#include <QQmlApplicationEngine>


/*************************************************************************
 *
 * Copyright (c) 2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "User.h"
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QtQuick>
#include <QTimer>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    User user("Joe", QDate(1971, 07, 11), User::Developer);

    // Update the Role from C++ after 3 seconds.
    QTimer* timer = new QTimer(&app);
    timer->start(3000);
    QObject::connect(timer, &QTimer::timeout, &user, &User::changeRole);

    QVariantList l;




    /* here */ engine.rootContext()->setContextProperty("_userData", new User("Joe", QDate(1971, 07, 11), User::Developer));
    engine.rootContext()->setContextProperty("_haseeb", new User("haseeb", QDate(1971, 07, 11), User::Developer));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

;
    return app.exec();
}
