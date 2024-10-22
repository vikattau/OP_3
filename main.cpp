#include "Mylib.h"
#include "Stud.h"
#include "templates.h"


int main(){
    cout<< "Noresite generuoti studentu failus, duomenis apie studentus nuskaityti is failo ar ivesti duomenis ranka? \n" <<
        "3 - jei norite atlikti programos veikimo greicio analize, \n" <<
        "2 - jei norite generuoti failus su studentu duomenimis, \n" <<
        "1 - jei norite nuskaityti nuo failo, \n" <<
        "0 - jei duomenis ivesite ranka: \n"<< endl;
    int ats;
    while(!(cin >> ats) || (ats != 1 && ats != 0 && ats != 2 && ats != 3)){
        cout << "Netinkama ivestis. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Kuri konteineri norite naudoti? \n"
        << "1 - vector\n"
        << "2 - list\n";
    int konteineris;
    while(!(cin >> konteineris) || (konteineris != 1 && konteineris != 2)){
        cout << "Netinkama ivestis. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (konteineris == 1){
        vector<Studentas> Vec1;
        programosPasirinkimas(ats, Vec1);
    } else if (konteineris == 2){
        list<Studentas> List1;
        programosPasirinkimas(ats, List1);
    }
    system("pause");
    return 0;
};

