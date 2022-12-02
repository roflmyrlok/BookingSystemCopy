#ifndef TERM2LAB1_BOOKINGSYSTEMUI_H
#define TERM2LAB1_BOOKINGSYSTEMUI_H
#include "BookingSystem.h"

class BookingSystemUI{
private:
    BookingSystem mySystem = BookingSystem("config.txt");
public:
    void StartUI();
};


#endif //TERM2LAB1_BOOKINGSYSTEMUI_H
