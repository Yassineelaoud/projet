#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QSqlQuery>
#include<QString>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_NumF_supp->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_NumF_2->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
    ui->le_Prix_2->setValidator( new QIntValidator(0, 99, this));
    ui->le_Code_2->setValidator( new QIntValidator(0, 99, this));

    ui->le_mat_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_DateE_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_NumF->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
    ui->le_Prix->setValidator( new QIntValidator(0, 99, this));
    ui->le_mat->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_Code->setValidator( new QIntValidator(0, 99, this));

    ui->le_DateE->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->tab_factures->setModel(e.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::controlesaisi()
{
    QRegExp mailRex("\\b[A-Z,a-z0-9._%+-]+@[A-Z,a-z0-9.-]+\\.[A-Z,a-z]{2,4}\\b");
    mailRex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRex.setPatternSyntax(QRegExp::RegExp);


    if (

                !(ui->le_mat->text().contains(QRegExp("^[A-Za-z]+$"))) ||

                !(ui->le_DateE->text().contains(QRegExp("^[A-Za-z]+$"))) ||


                ui->le_NumF->text().isEmpty() ||

                ui->le_NumF->text().toInt() == 0 ||

                !(mailRex.exactMatch(ui->le_Code->text())))



            return 0;

        else

            return 1;


}

void MainWindow::on_ajouter_clicked()
{
    int NumF=ui->le_NumF->text().toInt();
    QString mat=ui->le_mat->text();
    QString DateE=ui->le_DateE->text();
    int code=ui->le_Code->text().toInt();
    int Prix=ui->le_Prix->text().toInt();

    Factures e (NumF,mat,code,DateE,Prix);
     bool test=e.ajouter();
   if (test)
    test=e.ajouter();
       if(test)
       {
           ui->tab_factures->setModel(e.afficher());
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
      else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       ui->le_NumF->clear();
       ui->le_mat->clear();
       ui->le_DateE->clear();
       ui->le_Code->clear();
       ui->le_Prix->clear();
}


void MainWindow::on_modifier_clicked()
{
    int NumF=ui->le_NumF_2->text().toInt();
        QString mat=ui->le_mat_2->text();
        QString DateE=ui->le_DateE_2->text();
        int code=ui->le_Code_2->text().toInt();
        int Prix=ui->le_Prix_2->text().toInt();
        Factures e (NumF,mat,code,DateE,Prix);
        bool test=e.modifier();
        if(test){
            ui->tab_factures->setModel(e.afficher());
            QMessageBox::information(nullptr,"modification activite","activite modifie avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","activite non modifie");


         ui->le_NumF->clear();
         ui->le_mat->clear();
         ui->le_DateE->clear();
         ui->le_Code->clear();
         ui->le_Prix->clear();

}

void MainWindow::on_supprimer_clicked()
{
    Factures e1;
    e1.setNumFacture(ui->le_NumF_supp->text().toInt());
        //bool test=false;
        //bool trouver=e1.verification(e1.getNumF());
       // if (trouver)
             bool test=e.supprimer(e1.getNumFacture());
        QMessageBox msgBox;

        if (test)
        {

          msgBox.setText("Supprimer avec succes.");
          ui->tab_factures->setModel(e.afficher());

        }

        else
           msgBox.setText("Echec de suppression");
           msgBox.exec();

           ui->le_NumF_supp->clear();
}
