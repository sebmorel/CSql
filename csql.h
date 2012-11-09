#ifndef CSQL_H
#define CSQL_H

#include "CSql_global.h"
#include "ctcpclient.h"

#include <vector>

#include <QString>
//#include <QSqlDatabase>
class QString;
class QSqlQuery;
class QVariant;
class QSqlError;
class CDataUser;
class CDataRequetes;
class CDataPieceOrg;
//class CMainWindow;



// Définition des constantes.
// Messages d'erreur liés à la base.
const QString ERR_CONNEXION("Connexion impossible à Sigal.\n"
                            "Veuillez vérifier que les cables soient correctement connectés ou que le wifi fonctionne correctement.\n"
                            "Si le problème persiste veuillez contacter votre administateur.");

const QString ERR_REQUETE("Requète erronée.\n");
const QString ERR_POSTE_ABS("Aucun poste n'est déclaré ou le poste déclaré n'existe plus.\n"
                            "Veuillez choisir un poste une fois l'application lancée.");

// Constantes des tables.
const QString TB_APPLIS("QUERY_MOR.gen_applis");
const QString TB_USERS("QUERY_MOR.gen_users");
const QString TB_DROIT("QUERY_MOR.gen_droits");
const QString TB_REQUETE("QUERY_MOR.sv_ora_requetes");
const QString TB_TABLE("QUERY_MOR.sv_ora_tables");
const QString TB_TABLE_SELEC("QUERY_MOR.sv_ora_tables_select");
const QString TB_RUBRIQUE("QUERY_MOR.sv_ora_rubs");
const QString TB_RUB_SELECT("QUERY_MOR.sv_ora_rubs_select");
const QString TB_PIECE_RELANCE("QUERY_MOR.sv_relance_piece_relancee");
const QString TB_PIECE_ORG("QUERY_MOR.sv_relance_piece_org");
const QString TB_RUB_SAISI("QUERY_MOR.sv_champs_machine");
const QString TB_POSTES("QUERY_MOR.sv_postes");
const QString TB_ESPION("QUERY_MOR.sv_relance_espion");
const QString TB_TMP_RELANCE("QUERY_MOR.tmp_relance");
const QString TB_SUIVIS("QUERY_MOR.sv_suivis");
const QString TB_RUB_SUIVIS("QUERY_MOR.sv_rub_suivis");
const QString TB_OBJECTIFS("QUERY_MOR.sv_objectifs");
const QString TB_ACT_SUIVIS("QUERY_MOR.sv_suivis_actions");

// Constantes référence des postes.
const QString REF_BREMA("M0112");
const QString REF_SELCO("U0111");
const QString REF_VERNIS("CABIN");
const QString REF_PLACAGE("U0121");
const QString REF_MONTAGE("M0151");

const unsigned int INDEX_SELCO(0);
const unsigned int INDEX_PLACAGE(1);
const unsigned int INDEX_BREMA(2);
const unsigned int INDEX_VERNIS(3);
const unsigned int INDEX_MONTAGE(4);

typedef struct dbdata{
    QString     nom_rub;
    QString     valeur;
    void        *ptrObj1;
    void        *ptrObj2;
}dbdata;

QString getIPAddress();                             // Connaître l'adresse ip du poste.
//void    InitDatabase(QSqlDatabase *db);             // Initialisation des paramètres de connexion à Oracle.

#include <QDate>

#include <iostream>


/************************************************************************************************/
/************************************************************************************************/
class CDataUser{
public:
    explicit CDataUser(void);

    int     id;
    QString nom;
    QString pwd;
    int     droit;
    bool    log_err;
    bool    no_result;

//    CDataUser    & operator= (const CDataUser &other);
    friend std::ostream & operator<< (std::ostream& flux, CDataUser const &other);
};

/************************************************************************************************/
/************************************************************************************************/
class CDataRequetes{
public:
    explicit CDataRequetes(void);

    int         id;
    QString     lib_nom;
    QString     lib_requete;
    int         module;
    bool        log_err;
    bool        no_result;
};

/************************************************************************************************/
/************************************************************************************************/
class CDataPieceOrg{
public:
    explicit CDataPieceOrg(void);

