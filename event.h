#ifndef EVENT_H
#define EVENT_H
    #include <iostream>
    #include "populationCentre.h"

    class Event {
        private:
            std::string name;
            std::string description;
            double level;
        public:
            Event();
            Event(std::string, std::string);
            void generateLevel(PopulationCentre);
            void display();
    };

#endif
