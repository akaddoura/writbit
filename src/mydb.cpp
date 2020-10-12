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

#include "mydb.h"

MyDb::MyDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Qt/TextEditor/db.sqlite"); //SQLite operates on a single file, which must be set as the database name when opening a connection.
    if (!db.open())
        qDebug() << "Failed to open database.";

    create_db();
}

void MyDb::open()
{
    db.open();
}
void MyDb::create_db()
{
    /*  checks if tables are already created, return if not.
        db.tables() returns a QStringList of tables in the SQL db in the order below.
        better system to sort the QStringLists first is preferred. */
    //QStringList tables = { "tags", "items", "itemtags" };
    QStringList tables = { "tags", "notes" };
    if (db.tables() != tables)
        create_tables();
    else
        return;
}

void MyDb::create_tables()
{
    // Toxi method recommends 3 tables but trying
    // it with two tables for ease of use.

    //create tags_db table
    if (!db.open())
        qDebug() << "Problem opening database.";

    QString query_1 = "CREATE TABLE tags ("
                    "note_id integer, "
                    "tag_title VARCHAR(255));";
    QSqlQuery qry_1;
    if (!qry_1.exec(query_1))
        qDebug() << "error creating tags table.";

    //create item_db talbe
    if (!db.open())
        qDebug() << "Problem opening database.";

    QString query_2 = "CREATE TABLE notes ("
                    "note_id integer, "
                    "note_title VARCHAR(255), "
                    "note_content VARCHAT(255));";

    QSqlQuery qry_2;
    if (!qry_2.exec(query_2))
        qDebug() << "error creating items table.";

    //create itemtags_db table
//    if (!db.open())
//        qDebug() << "Problem opening database.";

//    QString query_3 = "CREATE TABLE itemtags ("
//                    "item_id integer,"
//                    "tag_id integer);";
//    QSqlQuery qry_3;
//    if (!qry_3.exec(query_3))
//        qDebug() << "error creating itemtags table.";
}

void MyDb::addvalues(int id, QString title)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO tags ("
                "note_id,"
                "tag_title)"
                "VALUES (?, ?);");
    qry.addBindValue(id);
    qry.addBindValue(title);

    if (!qry.exec())
        qDebug() << "error adding values.";
}

void MyDb::close()
{
    db.close();
    db.removeDatabase("QSQLITE");
}
