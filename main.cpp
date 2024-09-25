#include "Mylib.h"
#include "Stud.h"

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

    for (const auto& stud : Vec1){
        spausdinimas(stud);
    }
    system("pause");
    return 0;
};

