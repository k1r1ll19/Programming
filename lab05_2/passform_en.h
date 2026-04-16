#ifndef PASSFORM_EN_H
#define PASSFORM_EN_H

#include <QDialog>
#include "person.h"

namespace Ui {
    class PassFormEn;
}

class PassFormEn : public QDialog {
    Q_OBJECT

public:
    bool printed;
    explicit PassFormEn(AmP* person, QWidget* parent = nullptr);
    ~PassFormEn();

private slots:
    void onPrintClicked();
    void onCancelClicked();

private:
    Ui::PassFormEn* ui;
};

#endif
