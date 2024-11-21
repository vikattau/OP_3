## V1.1
### Programų greičio analizė 
Programų su struc ir class palyginimas naudojant vector, 3 strategiją (studentų dalijimas patobulinus antrą strategiją (ištrinimo) remove_if funkcija) ir 100 tūksk. bei 1 mln. studentų failus.

|Studentų skaičius|Programos dalis|Naudojant struc|Naudojant class|
|---|---|---|---|
|100000|Duomenų nuskaitymas|0.135 s|0.138 s|
||Rūšiavimas|0.014 s|0.328 s|
||Dalijimas į grupes|0.005 s|0.021 s|
||Įrašymas į failus|0.191 s|0.206 s|
|1000000|Duomenų nuskaitymas|1.391 s|1.534 s|
||Rūšiavimas|0.829 s|4.49 s|
||Dalijimas į grupes|0.182 s|0.221 s|
||Įrašymas į failus|1.95 s|2.22 s|

## V1.0
### Naudojimo instrukcija   
- **CMake**: Būtina turėti įdiegtą CMake (rekomenduojama versija 3.25 ar vėlesnė);
- **Kompiliatorius**: Tam, kad galėtumėte sukompiliuoti projektą, reikia turėti C++ kompiliatorių (pvz., GCC, MSVC).
- **Windows** (jei naudojate Windows): CMake ir `run.bat` failas buvo išbandyti Windows aplinkoje.
### Projekto struktūra
- **CMakeLists.txt**: Failas, naudojamas CMake projekto konfigūracijai ir kompilavimui.
- **run.bat**: Windows `.bat` failas, skirtas paleisti programą.
### Programos diegimas ir paleidimas
- **Klonuokite** šį projektą į savo vietinį kompiuterį;
- **Paleidimas** su run.bat - atliks visus reikalingus veiksmus: sukompiliuos projektą ir paleis jį automatiškai.

### Programos veikimo greičio analizė pagal strategijas
Pirma strategija (1 str.) - studentų dalijimas studentų vektorių skirstant į du naujus vektorius - vargšiukai ir galvočiai.  
Antra strategija (2 str.) - studentų dalijimas vargšiukus studentus įkeliant į naują vektorių ir juos ištrinant iš studentai vektoriaus.  
Trečia strategija (3 str.) - studentų dalijimas patobulinus antrą strategiją remove_if funkcija.   
Strategijų lyginimas vector konteinerio atveju (laikai release versijai):
|Studentų skaičius|Programos dalis|1 str. laikas|2 str. laikas|3 str. laikas| 
|---|---|---|---|---|
|1000|Duomenų nuskaitymas|0.002 s|0.002 s|0.002 s|
||Rūšiavimas|0 s|0 s|0 s|
||Dalijimas į grupes|0 s|0 s|0 s|
||Įrašymas į failus|0.0025 s|0.0025 s|0.0025 s|
|10000|Duomenų nuskaitymas|0.018 s|0.015 s|0.015 s|
||Rūšiavimas|0.02 s|0.002 s|0.02 s|
||Dalijimas į grupes|0.001 s|0.001 s|0 s|
||Įrašymas į failus|0.019 s|0.019 s|0.02 s|
|100000|Duomenų nuskaitymas|0.14 s|0.135 s|0.135 s|
||Rūšiavimas|0.031 s|0.036 s|0.014 s|
||Dalijimas į grupes|0.014 s|0.025 s|0.005 s|
||Įrašymas į failus|0.189 s|0.192 s|0.191 s|
|1000000|Duomenų nuskaitymas|1.361 s|1.362 s|1.391 s|
||Rūšiavimas|0.782 s|0.823 s|0.829 s|
||Dalijimas į grupes|0.25 s|0.367 s|0.182 s|
||Įrašymas į failus|2.06 s|1.98 s|1.95s|
|10000000|Duomenų nuskaitymas|14.765 s|14.129 s|19.632 s|
||Rūšiavimas|9.25 s|9.19 s|9.23 s|
||Dalijimas į grupes|2.833 s|5.781 s|1.672 s|
||Įrašymas į failus|19.43 s|19.22 s|19.17 s|

