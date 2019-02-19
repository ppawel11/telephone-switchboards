# telephone-switchboards

System centrali telefonicznych zaimplementowałem za pomocą grafu, którego węzłami są pojedyńcze centrale. Jest to graf spójny - nie ma możliwości utworzenia centrali, nie połączonej z żadną inną (oprócz momentu tworzenia pierwszej centrali).

Przesyłanie wiadomości pomiędzy klientami odbywa się za pomocą tworzenia wskaźników na wysyłaną wiadomość kolejno przez odpowiednie centrale. Odbywa się to poprzez rekurencyjne wykonywanie metody passMsg().

Klient ma możliwość przesłania dwóch rodzajów wiadomości:\
- standardowej (do 10 znaków)\
- premium (bez ograniczeń znakowych, ale ze zwiększonym kosztem przesłania)

Użytkownik ma możliwość obsługi programu poprzez wykonywanie metod klasy Menu.

Komunikaty o utworzeniu nowej centrali, połączeniu dwóch central, dodaniu nowego klienta oraz nadaniu wiadomości przez klienta zostają zapisane w pliku tekstowym "testowanie.txt"
