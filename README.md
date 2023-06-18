# Enkoder inkrementalny

Obsługa enkodera jest bardzo prosta. Do dwóch wejść mikrokontrolera podłączony jest enkoder. Piny podciągnięte są do zasilania poprzez rezystory. Podczas obrotu enkodera, na pinach pojawia się sygnał niski przesunięty względem pinów, kierunek ten jest zależny od kierunku obrotów enkodera. Pierwszy pin służy do generowania zewnętrznego przerwania. Wygenerowane przerwanie sprawdza stan na drugim pinie. W zależności od stanu, zmienna jest inkrementowana lub dekrementowana.

![image](https://github.com/MateuszKaminskiEmbedded/Enkoder-inkrementalny/assets/104322532/13c4ce0d-07df-41bc-a479-1b966877ea75)
