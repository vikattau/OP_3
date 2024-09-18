#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

struct Studentas{
    std::string vardas, pavarde;
    std::vector<int> NamuDarbai;
    int egz, rez;
};

void duomenuived(Studentas &Lok){
    cout<<"Iveskite Varda, Pavarde ir Egzamino rezultata: ";
    cin>>Lok.vardas>>Lok.pavarde>>Lok.egz;
    cout<<"Kiek Namu darbu pazymiu ivesite?: ";
    int x;
    cin>>x;
    Lok.NamuDarbai.resize(x);
    for(int i=0; i<x; i++){
        cout<<"Iveksite Namu darbu pazymi " << (i + 1) <<": ";
        cin >> Lok.NamuDarbai[i];
    };
};
void valymas(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.NamuDarbai.clear();
}
double vidurkioSkaic(const vector<int> &pazymiai){
    int suma = 0;
    for(int pazymys : pazymiai){
        suma += pazymys;
    };
    return suma/static_cast<double>(pazymiai.size());
};
double skaicGalutiniBala(const Studentas &studentas){
    double vidutinisND = vidurkioSkaic(studentas.NamuDarbai);
    return (vidutinisND * 0.4) + (studentas.egz * 0.6);
};
void spausdinimas(Studentas Lok){
    cout<< std::setw(15) << std::left << Lok.pavarde
        << std::setw(15) << std::left << Lok.vardas
        << std::setw(20) << std::left << skaicGalutiniBala(Lok);
};
int main()
{
    vector<Studentas> Vec1;
    Studentas A;
    cout<<"Kiek studentu ivesite?: ";
    int skaicius;
    cin>>skaicius;
    for(int i=0; i<skaicius; i++){
        cout<<"Iveskite informacija: "<<endl;
        duomenuived(A);
        Vec1.push_back(A);
        valymas(A);
    }

    cout << std::setw(15) << std::left << "Pavarde"
         << std::setw(15) << std::left << "Vardas"
         << std::setw(20) << std::left << "Galutinis (Vid.)"<<endl;
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout<<endl;
    for(int i=0; i<skaicius; i++){
        spausdinimas(Vec1.at(i));
        cout<<endl;
    }
    return 0;
};

