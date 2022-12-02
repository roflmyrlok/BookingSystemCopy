#include <fstream>
#include <sstream>
#include "iostream"
#include "BookingSystem.h"
#include "unordered_set"

std::vector<TicketData> places;
int lastID;

BookingSystem::BookingSystem(const std::string& filepath){
    places = *new std::vector<TicketData>;
    lastID = 11111;
    std::fstream newFile;
    newFile.open(filepath, std::ios::in);
    if (newFile.is_open()){
        std::string curr;
        while(getline(newFile, curr)){
            convertStringAndCreateFlight(curr);
        }
        newFile.close();
    }
}
void BookingSystem::BookingSystem::Check(const std::string& date, const std::string& flight){
    for (int i = 0; i < places.size(); ++i) {
        if (places[i].flightCode == flight && places[i].flightData == date && places[i].free){
            std::cout << places[i].row;
            std::cout << "-";
            std::cout << places[i].column;
            std::cout << " ";
            std::cout << places[i].price;
            std::cout << ", ";
            if ((i + 1) % 10 == 0) std::cout << std::endl;
        }
    }
    std::cout << " " << std::endl;
}

void BookingSystem::Book(const std::string& date, const std::string& flight, const int row, const char column,
                         const std::string& username, const std::string& passcode){
    for (auto & place : places) {
        if (place.flightCode == flight && place.flightData == date && place.row == row &&
            place.column == column){
            if (place.free){
                place.BookTicket(username, passcode);
                std::cout << "Confirmed with id: ";
                std::cout << place.id;
            } else {
                std::cout << "place is booked";
            }
        }
    }
    std::cout << " " << std::endl;
}

void BookingSystem::ReturnWithId(const int id, const std::string& passcode){
    for (auto & place : places) {
        if (place.CheckID(id)){
            place.ReturnTicket(passcode);
            std::cout << "Confirmed ";
            std::cout << place.price << std::endl;
        }
    }
}

void BookingSystem::ViewWithId(const int id){
    for (auto & place : places) {
        if (place.CheckID(id)){
            std::cout << place.flightCode;
            std::cout << " ";
            std::cout << place.flightData;
            std::cout << " ";
            std::cout << place.column;
            std::cout << "-";
            std::cout << place.row;
            std::cout << " ";
            std::cout << place.price;
            std::cout << " ";
            std::cout << place.id;
            std::cout << " " << std::endl;
        }
    }
}

void BookingSystem::ViewWithName(const std::string& name){
    for (auto & place : places) {
        if (place.CheckUsername(name)){
            std::cout << place.flightCode;
            std::cout << " ";
            std::cout << place.flightData;
            std::cout << " ";
            std::cout << place.column;
            std::cout << "-";
            std::cout << place.row;
            std::cout << " ";
            std::cout << place.price;
            std::cout << " ";
            std::cout << place.id;
            std::cout << " " << std::endl;
        }
    }
}

void BookingSystem::tokenize(std::string const &str, const char delim,std::vector<std::string> &out){
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}
void BookingSystem::convertStringAndCreateFlight(std::string inp) {
    std::string s = std::move(inp);
    char delim = ' ';

    std::vector<std::string> div;
    tokenize(s, delim, div);
    std::string date = div[0];
    std::string flight = div[1];
    int columns = std::stoi(div[2]);
    int i = 3;
    while(i < div.size()){
        std::string rowToSplit = div[i];
        std::string price = div[i+1];
        char ldelim = '-';

        std::vector<std::string> borders;
        tokenize(rowToSplit, ldelim, borders);
        int startRow = std::stoi(borders[0]);
        int endRow = std::stoi(borders[1]);
        addFlightClass(date,flight,columns,startRow,endRow,price);
        i += 2;
    }
}
//methods files places data with all places from one class(sorted by price) of one flight
void BookingSystem::addFlightClass(const std::string& date,const std::string& flightNumber,const int columns,
                                   const int startRow, const int endRow,const std::string& price){
    const std::string column = "0ABCDEFGHIJKLMN";
    for (int i = startRow; i <= endRow; ++i) {
        for (int j = 1; j <= columns; ++j) {
            TicketData curr = TicketData(date, flightNumber, i, column[j], price, lastID + 1);
            places.push_back(curr);
            lastID += 1;
        }
    }
}