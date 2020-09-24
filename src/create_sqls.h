#ifndef CREATE_SQLS_H
#define CREATE_SQLS_H

#endif // CREATE_SQLS_H

#include <QtSql>
#include <QDebug>


void create_tables(QSqlDatabase db)
{
    //create tags_db table
    if (!db.open())
        qDebug() << "Problem opening tags database.";

    QString query_1 = "CREATE TABLE tags ("
                    "tag_id integer,"
                    "tag_title VARCHAR(255));";
    QSqlQuery qry_1;
    if (!qry_1.exec(query_1))
        qDebug() << "error creating tags table.";

    //create item_db talbe
    if (!db.open())
        qDebug() << "Problem opening items database.";

    QString query_2 = "CREATE TABLE items ("
                    "item_id integer,"
                    "item_title VARCHAR(255));";
    QSqlQuery qry_2;
    if (!qry_2.exec(query_2))
        qDebug() << "error creating items table.";


    //create itemtags_db table
    if (!db.open())
        qDebug() << "Problem opening itemtags database.";

    QString query_3 = "CREATE TABLE itemtags ("
                    "item_id integer,"
                    "tag_id integer);";
    QSqlQuery qry_3;
    if (!qry_3.exec(query_3))
        qDebug() << "error creating itemtags table.";
}

void create_db(QSqlDatabase db)
{
    /*  checks if tables are already created, return if not.
        db.tables() returns a QStringList of tables in the SQL db in the order below.
        better system to sort the QStringLists first is preferred. */
    QStringList tables = { "tags", "items", "itemtags" };
    if (db.tables() != tables)
        create_tables(db);
    else
        return;
}

void close_dbs(QSqlDatabase db)
{
    db.close();
}
