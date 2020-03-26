# sorter
Program sortujący dane przy pomocy wybranego algorytmu sortowania. Zaimplementowano kilka popularniejszych algorytmów:

 - bubble sort,
 - selection sort,
 - insertion sort,
 - merge sort,
 - quick sort (w wersji obierającej skrajnie prawy element na pivot)
 - quick sort (w wersji obierającej losowy element na pivot)
 - heap sort
 - shell sort
 - counting sort

## Kompilacja
Aby skompilować program należy wykonać polecenie make

```bash
$ make
```

Po kompilacji program będzie dostępny jako plik o nazwie **sorter**

## Obsługa
Uruchamiając program, trzeba podać nazwę algorytmu sortującego jako argument (lista odpowiednich nazw-identyfikatorów będzie dostępna, gdy uruchomimy program bez podawania jakiegokolwiek argumentu).

Następnie na wejście należy podać ciąg liczb całkowitych, rozdzielonych białymi znakami. Ciąg ten terminowany jest przez EOF - można więc po prostu dane umieścić w pliku i przekierować na jako standardowe wejście. Posortowane liczby zostaną wypisane na standardowe wyjście.

Przykład:
```bash
$ ./sorter quick-rand < input.txt > output.txt
```

Istnieje jeszcze jeden, opcjonalny argument **benchmark**. Należy go podać, kiedy nie chcemy, aby program wypisał posortowane dane na wyjście (mogłoby to wpłynąć negatywnie na wynik benchmarku).

```bash
$ ./sorter heap benchmark < input.txt > output.txt
```
