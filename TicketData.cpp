#include "TicketData.h"
TicketData::TicketData(std::string IFlightData, std::string IFlightCode, int IRow, char IColumn, std::string IPrice, int IID) {
    flightData = std::move(IFlightData);
    flightCode = std::move(IFlightCode);
    id = IID;
    row = IRow;
    column = IColumn;
    price = std::move(IPrice);
//all places are free when flight is just created
    free = true;
    username = "";
    passcode = "00000";
}
void TicketData::BookTicket(std::string name, const std::string &checkPasscode) {
    this->free = false;
    this->passcode = checkPasscode;
    this->username = std::move(name);
}
bool TicketData::ReturnTicket(const std::string &checkPasscode) {
    if (checkPasscode == this->passcode) {
        this->free = true;
        this->passcode = "00000";
        this->username = "";
        return true;
    }
    return false;
}
bool TicketData::CheckID(int CheckID) const {
    if (this->id == CheckID) {
        return true;
    } else return false;
}
bool TicketData::CheckUsername(const std::string &checkName) const {
    if (this->username == checkName) {
        return true;
    } else return false;
}
/*
bool TicketData::operator==(const TicketData &otherPoint) const {
    if (this->flightCode == otherPoint.flightCode &&
            this->flightData == otherPoint.flightData &&
            this->id == otherPoint.id &&
            this->row == otherPoint.row &&
            this->column == otherPoint.column &&
            this->price == otherPoint.price) return true;
    else return false;
}

struct TicketData::HashFunction
{
    size_t operator()(const TicketData& ticket) const
    {
        size_t FlightHash = std::hash<std::string>()(ticket.flightCode) >> 1;
        size_t DATeHash = std::hash<std::string>()(ticket.flightData) << 1;
        size_t ColumnHash = std::hash<char>()(ticket.column) << 1 << 1;
        size_t ROWHash = std::hash<int>()(ticket.row);
        return FlightHash ^ DATeHash ^ ColumnHash ^ ROWHash;
    }
};*/