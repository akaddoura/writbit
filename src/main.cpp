#include "mainwindow.h"
#include <QApplication> //handles widgets, event handling, mouse movement, overall look and feel
#include <QtSql>
#include <QDebug>
#include <mydb.h>
#include <QFileInfo>
#include <QDir>

void addnotesvalues(int id, QString title, QString content);
void addtagvalues(int id, QString title);
void createDbTables(QSqlDatabase& db);
void checkDbTables(QSqlDatabase& db);
bool fileExists(QString path);

int main(int argc, char *argv[])
{
#if !defined(Q_OS_MAC)
	if (!qEnvironmentVariableIsSet("QT_DEVICE_PIXEL_RATIO")
			&& !qEnvironmentVariableIsSet("QT_AUTO_SCREEN_SCALE_FACTOR")
			&& !qEnvironmentVariableIsSet("QT_SCALE_FACTOR")
			&& !qEnvironmentVariableIsSet("QT_SCREEN_SCALE_FACTORS")) {
		QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	}
#endif
    
//    qDebug() << QSslSocket::sslLibraryBuildVersionString();
//    qDebug() << QSslSocket::supportsSsl();
//    qDebug() << QSslSocket::sslLibraryVersionString();


    QApplication app(argc, argv); //creates app object
    qDebug() << "start";
    
    QString appDirectory = app.applicationDirPath();
    QString userDir;
    
    if (userDir.isEmpty())
    {
        userDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        if (!QFile::exists(userDir)) 
        {
                    QDir dir(userDir);
                    dir.mkpath(dir.absolutePath());   
        }
    }
    
    // Create base user data path
	QDir dir(userDir);
	if (!dir.exists()) {
		dir.mkpath(dir.absolutePath());
	}
    
    QString appdir = app.applicationDirPath();
    QStringList datadirs;

    app.setOrganizationName("Five Turtles Studios");
    app.setOrganizationDomain("FiveTurtles.fu");
    app.setApplicationName("UnderTheSheets");
    MainWindow w;   //create main app object
    w.show();

    qDebug() << "end";
    return app.exec(); //put app into a loop in which events in app will be handled
}


