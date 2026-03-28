#include "TicketWindow.h"
#include "Ticket.h"

TicketWindow::TicketWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Билет");
    resize(400, 420);

    fromEdit     = new QLineEdit();
    toEdit       = new QLineEdit();
    dateTimeEdit = new QLineEdit();
    placeEdit    = new QLineEdit();

    fromEdit->setPlaceholderText("Москва");
    toEdit->setPlaceholderText("Minsk");
    dateTimeEdit->setPlaceholderText("18.03.2026/12:30");
    placeEdit->setPlaceholderText("12F");

    baggageYes = new QRadioButton("Да");
    baggageNo  = new QRadioButton("Нет");
    baggageNo->setChecked(true);

    QHBoxLayout *baggageLayout = new QHBoxLayout();
    baggageLayout->addWidget(baggageYes);
    baggageLayout->addWidget(baggageNo);
    baggageLayout->addStretch();

    foodCheck = new QCheckBox("Питание");
    taxiCheck = new QCheckBox("Такси");
    vipCheck  = new QCheckBox("VIP зал");

    QPushButton *resetButton = new QPushButton("Сброс");
    QPushButton *saveButton  = new QPushButton("Сохранить");
    resetButton->setMinimumHeight(30);
    saveButton->setMinimumHeight(30);


    resetButton->setStyleSheet("background-color: #c90000; color: black; font-weight: bold;");
    saveButton->setStyleSheet("background-color: #07b02e; color: black; font-weight: bold;");

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(resetButton);
    buttonsLayout->addWidget(saveButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(6);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    mainLayout->addWidget(new QLabel("Откуда"));
    mainLayout->addWidget(fromEdit);
    mainLayout->addWidget(new QLabel("Куда"));
    mainLayout->addWidget(toEdit);
    mainLayout->addWidget(new QLabel("Дата и время"));
    mainLayout->addWidget(dateTimeEdit);
    mainLayout->addWidget(new QLabel("Место"));
    mainLayout->addWidget(placeEdit);
    mainLayout->addWidget(new QLabel("Доп. багаж"));
    mainLayout->addLayout(baggageLayout);
    mainLayout->addWidget(new QLabel("Услуги"));
    mainLayout->addWidget(foodCheck);
    mainLayout->addWidget(taxiCheck);
    mainLayout->addWidget(vipCheck);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    connect(resetButton, &QPushButton::clicked, this, &TicketWindow::resetForm);
    connect(saveButton,  &QPushButton::clicked, this, &TicketWindow::saveTicket);
}

QString TicketWindow::validateFields()
{
    QRegularExpression nameRx("^\\p{Lu}\\p{Ll}*$");

    if (fromEdit->text().isEmpty())
        return "Заполните поле 'Откуда'";
    if (!nameRx.match(fromEdit->text()).hasMatch())
        return "Поле 'Откуда': первая буква заглавная, остальные строчные";

    if (toEdit->text().isEmpty())
        return "Заполните поле 'Куда'";
    if (!nameRx.match(toEdit->text()).hasMatch())
        return "Поле 'Куда': первая буква заглавная, остальные строчные";

    QRegularExpression dateRx(
        "^(0[1-9]|[12][0-9]|3[01])\\.(0[1-9]|1[0-2])\\.(19|20)[0-9]{2}/([01][0-9]|2[0-3]):[0-5][0-9]$"
        );
    if (dateTimeEdit->text().isEmpty())
        return "Заполните поле 'Дата и время'";
    if (!dateRx.match(dateTimeEdit->text()).hasMatch())
        return "Поле 'Дата и время' должно быть в формате ДД.ММ.ГГГГ/ЧЧ:ММ";

    QRegularExpression placeRx("^([1-5][A-D]|([6-9]|[12][0-9]|30)[A-F])$");
    if (placeEdit->text().isEmpty())
        return "Заполните поле 'Место'";
    if (!placeRx.match(placeEdit->text()).hasMatch())
        return "Поле 'Место': 1-5 + A-D (напр. 3B) или 6-30 + A-F (напр. 15C)";

    return "";
}
void TicketWindow::resetForm()
{
    fromEdit->clear();
    toEdit->clear();
    dateTimeEdit->clear();
    placeEdit->clear();
    baggageNo->setChecked(true);
    foodCheck->setChecked(false);
    taxiCheck->setChecked(false);
    vipCheck->setChecked(false);
    fromEdit->setFocus();
}

void TicketWindow::saveTicket()
{
    QString error = validateFields();
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", error);
        return;
    }

    Ticket ticket(
        fromEdit->text(),
        toEdit->text(),
        dateTimeEdit->text(),
        placeEdit->text(),
        baggageYes->isChecked(),
        foodCheck->isChecked(),
        taxiCheck->isChecked(),
        vipCheck->isChecked()
        );

    ticket.saveToFile();
    QMessageBox::information(this, "Успех", "Билет сохранён в result.txt");
    resetForm();
}
