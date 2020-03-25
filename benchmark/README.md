# benchmark
Skrypt testujący wydajność programów

## Konfiguracja
Program wykonuje testy w sposób automatyczny. Należy jednak wcześniej przygotować plik konfiguracyjny, który definiuje kolejno wykonywane testy.
Plik ten jest w formacie JSON. Poniżej znajduje się przykładowa treść takiego pliku:
```json
{
	"tests": [
		{
			"name": "Rozkład losowy",
			"size_range": {
				"start": 10000,
				"step": 10000,
				"count": 10
			},
			"repeats": 5,
			"generate_function": "random",
			"applications": [
				{ "name": "bubble", "command": "./sorter/sorter bubble benchmark" },
				{ "name": "insertion", "command": "./sorter/sorter insertion benchmark" },
				{ "name": "selection", "command": "./sorter/sorter selection benchmark" },
				{ "name": "shell", "command": "./sorter/sorter shell benchmark" }
			]
		},
		{
			"name": "Rozkład stały",
			"size_range": {
				"start": 100000,
				"step": 100000,
				"count": 10
			},
			"repeats": 10,
			"generate_function": "costant",
			"applications": [
				{ "name": "bubble", "command": "./sorter/sorter bubble benchmark" },
				{ "name": "selection", "command": "./sorter/sorter selection benchmark" },
			]
		}
	]
}
```

Pole "tests" jest tablicą obiektów, które definiują poszczególne testy. Testy są wykonywane w takiej kolejności, jaka została zdefiniowana w tej tablicy.
Każdy obiekt posiada taki sam zestaw pól (na chwilę obecną nie ma żadnych dodatkowych pól, które byłyby opcjonalne):
	- name - zawiera nazwę aktualnie wykonywanego testu; istotne, aby ta nazwa była **unikalna**
	- size_range - zawiera obiekt, który definiuje wielkości danych, na jakich bedą wykonywane testy (rosną one liniowo). Pole "start" określa wartość początkową, pole "step" określa przyrost przy każdej kolejnej wielkości danych, a pole "count" liczbę różnych wielkości danych. Na przykładzie pokazanym powyżej, w teście "Rozkład losowy" programy będą testowane na danych o rozmiarach, kolejno: 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 10000.
	- repeats - określa ile razy zostanie powtórzony taki sam test, dla tego samego programu i dla takiej samej wielkości danych. Większa liczba pozwala zminimalizować wpływ czynników losowych na wyniki testów (wyniki poszczególnych powtórzeń mogą zostać uśrednione), ale wydłuża znacznie czas wykonywania testów.
	- generate_function - określa funkcję, która generuje dane o zadanej wielkości. Na chwilę obecną dostępne są: random, constant, ascending, descending, a-shape
	- applications - tablica zawierająca obiekty, które definiują programy poddawane testowi. Pole name określa nazwę, która pojawi się w wynikach i będzie identyfikowała program. Pole command natomiast definiuje komendę, którą skrypt *benchmark* będzie wykonywał w celu przetestowania programu.

## Obsługa
Po przygotowaniu pliku konfiguracyjnego można przystąpić do uruchomienia testów. Należy uzbroić się w cierpliwość, gdyż w zależności od ilości testów, rozmiaru danych, dobranych algorytmów itd. może to potrwać długo lub bardzo długo.

Skrypt przyjmuje dwa argumenty:
 - ścieżka do pliku z konfiguracją
 - ścieżka do pliku, w którym będą zapisywane wyniki

Program na bieżąco informuje, który test jest aktualnie wykonywany. Wyniki są również na bieżąco zapisywane do pliku, by zminimalizować straty spowodowane jakimś błędem.

Przykład
```bash
$ ./benchmark.py config.json results.json
```
