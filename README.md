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



