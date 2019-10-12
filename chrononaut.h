#ifndef CHRONONAUT_H
#define CHRONONAUT_H
    #include <iostream>
    #include "populationCentre.h"
    #include "artifact.h"
    #include "event.h"

    class Chrononaut {
        private:
            std::string name;
            int type;
            int actualAge;
            int travelAge;
            double abilityLevel;
            int chanceAffected;
            double health;
        public:
            Chrononaut();
            Chrononaut(std::string, int);
            void increaseTravelAge();
            void generateActualAge();
            void generateAbility();
            void improveAbility(TechEra);
            void affectAbility();
            int getAbilityLevel();
            void display();
            double getHealth();
            void setHealth(double);
            void beingDamaged(double);
            void getIllness();
            void getWar();
            bool isDead();
    };

    class JumpEngineer : public Chrononaut {
        private:
        public:
            JumpEngineer();
            JumpEngineer(std::string, int);
            TECHNOLOGY_ERA findTechEra(int);
            void makeJump(int, TechEra&, PopulationCentre&);
    };

    class Doctor : public Chrononaut {
        private:
        public:
            Doctor();
            Doctor(std::string, int);
            double cure(Event, PopulationCentre);
    };

    class Historian : public Chrononaut {
        private:
        public:
            Historian();
            Historian(std::string, int);
            double findInfo(Event, bool);
            void solvedEvent(double);
    };

    class Security : public Chrononaut {
        private:
        public:
            Security();
            Security(std::string, int);
            void interactLocal(Event, TechEra&, PopulationCentre&);
    };

    class ChronoPet : public Chrononaut {
        private:
        public:
            ChronoPet();
            ChronoPet(std::string, int);
            double protect(Event, PopulationCentre);
    };

#endif
