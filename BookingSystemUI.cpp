#include "iostream"
#include "BookingSystemUI.h"
#include "string"
#include <cstdlib>

enum Command { CHECK = 1, BOOK, RETURN, VIEW_BY_ID, VIEW_BY_NAME, QUIT};
BookingSystem mySystem = BookingSystem("config.txt");

void BookingSystemUI::StartUI() {
    while (true){
        int n;
        try {
            std::string s;
            std::cout << "Chose the command: ";
            getline(std::cin, s);
            n = std::stoi(s);
            if (n < 0) throw 1;
        }
        catch (...) {
            std::cerr << "You must answer with a whole number >= 0." << std::endl;
        }
        fflush(stdin);
        if (n > 6) {
            std::cout << "The command is not implemented!" << std::endl;
        }
        system("clear");
        if (n == CHECK) {
            std::string flightDate;
            std::cout << "enter flight date: ";
            getline(std::cin, flightDate);
            std::string flightCode;
            std::cout << "enter flight code: ";
            getline(std::cin, flightCode);
            mySystem.Check(flightDate, flightCode);
        }
        if (n == BOOK) {
            std::string flightDate;
            std::cout << "enter flight date: ";
            getline(std::cin, flightDate);
            std::string flightCode;
            std::cout << "enter flight code: ";
            getline(std::cin, flightCode);
            std::string row;
            std::cout << "enter row: ";
            getline(std::cin, row);
            std::string column;
            std::cout << "enter column: ";
            getline(std::cin, column);
            std::string name;
            std::cout << "enter username: ";
            getline(std::cin, name);
            std::string passcode;
            std::cout << "enter passcode: ";
            getline(std::cin, passcode);
            mySystem.Book(flightDate, flightCode, std::stoi(row),
                          column[0],name,passcode);
        }

        if (n == RETURN) {
            std::string id;
            std::cout << "enter ID: ";
            getline(std::cin, id);
            std::string passcode;
            std::cout << "enter passcode: ";
            getline(std::cin, passcode);
            mySystem.ReturnWithId(std::stoi(id), passcode);
        }
        if (n == VIEW_BY_ID) {
            std::string id;
            std::cout << "enter ID: ";
            getline(std::cin, id);
            mySystem.ViewWithId(std::stoi(id));
        }
        if (n == VIEW_BY_NAME) {
            std::string name;
            std::cout << "enter name: ";
            getline(std::cin, name);
            mySystem.ViewWithName(name);
        }
        if (n == QUIT){
            return;
        }
    }}
