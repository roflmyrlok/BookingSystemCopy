#ifndef TERM2LAB1_BOOKINGSYSTEM_H
#define TERM2LAB1_BOOKINGSYSTEM_H
#include <cstdlib>
#include <unordered_set>
#include "vector"
#include "TicketData.h"


class BookingSystem{
public:
    std::vector<TicketData> places;
    int lastID;
public:
    explicit BookingSystem(const std::string& filepath);

    void Check(const std::string& date, const std::string& flight);

    void Book(const std::string& date, const std::string& flight, int row, char column,
              const std::string& username, const std::string& passcode);

    void ReturnWithId(int id, const std::string& passcode);

    void ViewWithId(int id);

    void ViewWithName(const std::string& name);

private:
    static void tokenize(std::string const &str, char delim,std::vector<std::string> &out);
    void convertStringAndCreateFlight(std::string inp);
    //methods files places data with all places from one class(sorted by price) of one flight
    void addFlightClass(const std::string& date,const std::string& flightNumber,int columns,
                        int startRow, int endRow,const std::string& price);
};


#endif //TERM2LAB1_BOOKINGSYSTEM_H
