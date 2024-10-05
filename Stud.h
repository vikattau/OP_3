#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

struct Studentas{
    string vardas, pavarde;
    vector<int> NamuDarbai;
    int egz;
};
void duomenuived(Studentas &Lok);
void spausdinimas(const vector<Studentas> &stud);
void valymas(Studentas &Lok);
double vidurkioSkaic(const vector<int> &pazymiai);
double medianosSkaic(vector<int> pazymiai);
double skaicGalutiniBalaVidur(const Studentas &studentas);
double skaicGalutiniBalaMed(const Studentas &studentas);
void atsitiktiniuBaluGeneravimas(Studentas &Lok);
void skaitytiFaila(vector<Studentas> &studentai, const string & failoPavadinimas);
void generuotiStudentus (int studentuSkaicius, const string &failoPav);
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud);



#endif // STUD_H_INCLUDED
