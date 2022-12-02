#ifndef TERM2LAB1_PLACEDATA_H
#include <cstdlib>
#include "string"

class TicketData{
public:
    std::string flightData; //represents date of flight format dd.mm.yyyy
    std::string flightCode; //represents flight code were this place is located
    std::string price;  //represents price for this place
    int row;//represents row were this place is located
    char column;//represents column were this place is located
    bool free; //represents if place is reserved by smn
    int id; //represents unique id for place
    //bool operator==(const TicketData& otherPoint) const;
    //struct HashFunction;

private:
    std::string username;//represents name of user reserved this place
    std::string passcode;//represents passcode user used to book this place

public:
    TicketData(std::string IFlightData, std::string IFlightCode, int IRow, char IColumn, std::string IPrice, int IID);
    void BookTicket(std::string name, const std::string& checkPasscode);
    bool ReturnTicket(const std::string& checkPasscode);
    bool CheckID(int CheckID) const;
    bool CheckUsername(const std::string& checkName) const;
};


#endif //TERM2LAB1_PLACEDATA_H
