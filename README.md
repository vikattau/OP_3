## V0.1
Parašyta programa, kuri:
1. nuskaito iš failų arba leidžia įvesti studentų duomenis (vardą, pavardę, namų darbų rezultatus, egzamino įvertinimą);
2. iš gautų duomenų suskaičiuoja galutinį balą pagal n.d. vidurkį ir medianą;
3. leidžia pažymius generuoti automatiškai;
4. atspausdina išrūšiuotą "lentelę" su studentų duomenimis

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

