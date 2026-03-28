#ifndef TICKETWINDOW_H
#define TICKETWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>

class TicketWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TicketWindow(QWidget *parent = nullptr);

private slots:
    void resetForm();
    void saveTicket();

private:
    QLineEdit *fromEdit;
    QLineEdit *toEdit;
    QLineEdit *dateTimeEdit;
    QLineEdit *placeEdit;

    QRadioButton *baggageYes;
    QRadioButton *baggageNo;

    QCheckBox *foodCheck;
    QCheckBox *taxiCheck;
    QCheckBox *vipCheck;

    QString validateFields();
};

#endif
