#include "Welcom_page.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "database_helpers.h"

void initializeDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("game_database.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    QString createTable = "CREATE TABLE IF NOT EXISTS waves ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "wave_number INTEGER NOT NULL)";
    if (!query.exec(createTable)) {
        qDebug() << "Couldn't create the table 'waves': one might already exist.";
    }
}

void saveWaveRecord(int waveNumber) {
    QSqlQuery query;
    query.prepare("INSERT INTO waves (wave_number) VALUES (:waveNumber)");
    query.bindValue(":waveNumber", waveNumber);

    if (!query.exec()) {
        qDebug() << "Couldn't insert the record:" << query.lastError();
    } else {
        qDebug() << "Wave record inserted successfully!";
    }
}

int getMaxWaveRecord() {
    QSqlQuery query;
    query.prepare("SELECT MAX(wave_number) FROM waves");

    if (!query.exec()) {
        qDebug() << "Couldn't retrieve the max wave record:" << query.lastError();
        return 0; // در صورت بروز خطا، مقدار ۰ برگردانده می‌شود
    }

    if (query.next()) {
        return query.value(0).toInt();
    }

    return 0; // اگر هیچ رکوردی وجود نداشته باشد، مقدار ۰ برگردانده می‌شود
}



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    initializeDatabase();
    welcom_page w;

    w.show();

    return a.exec();
}
