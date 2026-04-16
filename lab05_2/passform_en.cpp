#include "passform_en.h"
#include "ui_person_en.h"

PassFormEn::PassFormEn(AmP* person, QWidget* parent): QDialog(parent), ui(new Ui::PassFormEn) {

    ui->setupUi(this);
    printed = false;
    setWindowTitle("Pass");

    ui->firstName->setText("First Name: "  + person->firstName);
    ui->secondName->setText("Middle Name: " + person->middleName);
    ui->thirdName->setText("Last Name: "   + person->lastName);
    ui->dateEn->setText("Date: " + person->getDateEn());

    QPixmap pix("/Users/sinavinaekaterina/Desktop/фото.jpg");
    if (!pix.isNull()) {
        ui->photo->setPixmap(pix.scaled(ui->photo->width(), ui->photo->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    connect(ui->startButton,  &QPushButton::clicked, this, &PassFormEn::onPrintClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &PassFormEn::onCancelClicked);

}

PassFormEn::~PassFormEn() {
    delete ui;
}

void PassFormEn::onPrintClicked() {
    printed = true;
    accept();
}

void PassFormEn::onCancelClicked() {
    printed = false;
    reject();
}