Strategijų lyginimas list konteinerio atveju (laikai release versijai):  
|Studentų skaičius|Programos dalis|1 str. laikas|2 str. laikas|3 str. laikas| 
|---|---|---|---|---|
|1000|Duomenų nuskaitymas|0.003 s|0.002 s|0.002 s|
||Rūšiavimas|0 s|0 s|0 s|
||Dalijimas į grupes|0 s|0 s|0 s|
||Įrašymas į failus|0.0025 s|0.002 s|0.002 s|
|10000|Duomenų nuskaitymas|0.016 s|0.014 s|0.015 s|
||Rūšiavimas|0.001 s|0.002 s|0.002 s|
||Dalijimas į grupes|0.001 s|0.001 s|0 s|
||Įrašymas į failus|0.019 s|0.021 s|0.021 s|
|100000|Duomenų nuskaitymas|0.139 s|0.138 s|0.141 s|
||Rūšiavimas|0.034 s|0.035 s|0.036 s|
||Dalijimas į grupes|0.031 s|0.043 s|0.025 s|
||Įrašymas į failus|0.188 s|0.201 s|0.192 s|
|1000000|Duomenų nuskaitymas|1.383 s|1.385 s|1.381 s|
||Rūšiavimas|0.754 s|0.887 s|0.724 s|
||Dalijimas į grupes|0.395 s|0.885 s|0.365 s|
||Įrašymas į failus|1.897 s|2.067 s|2.031 s|
|10000000|Duomenų nuskaitymas|13.82 s|13.91 s|14.21 s|
||Rūšiavimas|9.89 s|9.92 s|9.44 s|
||Dalijimas į grupes|3.753 s|9.891 s|2.981 s|
||Įrašymas į failus|18.96 s|19.52 s|19.63 s|

