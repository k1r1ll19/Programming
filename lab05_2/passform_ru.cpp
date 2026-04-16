#include "passform_ru.h"
#include "ui_person_ru.h"

PassFormRu::PassFormRu(RuP* person, QWidget* parent): QDialog(parent), ui(new Ui::PassFormRu) {

    ui->setupUi(this);
    printed = false;
    setWindowTitle("Пропуск");

    ui->lastname->setText("Фамилия: " + person->lastName);
    ui->name->setText("Имя: " + person->firstName);

    QString patr = (person->patronymic == "-") ? "" : person->patronymic;
    ui->surname->setText("Отчество: " + patr);

    ui->date->setText("Дата: " + person->getDateRu());

    QPixmap pix("/Users/sinavinaekaterina/Desktop/фото.jpg");
    if (!pix.isNull()) {
        ui->photo->setPixmap(
            pix.scaled(ui->photo->width(), ui->photo->height(),
                       Qt::KeepAspectRatio, Qt::SmoothTransformation)
            );
    }

    connect(ui->startButton,  &QPushButton::clicked, this, &PassFormRu::onPrintClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &PassFormRu::onCancelClicked);

}

PassFormRu::~PassFormRu() {
    delete ui;
}

void PassFormRu::onPrintClicked() {
    printed = true;
    accept();
}

void PassFormRu::onCancelClicked() {
    printed = false;
    reject();
}
