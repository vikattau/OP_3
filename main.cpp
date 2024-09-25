#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

struct Studentas{
    string vardas, pavarde;
    vector<int> NamuDarbai;
    int egz;
};
void atsitiktiniuBaluGeneravimas(Studentas &Lok){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    int NDskaicius = 5;
    for (int i=0; i < NDskaicius; i++){
        Lok.NamuDarbai.push_back(dist(mt));
    }
    Lok.egz = dist(mt);
}
void duomenuived(Studentas &Lok){
    cout<<"Iveskite Varda, Pavarde: ";
    cin>>Lok.vardas>>Lok.pavarde;
    cout<<"Ar norite, kad pazymiai butu generuojami automatiskai? Jeigu Taip iveskite T, jeigu Ne - N: ";
    string ats;
    cin>> ats;
    if (ats == "T" || ats == "t"){
        atsitiktiniuBaluGeneravimas(Lok);
    } else if (ats == "N" || ats == "n"){
        cout<<"Iveskite egzamino rezultata: ";
        cin>> Lok.egz;
        cout<<"Iveskite Namu Darbu pazymius (noredami uzbaigti ivedima iveskite 0): \n";
        int x;
        while(true){
            cout<<"Pazymys: ";
            cin>> x;
            if (x == 0) break;
            Lok.NamuDarbai.push_back(x);
        }
    }
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
double medianosSkaic(vector<int> pazymiai){
    std::sort(pazymiai.begin(), pazymiai.end());
    int kiekis = pazymiai.size();
    if (kiekis % 2 == 0){
        return (pazymiai[kiekis / 2 - 1] + pazymiai[kiekis / 2]) / 2.0;
    } else {
        return pazymiai[kiekis /2];
    }
}
double skaicGalutiniBalaVidur(const Studentas &studentas){
    double vidutinisND = vidurkioSkaic(studentas.NamuDarbai);
    return (vidutinisND * 0.4) + (studentas.egz * 0.6);
};
double skaicGalutiniBalaMed(const Studentas &studentas){
    double medianaND = medianosSkaic(studentas.NamuDarbai);
    return (medianaND * 0.4) + (studentas.egz * 0.6);
}
void skaitytiFaila(vector<Studentas> &studentai, const string & failoPavadinimas){
    std::ifstream failas(failoPavadinimas);
    if (!failas) {
        cout<< "Nepavyko nuskaityti failo"<<endl;
        return;
    }
    string failoEilute;
    std::getline(failas, failoEilute);
    while(std::getline(failas, failoEilute)){
        std::istringstream iss(failoEilute);
        Studentas stud;
        iss >> std::ws >> stud.vardas >> std::ws >>stud.pavarde;

        int pazymys;
        while(iss >> pazymys){
            stud.NamuDarbai.push_back(pazymys);
        }
        if (!stud.NamuDarbai.empty()) {
            stud.egz = stud.NamuDarbai.back();
            stud.NamuDarbai.pop_back();
        } else {
            cout << "Nera pazymiu studentui: " << stud.vardas << " " << stud.pavarde << endl;
            continue;
        }

        studentai.push_back(stud);
    }
}
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud){
    return Lok.pavarde < stud.pavarde;
};
void spausdinimas(const Studentas &Lok){
    cout<< std::setw(15) << std::left << Lok.pavarde
        << std::setw(15) << std::left << Lok.vardas
        << std::setw(20) << std::left << std::fixed << std::setprecision(2) << skaicGalutiniBalaVidur(Lok)
        << std::setw(20) << std::left << std::fixed << std::setprecision(2) << skaicGalutiniBalaMed(Lok) << endl;
};
int main()
{
    vector<Studentas> Vec1;
    Studentas A;
    cout<< "Duomenis apie studentus nuskaitysite ar ivesite ranka? Iveskite 1, jei nuskaitysite nuo failo, 0, jei ivesite ranka: "<<endl;
    int ats;
    cin>>ats;
    if(ats == 1){
        cout<< "Kuri faila norite nuskaityti? (Pasirinkite skaiciu): \n"<<
            "1 - kursiokai.txt \n"<<
            "2 - studentai10000.txt \n"<<
            "3 - studentai100000.txt \n"<<
            "4 - studentai1000000.txt \n"<<endl;
        int failas;
        cin>>failas;
        if (failas == 1){
            skaitytiFaila(Vec1, "kursiokai.txt");
        }else if (failas == 2){
            skaitytiFaila(Vec1, "C:\\Users\\MSI\\Desktop\\OP\\failas\\studentai10000.txt");
        }else if (failas == 3){
            skaitytiFaila(Vec1,"C:\\Users\\MSI\\Desktop\\OP\\failas\\studentai100000.txt");
        }else if (failas == 4) {
            skaitytiFaila(Vec1, "C:\\Users\\MSI\\Desktop\\OP\\failas\\studentai1000000.txt");
        }else{
            cout << "Tokio failo nera" << endl;
        }
    }else if (ats == 0){
        cout<<"Kiek studentu ivesite?: ";
        int skaicius;
        cin>>skaicius;
        for(int i=0; i<skaicius; i++){
            cout<<"Iveskite informacija: "<<endl;
            duomenuived(A);
            Vec1.push_back(A);
            valymas(A);
        }
    }
    std::sort(Vec1.begin(), Vec1.end(), rusiavimasPavarde);

    cout << std::setw(15) << std::left << "Pavarde"
         << std::setw(15) << std::left << "Vardas"
         << std::setw(20) << std::left << "Galutinis (Vid.)"
         << std::setw(20) << std::left << "Galutinis (Med.)" << endl;

    cout << string(70, '-') << endl;

    for(int i=0; i<Vec1.size(); i++){
        spausdinimas(Vec1.at(i));
        cout<<endl;
    }
    system("pause");
    return 0;
};

