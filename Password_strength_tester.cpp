#include<iostream>
#include<chrono>
#include<thread>
#include<cctype>
#include<cstdlib>

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
            strength="Very Weak";
            break;
        case 2:
            strength="Weak";
            break;
        case 3:
            strength="Moderate";
            break;
        case 4:
            strength="Strong";
            break;
        case 5:
            strength="Very Strong";
            break;
        default:
            strength="Unknown";
            break;
    }

    tprt("Password Strength: ");
    tprt(strength);
    std::cout<<std::endl;
}

int main(){

    char choice='y';
    int runned=0;

    tprt("welcome to the password strength tester! \n");
    tprt("before we start, please tell us your name: ");
    std::string name;
    std::getline(std::cin, name);
    tprt("hello, "+name+"! let's test the strength of your password. \n");

    while(choice=='y' || choice=='Y'){

        if(runned>0){
            tprt("Loding");
            tprt("...........................",80);
        std::cout<<std::endl;
        std::cout<<std::endl;
        }
        tprt("please enter your password: ");
        std::string password;
        std::getline(std::cin, password);
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