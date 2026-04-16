#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_window.h"
#include <vector>
#include "person.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadClicked();
    void onTableDoubleClicked(int row, int col);

private:
    Ui::MainWindow* ui;
    std::vector<Person*> persons;

    void loadFromFile(QString filename);
    void fillTable();

};

#endif
