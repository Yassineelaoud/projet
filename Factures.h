
#ifndef Factures_H
#define Factures_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>


class Factures
{
public:
    Factures();
    Factures(int,QString,int,QString,int);
    //setters
    void setNumFacture(int NumF){this->NumF=NumF;}
    void setMatricule(QString Mat){this->Mat=Mat;}
    void setCodeConfirmation(int Code){this->Code=Code;}
    void setdate(QString DateE){this->DateE=DateE;}
    void setprix(int Prix){this->Prix=Prix;}
    //getters

    int getNumFacture(){return NumF;}
    QString getMatricule(){return Mat;}
    int getCodeConfirmation(){return Code;}
    QString getdate(){return DateE;}
    int getprix(){return Prix;}
    //crud
    QSqlQueryModel * afficher();
    bool ajouter();
    bool modifier();
    bool supprimer(int NumF);


private:
    int NumF;
    QString Mat;
    int Code;
    QString DateE;
    int Prix;
};

#endif // Factures_H
