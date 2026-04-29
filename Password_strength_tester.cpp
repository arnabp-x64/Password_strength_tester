#include<iostream>
#include<chrono>
#include<thread>
#include<cctype>
#include<cstdlib>
#include<windows.h>

void tprt(const std::string &text, int Delay=30){

    for(char c: text){
        std::cout<<c<<std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(Delay));

    }
}

void PSWC(std::string Password){

    int score=0;
    bool hasUpper=false, hasLower=false, hasDigit=false, hasSpecial=false;

    if(Password.length()>=8) score++;;

    for(char z: Password){
        if(std::isupper(z)) hasUpper=true;
        else if(std::islower(z)) hasLower=true;
        else if(std::isdigit(z)) hasDigit=true;
        else hasSpecial=true;
    }

    if(hasUpper) score++;
    if(hasLower) score++;  
    if(hasDigit) score++;
    if(hasSpecial) score++;

    tprt("Password Strength: ");
    std::cout<<score<<"/5"<<std::endl;

    std::string strength;
    switch(score){
        case 0:
        case 1:
            strength="\033[91mVery Weak\033[0m";
            break;
        case 2:
            strength="\033[91mWeak\033[0m";
            break;
        case 3:
            strength="\033[93mModerate\033[0m";
            break;
        case 4:
            strength="\033[92mStrong\033[0m";
            break;
        case 5:
            strength="\033[92mVery Strong\033[0m";
            break;
        default:
            strength="\033[5mUnknown\033[0m";
            break;
    }

    tprt("Password Strength: ");
    tprt(strength);
    std::cout<<std::endl;
}


int main(){
    // Enable ANSI escape codes for Windows 10/11
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    char choice='y';
    int runned=0;

    tprt("\033[1mwelcome to the password strength tester!\033[0m \n");
    tprt("before we start, please tell us your name:\033[94m ");
    std::string name;
    std::getline(std::cin, name);
    tprt("\033[0mhello, \033[93m"+name+"\033[0m! let's test the strength of your password. \n");

    while(choice=='y' || choice=='Y'){

        if(runned>0){
            tprt("Loding");
            tprt("...........................",80);
        std::cout<<std::endl;
        std::cout<<std::endl;
        }
        tprt("please enter your password: \033[2;0;107m");
        std::string password;
        std::getline(std::cin, password);
        std::cout<<"\033[0m"; // Reset color
        PSWC(password);
        tprt("do you want to test another password? (y/n): ");
        std::cin>>choice;
        std::cin.ignore();
        runned++;

        system("cls"); // Clear the console for the next test

    }

    std::cout<<"Closing in 5 seconds..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");

    std::cout<<"Closing in 4 seconds..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");

    std::cout<<"Closing in 3 seconds..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");

    std::cout<<"Closing in 2 seconds..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");

    std::cout<<"Closing in 1 seconds..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");


    return 0;
}