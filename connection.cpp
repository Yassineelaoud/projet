#include "connection.h"
#include <QSqlDatabase>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("yassine");//inserer nom de l'utilisateur
db.setPassword("yassine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
