#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Factures.h"

#include <QDialog>
#include <QTableView>
#include <QSortFilterProxyModel>
#include "connexion.h"
QSortFilterProxyModel *proxy = new QSortFilterProxyModel();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Connexion conn ;
    conn.ouvrirConnexion();

    Factures f;
    ui->setupUi(this);
    proxy->setSourceModel(f.afficher());
    ui->tabFactures->setModel(proxy);
}
int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    MainWindow d;
    d.show();
    return app.exec();

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_clicked()
{
    int numF=ui->numf->value();
    QString mat=ui->mat->text();
    int code=ui->code->value();
    QString date=ui->date->text();
    int prix=ui->prix->value();
    Factures ps(numF,mat,code,date,prix);
    QMessageBox msg;
    if(ps.ajouter())
    {
        msg.setText("ajout avec succés");
        //show_tables(p.afficherProduit(),ui->tabProduits);
        ui->numf->clear();
        ui->mat->clear();
        ui->code->clear();
        ui->date->clear();
        ui->prix->clear();
    }
    else
    {
        msg.setText("echec lors de l'ajout");
    }
    msg.exec();


}

void MainWindow::on_Modifier_clicked()
{
    int numF=ui->numf->value();
    QString mat=ui->mat->text();
    int code=ui->code->value();
    QString date=ui->date->text();
    int prix=ui->prix->value();
    Factures ps(numF,mat,code,date,prix);
    QMessageBox msg;
    if(ps.modifier())
    {
        msg.setText("modification avec succés");
        ui->numf->clear();
        ui->mat->clear();
        ui->code->clear();
        ui->date->clear();
        ui->prix->clear();
    }
    else
    {
        msg.setText("echec lors de la modification");
    }
    msg.exec();
}
void MainWindow::on_Supprimer_clicked()
{
}
