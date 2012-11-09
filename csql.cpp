#include "csql.h"

class CTcpClient;

/************************************************************************************************/
CDataUser::CDataUser()
{
    id = 0;
    nom = QString::null;
    pwd = QString::null;
    droit = 0x00;
    log_err = false;
    no_result = false;
}
std::ostream & operator<< (std::ostream& flux, CDataUser const &other)
{
    QString s, num;
    s = "{id:"+num.setNum(other.id)+", nom:'"+other.nom+"', pwd:'"+other.pwd+"', droit:"+num.setNum(other.droit)+", log_err:"+(other.log_err?"true":"false")+", no_result:"+(other.no_result?"true":"false");
    flux << s.toStdString();
    return flux;
}

/************************************************************************************************/
CDataRequetes::CDataRequetes()
{
    lib_nom = QString::null;
    lib_requete = QString::null;
    module = 0;
    no_result = false;
    log_err = false;
}

/************************************************************************************************/
CDataPieceOrg::CDataPieceOrg()
{
    id = 0;
    article_ref = QString::null;
    article_lib = QString::null;
    piece_ref = QString::null;
    piece_lib = QString::null;
    hauteur = 0;
    largeur = 0;
    epaisseur = 0;
    matiere = QString::null;
    coloris = QString::null;
    colo_chant_avant = QString::null;
    colo_chant_arriere = QString::null;
    colo_chant_gauche = QString::null;
    colo_chant_droit = QString::null;
    prgcn1 = QString::null;
    prgcn2 = QString::null;
    coloris_caisson = QString::null;
    coloris_facade = QString::null;
    colo_teinte_facade = QString::null;
    patine1 = QString::null;
    patine2 = QString::null;
    coloris_rechampi = QString::null;
    chevi = QString::null;
    vfini = QString::null;
    cde = QString::null;
    no_lig = 0;
    no_of = 0;
}

/************************************************************************************************/
CDataPieceRelancee::CDataPieceRelancee()
{
    piece_org_id = 0;
    date_crea = QDate::currentDate();
    date_valid = QDate::currentDate();
    date_delai = QDate::currentDate();
    commentaire = QString::null;
    article = QString::null;
    lib = QString::null;
    choix_piece = QString::null;
    piece_lib = QString::null;
    largeur = 0;
    hauteur = 0;
    epaisseur = 0;
    matiere = QString::null;
    coloris = QString::null;
    chant1dim1 = QString::null;
    chant1dim2 = QString::null;
    chant2dim1 = QString::null;
    chant2dim2 = QString::null;
}

/************************************************************************************************/
CDataPieceGeneric::CDataPieceGeneric()
{
    piece_org_id = 0;
    date_crea = QDate::currentDate();
    date_valid = QDate::currentDate();
    date_delai = QDate::currentDate();
    commentaire = QString::null;
    lib = QString::null;
    choix_piece = QString::null;
    piece_lib = QString::null;
}

std::ostream & operator<< (std::ostream& flux, CDataPieceGeneric const &other)
{
    QString s, num;
    s = "{id:"+num.setNum(other.id)+", piece_org_id:'"+other.piece_org_id+"', date_crea:'"+other.date_crea.toString()+"', date_valid:'"+other.date_valid.toString()+"', date_delai:'"+other.date_delai.toString()+"', commentaire:'"+other.commentaire+"', lib:'"+other.lib+"', choix_piece:'"+other.choix_piece+"', piece_lib:'"+other.piece_lib+"'}";
    flux << s.toStdString();
    return flux;
}

/************************************************************************************************/
CDataPieceSelco::CDataPieceSelco()
{
    dim1 = -1;
    dim2 = -1;
    epaisseur = -1;
    matiere = QString::null;
    coloris = QString::null;
}

/************************************************************************************************/
CDataPiecePlac::CDataPiecePlac()
{
    chant1Dim1 = QString::null;
    chant1Dim2 = QString::null;
    chant2Dim1 = QString::null;
    chant2Dim2 = QString::null;
}
/************************************************************************************************/
CDataPieceBrema::CDataPieceBrema()
{
    prgCn1 = QString::null;
    prgCn2 = QString::null;
    colca = QString::null;
    colcc = QString::null;
}
/************************************************************************************************/
CDataPieceVernis::CDataPieceVernis()
{
    colfo = QString::null;
    prepb = QString::null;
    pati1 = QString::null;
    pati2 = QString::null;
    colrec = QString::null;
    chevi = QString::null;
    vfini = QString::null;
}
/************************************************************************************************/
CDataPoste::CDataPoste()
{
    nom = QString::null;
    nombre = 0;
    rubriques = QString::null;
    code = QString::null;
    unit = QString::null;
    objectif = 0;
}
/************************************************************************************************/
CDataObjectif::CDataObjectif()
{
    nom = QString::null;
    objectif = 0;
//    horaire;
    requete = QString::null;
//    objectifs = {0};
}
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/

CSql::CSql()
{
}

