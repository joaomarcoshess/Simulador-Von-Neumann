#include<iostream>
#include<fstream>
#include"./cpu/REGISTER_BANK.h"
#include"./cpu/CONTROL_UNIT.h"
#include"./cpu/HashRegister.h"


using namespace std;

int main(){

        int counter = 0;
        ifstream file("programa.txt"); // Joga o programa inteiro na RAM
        string line;
        REGISTER_BANK registers;
        Control_Unit UC;
        bool endProgram = false;
        int counterForEnd = 5;
        int clock = 0;

        // Chamada das instruções de fetch, decode, execução, memory_access e write, respectivamente, da unidade de controle
        while(counterForEnd > 0){
            if(counter >= 0 && counterForEnd == 5){
                UC.Fetch(registers, endProgram);
            }
            if(counter >= 1 && counterForEnd >= 4){
                UC.Decode(registers, UC.data[counter]);
            }
            if(counter >= 2 && counterForEnd >= 3){
                UC.Execute(registers,UC.data[counter - 1], counter);
            }
            if(counter >= 3 && counterForEnd >= 2){
                UC.Memory_Acess(registers, UC.data[counter - 2]);
            }
            if(counter >= 4 && counterForEnd >= 1){
                UC.Write_Back(UC.data[counter - 3]);
            }
            counter =+ 1;
            clock =+ 1;
            if(endProgram == true){
                counterForEnd =- 1;
            }
        }
    
    return 0;
}
