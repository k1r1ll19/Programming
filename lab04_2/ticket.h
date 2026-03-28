#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

struct Ticket {
    QString from;
    QString to;
    QString dateTime;
    QString place;
    bool hasBaggage;
    bool hasFood;
    bool hasTaxi;
    bool hasVip;

    Ticket(QString f, QString t, QString dt, QString pl, bool bag, bool food, bool taxi, bool vip):
        from(f), to(t), dateTime(dt), place(pl), hasBaggage(bag), hasFood(food), hasTaxi(taxi), hasVip(vip) {}

    void saveToFile() {
        QFile file(QDir::homePath() + "/Desktop/result.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out.setEncoding(QStringConverter::Utf8);
            out << "Билет:\n";
            out << "Откуда: " << from << "\n";
            out << "Куда: " << to << "\n";
            out << "Дата и время: " << dateTime << "\n";
            out << "Место: " << place << "\n";
            out << "Доп. багаж: " << (hasBaggage ? "Да" : "Нет") << "\n";
            out << "Услуги: ";
            if (!hasFood && !hasTaxi && !hasVip) {
                out << "нет";
            }
            else {
                if (hasFood) out << "Питание ";
                if (hasTaxi) out << "Такси ";
                if (hasVip) out << "VIP зал";
            }
            out << "\n------------------------\n";
            file.close();
        }
    }
};

#endif
