# QT Simple Calculator - Un studiu de caz în C++ și Qt

### Introducere
Acest proiect reprezintă un instrument de calcul dezvoltat în mediul Qt, având ca scop aprofundarea conceptelor de programare orientată pe obiecte (OOP), gestionarea memoriei și implementarea algoritmilor numerici fără a recurge la biblioteci externe standard acolo unde logica de calcul a putut fi reconstruită manual.

### Provocări Tehnice și Implementare
Spre deosebire de un calculator convențional, acest proiect pune accent pe **"the hard way"** în procesul de învățare:

* **Gestionarea Interfeței (UI):** Nu am folosit Qt Designer (drag-and-drop). Întreaga interfață este construită integral din cod, utilizând layout-uri imbricate (`QVBoxLayout`, `QFormLayout`) pentru a asigura o scalabilitate corectă a ferestrei.
* **Mecanismul Signal-Slot:** Comunicarea între componentele grafice și logica de business este realizată prin sistemul de semnale și sloturi al Qt, respectând principiul decuplării codului (Decoupling).
* **Algoritmi Numerici:**
    * **Ridicarea la putere:** Implementată prin metoda ridicării la pătrate succesive (Binary Exponentiation), reducând complexitatea de la $O(n)$ la $O(\log n)$.
    * **Extragerea radicalului:** Implementată folosind metoda Newton-Raphson, un algoritm iterativ de aproximare numerică a rădăcinilor.

### Tehnologii Utilizate
* **C++17**
* **Qt Framework** (Core, Widgets)
* **CMake** (Sistem de build)

### Instalare și Rulare
1. Clonați repository-ul.
2. Deschideți fișierul `CMakeLists.txt` în Qt Creator.
3. Compilați și rulați proiectul în modul Debug sau Release.