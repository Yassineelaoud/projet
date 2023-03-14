#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Factures.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool controlesaisi();

private slots:
    void on_ajouter_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Factures e;
    int numf,code,prix;
    QString mat,date;
};

#endif // MAINWINDOW_H
