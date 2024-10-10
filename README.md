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
Failas su 1000 studentų vidutiniškai nuskaitomas per 0,0072s, studentai į grupes suskirstomi per 0s, surūšiuoti studentai išvedami į failus vidutiniškai per 0,0021s. 
Failas su 10000 studentų vidutiniškai nuskaitomas per 0,0584s, studentai į grupes suskirstomi per 0,0018s, surūšiuoti studentai išvedami į failus vidutiniškai per 0,0203s. 
Failas su 100000 studentų vidutiniškai nuskaitomas per 0,572s, studentai į grupes suskirstomi per 0,0204s, surūšiuoti studentai išvedami į failus vidutiniškai per 0,1974s. 
Failas su 1000000 studentų vidutiniškai nuskaitomas per 5,7032s, studentai į grupes suskirstomi per 0,209s, surūšiuoti studentai išvedami į failus vidutiniškai per 1,9315s.
Failas su 10000000 studentų vidutiniškai nuskaitomas per 57,5432s, studentai į grupes suskirstomi per 2,041s, surūšiuoti studentai išvedami į failus vidutiniškai per 19,5254s.

