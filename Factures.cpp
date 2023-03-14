#include "Factures.h"

Factures::Factures()
{

}
Factures::Factures(int NumF,QString Mat,int Code,QString DateE,int Prix)
{
    this->NumF=NumF;
    this->Mat=Mat;
    this->Code=Code;
    this->DateE=DateE;
    this->Prix=Prix;
}

bool Factures::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO FACTURE (NUM_FACTURE,MATRICULE,CODE_DE_CONFIRMATION,DATE_DEXPIRATION,PRIX) "
                        "VALUES (:NUMF, :MATR, :CODECONF,:DATEE,:PRIXE)");
    query.bindValue(":NUMF",NumF );
    query.bindValue(":MATR",Mat); //remplir la valeur d'une maniere securisée
    query.bindValue(":CODECONF", Code);
    query.bindValue(":DATEE", DateE);
    query.bindValue(":PRIXE",Prix);
    return    query.exec();
}

QSqlQueryModel * Factures::afficher()
{

    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("SELECT *FROM FACTURE");
    return modal;
}

bool Factures::supprimer (int NumF)
{

    QSqlQuery query;
    qDebug()<<"NUMF"<<NumF;
    query.prepare("Delete from FACTURE where NUM_FACTURE = :NUMF");
    query.bindValue(":NUMF",NumF);
    return query.exec();
}

bool Factures::modifier()
{

    QSqlQuery query;

          query.prepare("UPDATE FACTURE SET MATRICULE=:MAT,CODE_DE_CONFIRMATION=:CODE, DATE_DEXPIRATION=:DATE,PRIX=:PRIXE WHERE NUM_FACTURE=:NUMF");
          query.bindValue(":NUMF", NumF);
          query.bindValue(":MAT", Mat);
          query.bindValue(":CODE", Code);
          query.bindValue(":DATEE", DateE);
          query.bindValue(":PRIXE", Prix);
          return query.exec();
}
