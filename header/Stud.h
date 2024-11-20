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

    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getNd() const { return nd; }
    int getEgz() const { return egzaminas; }

    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setPazymiai(const vector<int>& pazymiai) { nd = pazymiai; }
    void setEgzaminas(int egz) { egzaminas = egz; }

    void duomenuived();
    void atsitiktiniuBaluGeneravimas();
    void valymas();

    ~Studentas() {}
};
double skaicGalutiniBalaVidur(const Studentas &studentas);
double skaicGalutiniBalaMed(const Studentas &studentas);
void generuotiStudentus (int studentuSkaicius, const string &failoPav);
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud);
void VectorstudentuSkaidymas(vector<Studentas>& studentai, vector<Studentas>& vargsiukai);
void ListStudentuSkaidymas(list<Studentas> & studentai, list<Studentas>& vargsiukai);

#endif // STUD_H_INCLUDED
