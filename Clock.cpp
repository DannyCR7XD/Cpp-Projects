//Danny Castaneda
/*A C++ class called Clock for dealing with the daytime represented by hours, minutes,
and seconds.*/

#include <iostream>

using namespace std;

class Clock 

{
    
    private:
     int hours, minutes, seconds;

    
    public:

     Clock() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    
    Clock(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

// Instance Functions:  
    int getHours() { return hours; }

    int getMinutes() { return minutes; }

    int getSeconds() { return seconds; }

    
    void setHours(int h) {
        hours = h;
    }

    void setMinutes(int m) {
        minutes = m;
    }

    void setSeconds(int s) {
        seconds = s;
    }

    
    void tick() {
        seconds += 1;
        minutes += seconds / 60; 
        seconds = seconds % 60;
        hours += minutes / 60;
        minutes = minutes % 60;
        hours = hours % 24;
    }

    
    void printClock() {
        int h = hours % 12;
        if (h == 0)
            h = 12;
        printf("Time: %02d:%02d:%02d %s", h, minutes, seconds, hours < 12 ? "AM" : "PM");
    }
};


Clock addClocks(Clock firstClock, Clock secondClock) {
    Clock sum;
    sum.setHours( (firstClock.getHours() + secondClock.getHours()) % 24 );
    sum.setMinutes( (firstClock.getMinutes() + secondClock.getMinutes()) % 60 );
    sum.setSeconds( (firstClock.getSeconds() + secondClock.getSeconds()) % 60 );
    return sum;
}

int main() {
    Clock firstClock;
    cout << "Creating firstClock object using the default constructor: "  << endl;
    firstClock.printClock();
    cout << endl;
    cout << "Ticking firstClock object: " << endl;
    for (int i=0; i<10; i++) {
        cout << "Tick " << i+1 << " : ";
        firstClock.tick();
        firstClock.printClock();
        cout  << endl;
    }
    cout << endl;
    cout << "Creating secondClock object using the second constructor" << endl;
    int h, m, s;
    cout << "Enter Value for hour: ";
    cin >> h;
    cout << "Enter Value for minutes: ";
    cin >> m;
    cout << "Enter Value for seconds: ";
    cin >> s;
    Clock secondClock(h, m, s);
    secondClock.printClock();
    cout << endl;
    cout << "Ticking secondClock object : " << endl;
    for (int i=0; i<10; i++) {
        cout << "Tick " << i+1 << " : ";
        secondClock.tick();
        secondClock.printClock();
        cout  << endl;
    }
    cout << "Adding the time in the firstClock object to the time in the secondClock object to produce the thirdClock object:" << endl;
    Clock thirdClock = addClocks(firstClock, secondClock);
    cout << "Time in thirdClock is: ";
    thirdClock.printClock();
    cout << endl;
    cout << "Changing the time in firstClock object to be: ";
    firstClock.setHours(7);
    firstClock.setMinutes(23);
    firstClock.setSeconds(15);
    firstClock.printClock();
    cout << endl;
    

    if (firstClock.getHours() == secondClock.getHours() && firstClock.getMinutes() == secondClock.getMinutes() && firstClock.getSeconds() == secondClock.getSeconds())
        cout << "firstClock and secondClock have the same time" << endl;
    else
        cout << "firstClock and secondClock do not have the same time" << endl;
}