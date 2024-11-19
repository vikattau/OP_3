#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

class Studentas {
private:
    string vardas;
    string pavarde;
    int egzaminas;
    vector<int> nd;
public:
    Studentas(const string& vardas = "", const string& pavarde = "",
              const vector<int>& nd = {}, int egzaminas = 0)
        : vardas(vardas), pavarde(pavarde), nd(nd), egzaminas(egzaminas) {}

    Studentas(istream& is);

    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getNd() const { return nd; }
    int getEgz() const { return egzaminas; }

    istream& readStudent(std::istream&);

    void duomenuived();
    void atsitiktiniuBaluGeneravimas();
    void valymas();

    double skaicGalutiniBalaVidur() const;
    double skaicGalutiniBalaMed() const;



};
//void duomenuived(Studentas &Lok);
//void valymas(Studentas &Lok);
//double vidurkioSkaic(const vector<int> &pazymiai);
//double medianosSkaic(vector<int> pazymiai);
//double skaicGalutiniBalaVidur(const Studentas &studentas);
//double skaicGalutiniBalaMed(const Studentas &studentas);
//void atsitiktiniuBaluGeneravimas(Studentas &Lok);
void generuotiStudentus (int studentuSkaicius, const string &failoPav);
void isrusiuotuFailuKurimas(vector<Studentas> &stud, const string& failoPav, int rusiavimoPasirinkimas);
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud);
void VectorstudentuSkaidymas(vector<Studentas>& studentai, vector<Studentas>& vargsiukai);
void ListStudentuSkaidymas(list<Studentas> & studentai, list<Studentas>& vargsiukai);
#endif // STUD_H_INCLUDED
