#include <iostream>
#include <thread>
#include <chrono>

//alap változók
const int hosszusag = 20;
const int szelesseg = 60;
std::string labda = "o";
const std::string feltoltes = " ";
int irany = 1;
int x = 2;
int y = 2;

//kétdimenziós tömb a karaktereknek
std::string screen[hosszusag][szelesseg];


//helyes megjelenítéshez szükséges első feltöltése a tömbnek
void feltolt(){
    for (int i = 0; i < hosszusag; i++)
    {
        for (int j = 0; j < szelesseg; j++)
        {
            if (i == 0 || i == hosszusag-1)
            {
                screen[i][j] = "-";
            }
            if(j == 0 || j == szelesseg-1){
                screen[i][j] = "|";

            }
            if(j != 0 && j != szelesseg-1 && i != 0 && i != hosszusag-1){
                screen[i][j] = feltoltes;
            }   
        }                      
    }
}

//kiírja táblázatosan a screen tömb tartalmát majd törli a cmd tartalmát, ezzel egy animáció effektust elérve
void megjelenit(){
    for (int i = 0; i < hosszusag; i++)
    {
        for (int j = 0; j < szelesseg; j++)
        {
            std::cout << screen[i][j];
        }
        std::cout << std::endl;                       
    }  
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::system("cls");
}

//a labda lehetséges mozgásirányai
void mozgas(){
    switch (irany)
    {
        case 1: //jobble
            y++;
            x++;
            break;
        case 2: //jobbfel
            y--;
            x++;
            break;
        case 3: //balle
            y++;
            x--;
            break;
        case 4: //balfel
            y--;
            x--; 
            break;
        default:
            break;
    }
}

//a labda mozgásirányának változása az y tengelyen attól függően, hogy honnan érkezett
void iranyvaltoz_y(){
    switch (irany)
    {
        case 1:
            irany = 2;
            break;
        case 2:
            irany = 1;
            break;
        case 3:
            irany = 4;
            break;
        case 4:
            irany = 3;
            break;
        default:
            break;
    }
}

//a labda mozgásirányának változása az x tengelyen attól függően, hogy honnan érkezett
void iranyvaltoz_x(){
    switch (irany)
    {
        case 1:
            irany = 3;
            break;
        case 2:
            irany = 4;
            break;
        case 3:
            irany = 1;
            break;
        case 4:
            irany = 2;
            break;
        default:
            break;
    }
}



int main(){
    feltolt();
    while(true)
    {  
        screen[y][x] = labda;

        megjelenit();

        screen[y][x] = feltoltes;

        //ha ütözik az y tengely széleivel akkor megváltoztatja a labda irányát az iranyvaltoz_y() függvény alapján
        switch (y)
        {
            case 1:
                iranyvaltoz_y();
                break;
            case hosszusag-2:
                iranyvaltoz_y();
                break;
            default:
                break;
        }

        //ha ütözik az x tengely széleivel akkor megváltoztatja a labda irányát az iranyvaltoz_x() függvény alapján
        switch (x)
        {
            case 1:
                iranyvaltoz_x();
                break;
            case szelesseg-2:
                iranyvaltoz_x();
                break;
            default:
                break;
        }

        mozgas();
    }
}