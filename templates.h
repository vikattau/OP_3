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

    } else if (ats == 3){
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

        if constexpr (is_same<Container, vector<Studentas>>::value) {
            for (const auto& failoPav : testuojamiFailai) {
                cout << "Testuojamas failas: " << failoPav << endl;
                failuTestavimas(failoPav, studentai, rusiavimoPasirinkimas);
            }
        } else if constexpr (is_same<Container, list<Studentas>>::value) {
            for (const auto& failoPav : testuojamiFailai) {
                cout << "Testuojamas failas: " << failoPav << endl;
                failuTestavimas(failoPav, studentai, rusiavimoPasirinkimas);
            }
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

template <typename Container>
void failuTestavimas(string failoPav, Container& stud, int rusiavimoPasirinkimas) {
    stud.clear();
    auto start = high_resolution_clock::now();
    skaitytiFaila(stud, failoPav);
    auto end = high_resolution_clock::now();
    auto failoSkaitymas = duration_cast<milliseconds>(end - start).count();
    cout << "Failo is " << stud.size() << " irasu nuskaitymo laikas: " << fixed << setprecision(6) << failoSkaitymas / 1000.0 << " s" << endl;

    start = high_resolution_clock::now();
    if (rusiavimoPasirinkimas == 1){
        if constexpr (std::is_same<Container, std::vector<Studentas>>::value) {
            std::sort(stud.begin(), stud.end(), rusiavimasPavarde);
        } else if constexpr (std::is_same<Container, std::list<Studentas>>::value) {
            stud.sort(rusiavimasPavarde);
        }
    } else if (rusiavimoPasirinkimas == 2) {
         if constexpr (std::is_same<Container, std::vector<Studentas>>::value) {
            std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
                return skaicGalutiniBalaVidur(a) > skaicGalutiniBalaVidur(b);
            });
        } else if constexpr (std::is_same<Container, std::list<Studentas>>::value) {
            stud.sort([](const Studentas& a, const Studentas& b) {
                return skaicGalutiniBalaVidur(a) > skaicGalutiniBalaVidur(b);
            });
        }
    } else {
        if constexpr (std::is_same<Container, std::vector<Studentas>>::value) {
            std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
                return skaicGalutiniBalaVidur(a) < skaicGalutiniBalaVidur(b);
            });
        } else if constexpr (std::is_same<Container, std::list<Studentas>>::value) {
            stud.sort([](const Studentas& a, const Studentas& b) {
                return skaicGalutiniBalaVidur(a) < skaicGalutiniBalaVidur(b);
            });
        }
    }

    end = high_resolution_clock::now();
    auto rusiavimoLaikas = duration_cast<milliseconds>(end - start).count();
    cout << "Rusiavimo laikas: " << fixed << setprecision(6) << rusiavimoLaikas / 1000.0 << " s" << endl;

    vector<Studentas> vargsiukai, galvociai;
    start = high_resolution_clock::now();
    studentuSkirstymas(stud, vargsiukai, galvociai);
    end = high_resolution_clock::now();
    auto skirstymoLaikas = duration_cast<milliseconds>(end - start).count();
    cout << "Dalijimo i dvi grupes laikas: " << fixed << setprecision(6) << skirstymoLaikas / 1000.0 << " s" << endl;

    string vargsiukaiFailas = failoPav + "_vargsiukai.txt";
    string galvociaiFailas = failoPav + "_galvociai.txt";

    start = high_resolution_clock::now();
    rasytiIFaila(vargsiukai, vargsiukaiFailas);
    end = high_resolution_clock::now();
    auto vfailoIsvedimoLaikas = duration_cast<milliseconds>(end - start).count();
    cout << "Irasymo i " << vargsiukaiFailas << " faila laikas: " << fixed << setprecision(6) << vfailoIsvedimoLaikas / 1000.0 << " s" << endl;

    start = high_resolution_clock::now();
    rasytiIFaila(galvociai, galvociaiFailas);
    end = high_resolution_clock::now();
    auto gfailoIsvedimoLaikas = duration_cast<milliseconds>(end - start).count();
    cout << "Irasymo i " << galvociaiFailas << " faila laikas: " << fixed << setprecision(6) << gfailoIsvedimoLaikas / 1000.0 << " s" << endl;

    auto visasLaikas = failoSkaitymas + rusiavimoLaikas + skirstymoLaikas + vfailoIsvedimoLaikas + gfailoIsvedimoLaikas;
    cout << stud.size() << " irasu testo laikas: " << fixed << setprecision(6) << visasLaikas / 1000.0 << " s" << endl << endl;
}
#endif // TEMPLATES_H_INCLUDED
