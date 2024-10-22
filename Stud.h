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
//template <typename Container>
void duomenuived(Studentas &Lok);
template <typename Container>
void spausdinimas(const Container &stud);
void valymas(Studentas &Lok);
double vidurkioSkaic(const vector<int> &pazymiai);
double medianosSkaic(vector<int> pazymiai);
double skaicGalutiniBalaVidur(const Studentas &studentas);
double skaicGalutiniBalaMed(const Studentas &studentas);
void atsitiktiniuBaluGeneravimas(Studentas &Lok);
template <typename Container>
void skaitytiFaila(Container &studentai, const string & failoPavadinimas);
void generuotiStudentus (int studentuSkaicius, const string &failoPav);
void studentuSkirstymas(const vector<Studentas> &studentai, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai);
void rasytiIFaila(const vector<Studentas>& stud, const string& failoPav);
void isrusiuotuFailuKurimas(vector<Studentas> &stud, const string& failoPav, int rusiavimoPasirinkimas);
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud);
void failuTestavimas(string failoPav, vector<Studentas>& stud, int rusiavimoPasirinkimas);
template <typename Container>
void programosPasirinkimas(int ats, Container &studentai);


#endif // STUD_H_INCLUDED
