#ifndef EVENT_H
#define EVENT_H
    #include <iostream>
    #include "populationCentre.h"
    #include "const.h"

    class Event {
        private:
            std::string name;
            std::string description;
            EVENT_TYPE type;
            double level;
            int occurChance;
        public:
            Event();
            Event(std::string, std::string, EVENT_TYPE);
            void generateLevel(PopulationCentre);
            void display();
            int getOccurChance();
            void setOccurChance(int);
            EVENT_TYPE getEventType();
            int getLevel();
    };

#endif
