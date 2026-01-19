# sklep
# opis projektu (visual paradigm na cpp)
Nasz kod został częściowo wygenerowany przez Visual Paradigm. W aplikacji tej sukcesywnie dodawałyśmy coraz to nowsze aktualizacje w oparciu o wykłady. Nasz plik w VP jest podzielony na Use Case Diagram, Class Diagram, Sequence Diagram, State Machine Diagram, Activity Diagram, Component Diagram oraz na Deployment Diagram. 
Nasz projekt dotyczy platformy do zakupów

INSTRUKCJA
1. Start i Wybór Akcji Po uruchomieniu programu klasa SystemLogowania wyświetla menu główne. Użytkownik ma do wyboru cztery ścieżki:
-Rejestracja (nowy klient)
-Logowanie jako Klient (istniejący użytkownik).
-Logowanie jako Sprzedawca (obsługa magazynu).
-Przeglądanie jako Gość (bez logowania).

2.1. Rejestracja (Klasa Gosc / SystemLogowania) 
System prosi o podanie loginu, hasła, e-maila oraz danych osobowych (imię, nazwisko, adres, telefon).
Weryfikacja: System sprawdza w pliku klienci.txt, czy login lub e-mail nie są już zajęte.
Zapis: Po pozytywnej weryfikacji dane są dopisywane do pliku klienci.txt.

2.2. Logowanie (Klasa Klient / SystemLogowania)  
Użytkownik podaje login i hasło. System przeszukuje plik klienci.txt.
Jeśli dane są poprawne, tworzony jest dynamiczny obiekt klasy Klient, który dziedziczy po klasie Gosc. System "pamięta" zalogowanego użytkownika przez cały czas trwania sesji.

3. Panel Klienta
Po zalogowaniu Klient może korzystać z przeglądania i wyszukiwania: Klasa Przegladanie_produktow pozwala wyświetlić listę z pliku produkty.txt lub szukać konkretnego towaru po nazwie (sprawdzając cenę i dostępność).

4. Panel Sprzedawcy (Klasa Sprzedawca)
Jeśli użytkownik zaloguje się danymi z pliku sprzedawcy.txt:
- Zyskuje dostęp do metod modyfikacji bazy danych.
- Dodawanie: Może dopisać nowy produkt do pliku produkty.txt.
- Modyfikacja: Może zmienić cenę istniejącego produktu lub zaktualizować stan magazynowy (ilość sztuk).
- Usuwanie: Pozwala usunąć produkt, którego nie ma już w ofercie.

5. Przechowywanie Danych System jest trwały dzięki wykorzystaniu plików tekstowych:
- klienci.txt – baza użytkowników.
- produkty.txt – baza towarów.
- sprzedawcy.txt – uprawnienia administracyjne.
