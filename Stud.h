#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

struct Studentas{
    string vardas, pavarde;
    vector<int> NamuDarbai;
    int egz;
    double galutinisBalasVid;
    double galutinisBalasMed;
};
void duomenuived(Studentas &Lok);
void valymas(Studentas &Lok);
double vidurkioSkaic(const vector<int> &pazymiai);
double medianosSkaic(vector<int> pazymiai);
double skaicGalutiniBalaVidur(const Studentas &studentas);
double skaicGalutiniBalaMed(const Studentas &studentas);
void atsitiktiniuBaluGeneravimas(Studentas &Lok);
void generuotiStudentus (int studentuSkaicius, const string &failoPav);
void isrusiuotuFailuKurimas(vector<Studentas> &stud, const string& failoPav, int rusiavimoPasirinkimas);
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud);
void VectorstudentuSkaidymasIstrinant(vector<Studentas>& studentai, vector<Studentas>& vargsiukai);
#endif // STUD_H_INCLUDED