    int         id;
    QString     article_ref;
    QString     article_lib;
    QString     piece_ref;
    QString     piece_lib;
    int         hauteur;
    int         largeur;
    int         epaisseur;
    QString     matiere;
    QString     coloris;
    QString     colo_chant_avant;
    QString     colo_chant_arriere;
    QString     colo_chant_gauche;
    QString     colo_chant_droit;
    QString     prgcn1;
    QString     prgcn2;
    QString     coloris_caisson;
    QString     coloris_facade;
    QString     colo_teinte_facade;
    QString     patine1;
    QString     patine2;
    QString     coloris_rechampi;
    QString     chevi;
    QString     vfini;
    int         no_lig;
    QString     cde;
    int         no_of;
};

/************************************************************************************************/
/************************************************************************************************/
class CDataPieceRelancee{
public:
    explicit CDataPieceRelancee(void);

    int         id;
    int         piece_org_id;
    QDate       date_crea;
    QDate       date_valid;
    QDate       date_delai;
    QString     commentaire;
    QString     article;
    QString     lib;
    QString     choix_piece;
    QString     piece_lib;
    int         hauteur;
    int         largeur;
    int         epaisseur;
    QString     matiere;
    QString     coloris;
    QString     chant1dim1;
    QString     chant1dim2;
    QString     chant2dim1;
    QString     chant2dim2;
};

/************************************************************************************************/
/************************************************************************************************/
class CDataPieceGeneric{
public:
    explicit CDataPieceGeneric(void);

    int         id;
    int         piece_org_id;
    QDate       date_crea;
    QDate       date_valid;
    QDate       date_delai;
    QString     commentaire;
    QString     article;
    QString     lib;
    QString     choix_piece;
    QString     piece_lib;

    friend std::ostream & operator<< (std::ostream& flux, CDataPieceGeneric const &other);
};

/************************************************************************************************/
/************************************************************************************************/
class CDataPieceSelco : public CDataPieceGeneric{
public:
    explicit CDataPieceSelco(void);

    int         dim1;
    int         dim2;
    int         epaisseur;
    QString     matiere;
    QString     coloris;
};

/************************************************************************************************/
/************************************************************************************************/
class CDataPiecePlac : public CDataPieceGeneric{
public:
    explicit CDataPiecePlac (void);

    QString     chant1Dim1;
    QString     chant1Dim2;
    QString     chant2Dim1;
    QString     chant2Dim2;
};
/************************************************************************************************/
/************************************************************************************************/
class CDataPieceBrema : public CDataPieceSelco{
public:
    explicit CDataPieceBrema (void);

    QString     prgCn1;
    QString     prgCn2;
    QString     colca;
    QString     colcc;
};
/************************************************************************************************/
/************************************************************************************************/
class CDataPieceVernis : public CDataPieceGeneric{
public:
    explicit CDataPieceVernis(void);

    QString     colfo;
    QString     prepb;
    QString     pati1;
    QString     pati2;
    QString     colrec;
    QString     chevi;
    QString     vfini;
};
/************************************************************************************************/
/************************************************************************************************/
class CSQLSHARED_EXPORT CDataPoste {
public:
    explicit CDataPoste(void);

    QString         nom;
    QString         rubriques;
    QString         rub_aff;
    QString         code;
    unsigned int    nombre;
    QString         unit;
    unsigned int    objectif;
};
/************************************************************************************************/
/************************************************************************************************/
class CSQLSHARED_EXPORT CDataObjectif{
public:
    explicit CDataObjectif(void);

    QString         nom;
    unsigned int    objectif;
    quint64          horaire[7];
    unsigned int    objectifs[7];
    QString         requete;
};


/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
class CSQLSHARED_EXPORT CSql {
public:
    CSql();
    CSql(CTcpClient *tcp);

    bool open();
    bool isOpen();
    bool connectionError();
    QString lastError();
    int typeError();

    bool exec();
    bool exec(QString requete);
    bool seek(int pos);
    QVariant value(int pos);
    bool next();
    bool isValid();
    bool getPoste(CDataPoste *piece);
    CDataPoste *getPoste(QString nom);
    bool getObjectif(CDataObjectif *data);
    CDataObjectif *getObjectif(QString nom);
    void close();
    void removeDatabase();
    int autoIncrement(QString table);
    bool prepare(QString requete);
    bool bindValue(const QString &placeholder, const QVariant &val);


private:
    CTcpClient *_tcp;
};

#endif // CSQL_H
