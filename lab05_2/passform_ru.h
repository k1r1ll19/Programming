#ifndef PASSFORM_RU_H
#define PASSFORM_RU_H

#include <QDialog>
#include "person.h"

namespace Ui {
    class PassFormRu;
}

class PassFormRu : public QDialog {
    Q_OBJECT

public:
    bool printed;
    explicit PassFormRu(RuP* person, QWidget* parent = nullptr);
    ~PassFormRu();

private slots:
    void onPrintClicked();
    void onCancelClicked();

private:
    Ui::PassFormRu* ui;
};

#endif
