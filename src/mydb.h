/***********************************************************************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * See http://www.gnu.org/licenses/ for a look at the GNU general public
 * license.
 ***********************************************************************/

#ifndef MYDB_H
#define MYDB_H

#include <QtSql>
#include <QDebug>

class MyDb
{
public:
    MyDb();

    /*
     * Warning: It is highly recommended that you do not keep a copy of the QSqlDatabase around as a member of a class,
     * as this will prevent the instance from being correctly cleaned up on shutdown.
     * If you need to access an existing QSqlDatabase, it should be accessed with database().
     * If you chose to have a QSqlDatabase member variable, this needs to be deleted
     * before the QCoreApplication instance is deleted, otherwise it may lead to undefined behavior.
     */
    QSqlDatabase db;

    void open();

    void addvalues(int id, QString title); //keep for testing, make template

    void create_db();

    void close();

private:

    void create_tables();

};

#endif // MYDB_H
