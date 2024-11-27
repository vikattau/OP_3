#include "Stud.h"
ifstream& operator>>(ifstream& in, Studentas& studentas) {
    std::string line;
    std::getline(in, line);
    if (line.empty()) return in;

    std::stringstream ss(line);
    ss >> studentas.vardas_ >> studentas.pavarde_;

    studentas.nd_.resize(5);
    for (int& grade : studentas.nd_) {
        ss >> grade;
    }

    ss >> studentas.egzaminas_;
    studentas.galutinisBalasVidur = skaicGalutiniBalaVidur(studentas);
    studentas.galutinisBalasMed = skaicGalutiniBalaMed(studentas);

    return in;
}

istream& operator>>(istream& in, Studentas& studentas){
    cout << "Iveskite Varda: ";
    in >> studentas.vardas_;
    cout << "Iveskite Pavarde: ";
    in >> studentas.pavarde_;

    while (true){
    cout << "Ar norite, kad pazymiai butu generuojami automatiskai? Jeigu Taip iveskite T, jeigu Ne - N: ";
    string ats;
    in >> ats;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    if (ats == "T" || ats == "t") {
        studentas.atsitiktiniuBaluGeneravimas();
        break;
    } else if (ats == "N" || ats == "n") {
        cout << "Iveskite egzamino rezultata (0 - 10): ";
        while (!(in >> studentas.egzaminas_) || studentas.egzaminas_ < 0 || studentas.egzaminas_ > 10) {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisingai ivedete, bandykite dar karta: ";
        }
        cout << "Iveskite Namu Darbu pazymius 1 - 10 (noredami uzbaigti ivedima iveskite 0): \n";
        studentas.nd_.clear();
        int x;
        bool ivestasPazymys = false;
        while (true) {
            cout << "Pazymys: ";
            while (!(in >> x) || x < 0 || x > 10) {
                    in.clear();
                    in.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Neteisingai ivedete, bandykite dar karta: ";
            }

            if (x == 0) {
                if (!ivestasPazymys) {
                cout << "Turite ivesti bent viena pazymi. \n";
                    continue;
                }
                break;
            }
            studentas.nd_.push_back(x);
            ivestasPazymys = true;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    } else {
        cout << "Neteisingai ivedete. Prasome iveskite T arba N." << endl;
    }
    }
    studentas.galutinisBalasVidur = skaicGalutiniBalaVidur(studentas);
    studentas.galutinisBalasMed = skaicGalutiniBalaMed(studentas);

    return in;
}
std::ostream& operator<<(std::ostream& out, const Studentas& studentas){
    out << setw(15) << left << studentas.pavarde_
        << setw(15) << left << studentas.vardas_
        << setw(20) << left << fixed << setprecision(2)
        << studentas.galutinisBalasVidur
        << setw(20) << left << fixed << setprecision(2)
        << studentas.galutinisBalasMed;

        return out;
}
void Studentas::valymas(){
    vardas_.clear();
    pavarde_.clear();
    nd_.clear();
    egzaminas_ = 0;
};

double skaicGalutiniBalaVidur(const Studentas &studentas){
    double vidutinisND = 0.0;
    for (int grade : studentas.getNd()) {
        vidutinisND += grade;
    }
    vidutinisND /= studentas.getNd().size();
    return (vidutinisND * 0.4) + (studentas.getEgz() * 0.6);
}
double skaicGalutiniBalaMed(const Studentas &studentas){
    if (studentas.getNd().empty()) return 0.0;

    vector<int> sortedNd = studentas.getNd();
    sort(sortedNd.begin(), sortedNd.end());

    size_t size = sortedNd.size();
    double medianaNd;
    if (size % 2 == 0) {
        medianaNd = (sortedNd[size / 2 - 1] + sortedNd[size / 2]) / 2.0;
    } else {
        medianaNd = sortedNd[size / 2];
    }

    return (medianaNd * 0.4) + (studentas.getEgz() * 0.6);
}
void Studentas::atsitiktiniuBaluGeneravimas() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    int NDskaicius = 5;
    for (int i=0; i < NDskaicius; i++){
        nd_.push_back(dist(mt));
    }
    egzaminas_ = dist(mt);
};
void generuotiStudentus (int studentuSkaicius, const string &failoPav){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    auto start = high_resolution_clock::now();

    ofstream failas(failoPav);
    if (!failas){
        cerr << "Nepavyko atidaryti failo " << failoPav << endl;
        return;
    }
    failas << setw(20) << left << "Vardas"
           << setw(20) << left << "Pavarde";
    for (int i = 1; i <= 5; ++i) {
        failas << setw(10) << left << "ND" + to_string(i);
    }
    failas << setw(10) << left << "Egz." << endl;

    for (int i = 0; i < studentuSkaicius; i++) {
        string pavarde = "Pavarde" + to_string(i);
        string vardas = "Vardas" + to_string(i);

        failas << setw(20) << left << vardas
               << setw(20) << left << pavarde;
        for (int j=0; j<5; j++){
            failas << setw(10) << left << dist(mt);
        }
        failas << setw(10) << left << dist(mt) << endl;
    }
    failas.close();
    auto end = high_resolution_clock::now();
    duration<double> laikas = end - start;
    cout << "Sukurtas failas: " << failoPav << " su " << studentuSkaicius << " studentais. "
        << "Uztruko: " << laikas.count() << " sekundes." << endl;
}
bool rusiavimasPavarde(const Studentas &Lok, const Studentas &stud){
    return Lok.getPavarde() < stud.getPavarde();
};

