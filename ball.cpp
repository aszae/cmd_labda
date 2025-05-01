#include <iostream>
#include <thread>
#include <chrono>


int main(){
    std::string egysor[40];
    
    for (;;)
    {   
        bool vissza=false;
        if(vissza==false){
            for (int j = 0; j < 39; j++)
            {

                egysor[j]="O";
                for (int i = 0; i < 20; i++)
                {
                    std::cout << std::endl;
                }

            
                for (int i = 0; i < 40; i++)
                {
                    std::cout << egysor[i];
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(40));
                std::system("cls");
                egysor[j]=" ";

            }
            vissza=true;
        }
        if(vissza==true){
            for (int j = 39; j > 0; j--)
            {

                egysor[j]="O";
                for (int i = 0; i < 20; i++)
                {
                    std::cout << std::endl;
                }

            
                for (int i = 0; i < 40; i++)
                {
                    std::cout << egysor[i];
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(40));
                std::system("cls");
                egysor[j]=" ";
            }
            vissza=false;
        }
    }
    
}