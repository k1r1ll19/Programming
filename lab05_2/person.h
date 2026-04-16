#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QWidget>

struct Date {
    int day;
    int month;
    int year;
};

class Person {
public:
    int code;
    QString lastName;
    QString firstName;
    Date birthDate;

    virtual ~Person() {}

    virtual bool Craft(QWidget* parent) = 0;

    virtual QString getFullName() = 0;

    QString getDateRu() {
        return QString("%1.%2.%3")
            .arg(birthDate.day,   2, 10, QChar('0'))
            .arg(birthDate.month, 2, 10, QChar('0'))
            .arg(birthDate.year,  4, 10, QChar('0'));
    }

};

class RuP : public Person {
public:
    QString patronymic;

    RuP(int c, QString ln, QString fn, QString patr, int d, int m, int y) {
        code       = c;
        lastName   = ln;
        firstName  = fn;
        patronymic = patr;
        birthDate.day   = d;
        birthDate.month = m;
        birthDate.year  = y;
    }

    bool Craft(QWidget* parent) override;
    QString getFullName() override {
        return lastName + " " + firstName + " " + patronymic;
    }
};

class AmP : public Person {
public:
    QString middleName;

    AmP(int c, QString fn, QString mn, QString ln, int m, int d, int y) {
        code       = c;
        firstName  = fn;
        middleName = mn;
        lastName   = ln;
        birthDate.month = m;
        birthDate.day   = d;
        birthDate.year  = y;
    }

    bool Craft(QWidget* parent) override;
    QString getFullName() override {
        return firstName + " " + middleName + " " + lastName;
    }
    QString getDateEn() {
        return QString("%1-%2-%3")
            .arg(birthDate.month, 2, 10, QChar('0'))
            .arg(birthDate.day,   2, 10, QChar('0'))
            .arg(birthDate.year,  4, 10, QChar('0'));
    }
};

#endif