Pirmos strategijos testavimo pavyzdys su 10mln. studentų ir vector
![Ekrano kopija 2024-10-24 151940](https://github.com/user-attachments/assets/ccceb00c-f698-400a-8019-e89f4a9ecf81)

Pirmos strategijos testavimo pavyzdys su 10mln. studentų ir list
![Ekrano kopija 2024-10-24 152750](https://github.com/user-attachments/assets/6cd457b2-49de-4b9d-b2a6-3c980a3476ae)

Antros strategijos testavimo pavyzdys su 10mln. studentų ir vector
![image](https://github.com/user-attachments/assets/4d2c50c9-d9f6-4c82-b47a-2a0d0a23ad6f)

Antros strategijos testavimo pavyzdys su 10mln. studentų ir list
![image](https://github.com/user-attachments/assets/db3ab4f9-42aa-4e9a-bf8e-dc14b85234f6)

Trečios strategijos testavimo pavyzdys su 10mln. studentų ir vector
![image](https://github.com/user-attachments/assets/6453a656-e55b-4dcd-81d3-0bf80a8f7a9a)

Trečios strategijos testavimo pavyzdys su 10mln. studentų ir list
![image](https://github.com/user-attachments/assets/e22a411d-bf8a-4763-bbec-a38c56192584)


## V0.3
### Programos veikimo greičio analizė list ir vector atvejais
Testavimo sistemos parametrai:  
-CPU: Intel(R) Core(TM) i5-10500H CPU @ 2.50GHz  
-RAM: 8 GB  
-SSD: 256 GB Kingston NVMe SSD (OM8PDP3256B-AI1)  

Su 1000 studentų:
|Programos dalis|Laikas su vector|Laikas su list|
|---|---|---|
|Duomenų nuskaitymas|0.002 s|0.003 s|
|Rūšiavimas|0.001 s|0.001 s|
|Dalijimas į grupes|0 s|0 s|
|Įrašymas į failus|0.0025 s|0.0025 s|

Su 10000 studentų:
|Programos dalis|Laikas su vector|Laikas su list|
|---|---|---|
|Duomenų nuskaitymas|0.021 s|0.02 s|
|Rūšiavimas|0.023 s|0.018 s|
|Dalijimas į grupes|0.004 s|0.003 s|
|Įrašymas į failus|0.024 s|0.024 s|

Su 100000 studentų:
|Programos dalis|Laikas su vector|Laikas su list|
|---|---|---|
|Duomenų nuskaitymas|0.19 s|0.201 s|
|Rūšiavimas|0.31 s|0.239 s|
|Dalijimas į grupes|0.035 s|0.049 s|
|Įrašymas į failus|0.228 s|0.235 s|

Su 1000000 studentų:
|Programos dalis|Laikas su vector|Laikas su list|
|---|---|---|
|Duomenų nuskaitymas|1.942 s|1.931 s|
|Rūšiavimas|4.263 s|3.554 s|
|Dalijimas į grupes|0.526 s|0.511 s|
|Įrašymas į failus|2.324 s|2.297 s|

Su 10000000 studentų:
|Programos dalis|Laikas su vector|Laikas su list|
|---|---|---|
|Duomenų nuskaitymas|19.765 s|21.641 s|
|Rūšiavimas|52.95 s|48.23 s|
|Dalijimas į grupes|4.573 s|6.707 s|
|Įrašymas į failus|23.382 s|27.962 s|

Testavimo pavyzdys su 10mln. studentų ir vector
![Ekrano kopija 2024-10-24 151940](https://github.com/user-attachments/assets/ccceb00c-f698-400a-8019-e89f4a9ecf81)

Testavimo pavyzdys su 10mln. studentų ir list
![Ekrano kopija 2024-10-24 152750](https://github.com/user-attachments/assets/6cd457b2-49de-4b9d-b2a6-3c980a3476ae)

## V0.2
Patobulinta programa dabar:
1. generuoja pasirinkto dydžio (1000, 10000, 100000, 1000000, 10000000) atsitiktinius studentų failus
2. padalija studentus į dvi grupes (vargšiukus ir galvočius) pagal galutinį balą.
3. surūšiuotus studentus išveda į failus.
### Programos veikimo greičio analizė
- Failas su 1000 studentų vidutiniškai sukuriamas per 0.0042s, nuskaitomas per 0.003s, studentai į grupes suskirstomi per 0.00s, surūšiuoti studentai išvedami į failus vidutiniškai per 0.0025s. 
- Failas su 10000 studentų vidutiniškai sukuriamas per 0.0352s, nuskaitomas per 0.019s, studentai į grupes suskirstomi per 0.003s, surūšiuoti studentai išvedami į failus vidutiniškai per 0.0235s. 
- Failas su 100000 studentų vidutiniškai sukuriamas per 0.3372s, nuskaitomas per 0.198s, studentai į grupes suskirstomi per 0.032s, surūšiuoti studentai išvedami į failus vidutiniškai per 0.2232s. 
- Failas su 1000000 studentų vidutiniškai sukuriamas per 3.3104s, nuskaitomas per 1.875s, studentai į grupes suskirstomi per 0.385s, surūšiuoti studentai išvedami į failus vidutiniškai per 2.2315s.
- Failas su 10000000 studentų vidutiniškai sukuriamas per 34.7842s, nuskaitomas per 19.856s, studentai į grupes suskirstomi per 4.041s, surūšiuoti studentai išvedami į failus vidutiniškai per 20.453s.

## V0.1
Parašyta programa, kuri:
1. nuskaito iš failų arba leidžia įvesti studentų duomenis (vardą, pavardę, namų darbų rezultatus, egzamino įvertinimą);
2. iš gautų duomenų suskaičiuoja galutinį balą pagal n.d. vidurkį ir medianą;
3. leidžia pažymius generuoti automatiškai;
4. atspausdina išrūšiuotą "lentelę" su studentų duomenimis



