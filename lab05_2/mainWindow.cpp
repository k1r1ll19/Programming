#include "mainwindow.h"
#include "ui_window.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHeaderView>

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle("Лабораторная работа 5");

    ui->usersTable->setColumnCount(3);
    ui->usersTable->setHorizontalHeaderLabels({"ФИО", "Дата рождения", "Тип"});
    ui->usersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->usersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->usersTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->usersTable->setColumnWidth(1, 130);
    ui->usersTable->setColumnWidth(2, 60);

    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadClicked);

    connect(ui->usersTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::onTableDoubleClicked);

}

MainWindow::~MainWindow() {
    for (Person* p : persons) delete p;
    delete ui;
}

void MainWindow::onLoadClicked() {
    QString filename = QFileDialog::getOpenFileName(
        this, "Открыть файл", "", "Text files (*.txt);;All files (*)"
        );
    if (filename.isEmpty()) return;

        loadFromFile(filename);
    fillTable();

}

void MainWindow::loadFromFile(QString filename) {
    for (Person* p : persons) delete p;
    persons.clear();

        QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList p = line.split(" ");
        if (p.size() < 8) continue;

        QString type = p[0];
        int code     = p[1].toInt();

        if (type == "R") {
            persons.push_back(new RuP(
                code, p[2], p[3], p[4], p[5].toInt(), p[6].toInt(), p[7].toInt()
            ));
        } else if (type == "A") {
            persons.push_back(new AmP(
                code, p[2], p[3], p[4], p[5].toInt(), p[6].toInt(), p[7].toInt()
            ));
        }
    }
    file.close();
}

void MainWindow::fillTable() {
    ui->usersTable->setRowCount(0);

        for (int i = 0; i < (int)persons.size(); i++) {
        ui->usersTable->insertRow(i);
        Person* p = persons[i];

        ui->usersTable->setItem(i, 0, new QTableWidgetItem(p->getFullName()));
        ui->usersTable->setItem(i, 1, new QTableWidgetItem(p->getDateRu()));

        RuP* rup = dynamic_cast<RuP*>(p);
        QString typeName = (rup != nullptr) ? "RuP" : "AmP";
        ui->usersTable->setItem(i, 2, new QTableWidgetItem(typeName));
    }

}

void MainWindow::onTableDoubleClicked(int row, int col) {
    if (row < 0 || row >= (int)persons.size()) return;

        bool shouldRemove = persons[row]->Craft(this);

    if (shouldRemove) {
        delete persons[row];
        persons.erase(persons.begin() + row);
        fillTable();
    }

}
