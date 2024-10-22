#ifndef TEMPLATES_H_INCLUDED
#define TEMPLATES_H_INCLUDED
#include "Mylib.h"
#include "Stud.h"

template <typename Container>
void programosPasirinkimas(int ats, Container &studentai){
    try {
    if (ats == 1){
        cout<< "Kuri faila norite nuskaityti? (Pasirinkite skaiciu): \n"<<
                "1 - kursiokai.txt \n"<<
                "2 - studentai10000.txt \n"<<
                "3 - studentai100000.txt \n"<<
                "4 - studentai1000000.txt \n"<<endl;
            int failas;
            cin >> failas;
            string filename;
            switch (failas) {
                case 1: filename = "kursiokai.txt"; break;
                case 2: filename = "studentai10000.txt"; break;
                case 3: filename = "studentai100000.txt"; break;
                case 4: filename = "studentai1000000.txt"; break;
                default: cout << "Tokio failo nera" << endl; return;
            }
            skaitytiFaila(studentai, filename);
            if constexpr (is_same<Container, vector<Studentas>>::value) {
                sort(studentai.begin(), studentai.end(), rusiavimasPavarde);
            } else if constexpr (is_same<Container, list<Studentas>>::value) {
                studentai.sort(rusiavimasPavarde);
            }
            spausdinimas(studentai);
    }else if (ats == 0){
            cout<<"Kiek studentu ivesite?: ";
            int skaicius;
            while (!(cin >> skaicius) || skaicius <= 0){
                cout << "Netinkama ivesti, bandykite dar karta: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();
            for(int i=0; i<skaicius; i++){
                cout<<"Iveskite informacija: "<<endl;
                Studentas A;
                duomenuived(A);
                studentai.push_back(A);
                cout << "Studento objektas saugomas adresu: " << &studentai.back() << endl;
                valymas(A);
            }
            if constexpr (is_same<Container, vector<Studentas>>::value) {
                sort(studentai.begin(), studentai.end(), rusiavimasPavarde);
            } else if constexpr (is_same<Container, list<Studentas>>::value) {
                studentai.sort(rusiavimasPavarde);
            }
            spausdinimas(studentai);

    }else if (ats == 2){
            cout << "Kiek studentu norite sugeneruoti? (iveskite atitinkama skaiciu): \n" <<
                "1 - 1000 studentu \n" <<
                "2 - 10000 studentu \n" <<
                "3 - 100000 studentu \n" <<
                "4 - 1000000 studentu \n" <<
                "5 - 10000000 studentu \n" << endl;
            int skaicius;
            while(!(cin >> skaicius) || (skaicius != 1 && skaicius != 2 && skaicius != 3 && skaicius != 4 && skaicius != 5)){
                cout << "Netinkama ivestis. Bandykite dar karta: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            string failoPav;
            if (skaicius == 1){
                failoPav = "studentai_1000.txt";
                generuotiStudentus(1000, failoPav);
            }else if (skaicius == 2){
                failoPav = "studentai_10000.txt";
                generuotiStudentus(10000, failoPav);
            }else if (skaicius == 3){
                failoPav = "studentai_100000.txt";
                generuotiStudentus(100000, "studentai_100000.txt");
            }else if (skaicius == 4) {
                failoPav = "studentai_1000000.txt";
                generuotiStudentus(1000000, failoPav);
            }else if (skaicius == 5) {
                failoPav = "studentai_10000000.txt";
                generuotiStudentus(10000000, failoPav);
            }else{
                cout << "Klaida" << endl;
            }
        }else if (ats == 3){
            cout << "Kaip norite rusiuoti studentus?: \n"
                << "1 - pagal pavardes \n"
                << "2 - pagal galutini bala mazejancia tvarka \n"
                << "3 - pagal galutini bala didejancia tvarka \n" << endl;
            int rusiavimoPasirinkimas;
            cin >> rusiavimoPasirinkimas;

            vector<string> testuojamiFailai = {
            "studentai_1000.txt",
            "studentai_10000.txt",
            "studentai_100000.txt",
            "studentai_1000000.txt",
            "studentai_10000000.txt"
            };
            for (const auto& failoPav : testuojamiFailai) {
                cout << "Testuojamas failas: " << failoPav << endl;
//                failuTestavimas(failoPav, Vec1, rusiavimoPasirinkimas);
            }
        }
    } catch (const std::runtime_error &e){
        cout << "Klaida: " << e.what() << endl;
    } catch (...){
        cout << "Ivyko nezinoma klaida." << endl;
    }
}

template <typename Container>
void spausdinimas(const Container &stud){
    cout << std::setw(15) << std::left << "Pavarde"
         << std::setw(15) << std::left << "Vardas"
         << std::setw(20) << std::left << "Galutinis (Vid.)"
         << std::setw(20) << std::left << "Galutinis (Med.)" << endl;

    cout << string(70, '-') << endl;

    for (const auto& Lok : stud){
        cout<< std::setw(15) << std::left << Lok.pavarde
        << std::setw(15) << std::left << Lok.vardas
        << std::setw(20) << std::left << std::fixed << std::setprecision(2) << skaicGalutiniBalaVidur(Lok)
        << std::setw(20) << std::left << std::fixed << std::setprecision(2) << skaicGalutiniBalaMed(Lok) << endl;
    }

};

template <typename Container>
void skaitytiFaila(Container &studentai, const string & failoPavadinimas){
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

        iss >> stud.vardas >>stud.pavarde;

        if (iss.fail()){
            cout << "Nepavyko teisingai nuskaityti studento vardo ir pavardes." << endl;
            continue;
        }

        int pazymys;
        while(iss >> pazymys){
            if (pazymys < 0 || pazymys > 10) {
                cout << "Faile neteisingas pazymys studentui: " << stud.vardas << " " << stud.pavarde <<endl;
                continue;
            }
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
    if (studentai.empty()){
        cout << "Ivyko klaida: Nebuvo galima nuskaityti jokiu studentu is failo" << endl;
    }
};






#endif // TEMPLATES_H_INCLUDED
