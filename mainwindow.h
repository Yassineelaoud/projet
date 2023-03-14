#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>

#include <QMainWindow>
#include "Factures.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();

    void on_Modifier_clicked();

    void on_Supprimer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
