#include "Mylib.h"
#include "Stud.h"

int main()
{
    vector<Studentas> Vec1;
    Studentas A;
    cout<< "Duomenis apie studentus nuskaitysite ar ivesite ranka? \n" <<
        "Iveskite 1, jei nori nuskaityti nuo failo, 0 - jei duomenis ivesite ranka: ";
    int ats;
    while(!(cin >> ats) || (ats != 1 && ats != 0)){
        cout << "Netinkama ivestis. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    try{
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
        while (!(cin >> skaicius) || skaicius <= 0){
            cout << "Netinkama ivesti, bandykite dar karta: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin.ignore();
        for(int i=0; i<skaicius; i++){
            cout<<"Iveskite informacija: "<<endl;
            duomenuived(A);
            Vec1.push_back(A);
            valymas(A);
        }
    }
    } catch (const std::runtime_error &e){
        cout << "Klaida: " << e.what() << endl;
    } catch (...){
        cout << "Ivyko nezinoma klaida." << endl;
    }

    std::sort(Vec1.begin(), Vec1.end(), rusiavimasPavarde);

    cout << std::setw(15) << std::left << "Pavarde"
         << std::setw(15) << std::left << "Vardas"
         << std::setw(20) << std::left << "Galutinis (Vid.)"
         << std::setw(20) << std::left << "Galutinis (Med.)" << endl;

    cout << string(70, '-') << endl;

    for (const auto& stud : Vec1){
        spausdinimas(stud);
    }
    system("pause");
    return 0;
};