void VectorstudentuSkaidymas(vector<Studentas>& studentai, vector<Studentas>& vargsiukai){
    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](const Studentas& s) {
        if (skaicGalutiniBalaVidur(s) < 5.0) {
            vargsiukai.push_back(s);
            return true;
        }
            return false;
        });
    studentai.erase(it, studentai.end());
}
void ListStudentuSkaidymas(list<Studentas> & studentai, list<Studentas>& vargsiukai){
    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](const Studentas& s) {
        if (skaicGalutiniBalaVidur(s) < 5.0) {
            vargsiukai.push_back(s);
            return true;
        }
            return false;
        });
    studentai.erase(it, studentai.end());
}
void pademonstruotiTrysMetodus() {
    Studentas studentas1("Jonas", "Jonaitis", {8, 7, 10}, 9.0);
    std::cout << "Studentas1: " << studentas1.getVardas() << " " << studentas1.getPavarde() << ", egzamino pazymys: " << studentas1.getEgz() << std::endl;

    cout << "Studentas2 sukuriamas kopijuojant studentas1" << endl;
    Studentas studentas2 = studentas1;
    std::cout << "Studentas2 (kopija): " << studentas2.getVardas() << " " << studentas2.getPavarde() << ", egzamino pazymys: " << studentas2.getEgz() << std::endl;

    cout << "Studentui3 priskiriamas studentas1" << endl;
    Studentas studentas3("Petras", "Petraitis", {7, 6, 8}, 8.0);
    std::cout << "Studentas3 (pries priskyrima): " << studentas3.getVardas() << " " << studentas3.getPavarde() << ", egzamino pazymys: " << studentas3.getEgz() << std::endl;
    studentas3 = studentas1;
    std::cout << "Studentas3 (po priskyrimo): " << studentas3.getVardas() << " " << studentas3.getPavarde() << ", egzamino pazymys: " << studentas3.getEgz() << std::endl;

    {
        Studentas studentas4("Ona", "Onaite", {10, 9, 10}, 8.0);
        std::cout << "Studentas4 sukurtas" << std::endl;
        std::cout << "Studentas4 : " << studentas4.getVardas() << " " << studentas4.getPavarde() << ", egzamino pazymys: " << studentas4.getEgz() << std::endl;
    }
    cout << "Studentas 4 sunaikintas"  << std::endl;
}