CSql::CSql(CTcpClient *tcp)
{
    _tcp = tcp;
}
/************************************************************************************************/
bool CSql::open(){
    std::cout << "oyo" << std::endl;
    std::cout << "tcp : " << _tcp->state() << std::endl;
    while(CTcpClient::ConnectedState != _tcp->state());
    return _tcp->sqlOpen();
}
bool CSql::isOpen(){
    return _tcp->sqlIsOpen();
}
/************************************************************************************************/
QString CSql::lastError(){
    return _tcp->sqlError();
}
int CSql::typeError(){
    return _tcp->sqlTypeError();
}
/************************************************************************************************/
bool CSql::exec(){
    return _tcp->sqlExec();
}
bool CSql::exec(QString requete){
    _tcp->sqlRequete(requete);
    return _tcp->sqlExec();
}
/************************************************************************************************/
bool CSql::seek(int pos){
    return _tcp->sqlSeek(pos);
}
/************************************************************************************************/
QVariant CSql::value(int pos){
    return _tcp->sqlValue(pos);
}
/************************************************************************************************/
bool CSql::next(){
    return _tcp->sqlNext();
}
/************************************************************************************************/
bool CSql::isValid(){
    return _tcp->sqlIsValid();
}
/************************************************************************************************/
bool CSql::prepare(QString requete){
    return _tcp->sqlPrepare(requete);
}
/************************************************************************************************/
bool CSql::bindValue(const QString &placeholder, const QVariant &val){
    return _tcp->sqlBindValue(placeholder, val);
}
/************************************************************************************************/
bool CSql::getPoste(CDataPoste *piece){
    bool bOk(false);

    if (piece->nom.isNull()){}
    else{
        if (exec("SELECT RTrim(nombre), RTrim(code), RTrim(rubriques), RTrim(rub_aff), RTrim(unit), RTrim(objectif) FROM "+TB_POSTES+" WHERE nom='"+piece->nom+"'")){
//        if (m_query->exec("SELECT RTrim(nombre), RTrim(code), RTrim(rubriques), RTrim(rub_aff), RTrim(unit), RTrim(objectif) FROM "+TB_POSTES+" WHERE nom='"+piece->nom+"'")){
            seek(0);
//            m_query->seek(0);
            if(isValid()){
//            if (m_query->isValid()){
                piece->nombre = value(0).toInt(); //m_query->value(0).toInt();
                piece->code = value(1).toString(); //m_query->value(1).toString();
                piece->rubriques = value(2).toString(); //m_query->value(2).toString();
                piece->rub_aff = value(3).toString(); //m_query->value(3).toString();
                piece->unit = value(4).toString(); //m_query->value(4).toString();
                piece->objectif = value(5).toInt(); //m_query->value(5).toInt();
            }
        }
    }
    return bOk;
}
CDataPoste *CSql::getPoste(QString nom){
    CDataPoste *poste = new CDataPoste;
    poste->nom = nom;
    getPoste(poste);
    return poste;
}
/************************************************************************************************/
bool CSql::connectionError(){
    return false;
}
/************************************************************************************************/
int CSql::autoIncrement(QString table)
{
    QString qstr;
    qstr = "SELECT MAX(id) FROM "+table;
    exec(qstr);
    seek(0);

    return (value(0).toInt()+1);
}
/************************************************************************************************/
CDataObjectif *CSql::getObjectif(QString nom)
{
    CDataObjectif *obj = new CDataObjectif;
    obj->nom = nom;
    getObjectif(obj);
    return obj;
}
/************************************************************************************************/
bool CSql::getObjectif(CDataObjectif *data)
{
    bool b(false);

    exec("SELECT objectif, RawToHex(h_lun), RawToHex(h_mar), RawToHex(h_mer), RawToHex(h_jeu), "
                         "RawToHex(h_ven), RawToHex(h_sam), RawToHex(h_dim), requete, "
                         "o_lun, o_mar, o_mer, o_jeu, o_ven, o_sam, o_dim FROM "+TB_OBJECTIFS+" WHERE nom='"+data->nom+"'");
    if(exec()){
//    if (m_query->exec("SELECT objectif, RawToHex(h_lun), RawToHex(h_mar), RawToHex(h_mer), RawToHex(h_jeu), "
//                      "RawToHex(h_ven), RawToHex(h_sam), RawToHex(h_dim), requete, "
//                      "o_lun, o_mar, o_mer, o_jeu, o_ven, o_sam, o_dim FROM "+TB_OBJECTIFS+" WHERE nom='"+data->nom+"'")){
        seek(0);
//        m_query->seek(0);
        if(isValid()){
//        if (m_query->isValid()){
            data->objectif = value(0).toUInt(); //m_query->value(0).toUInt();
            data->horaire[0] = value(1).toULongLong(); //m_query->value(1).toULongLong();
            data->horaire[1] = value(2).toULongLong(); //m_query->value(2).toULongLong();
            data->horaire[2] = value(3).toULongLong(); //m_query->value(3).toULongLong();
            data->horaire[3] = value(4).toULongLong(); //m_query->value(4).toULongLong();
            data->horaire[4] = value(5).toULongLong(); //m_query->value(5).toULongLong();
            data->horaire[5] = value(6).toULongLong(); //m_query->value(6).toULongLong();
            data->horaire[6] = value(7).toULongLong(); //m_query->value(7).toULongLong();
            data->requete = value(8).toString(); //m_query->value(8).toString();
            data->objectifs[0] = value(9).toUInt(); //m_query->value(9).toUInt();
            data->objectifs[1] = value(10).toUInt(); //m_query->value(10).toUInt();
            data->objectifs[2] = value(11).toUInt(); //m_query->value(11).toUInt();
            data->objectifs[3] = value(12).toUInt(); //m_query->value(12).toUInt();
            data->objectifs[4] = value(13).toUInt(); //m_query->value(13).toUInt();
            data->objectifs[5] = value(14).toUInt(); //m_query->value(14).toUInt();
            data->objectifs[6] = value(15).toUInt(); //m_query->value(15).toUInt();
            b = true;
        }
    }
    else {
    }

    return b;
}
