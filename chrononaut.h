#ifndef CHRONONAUT_H
#define CHRONONAUT_H
    #include <iostream>
    #include "populationCentre.h"

    class Chrononaut {
        private:
            std::string name;
            int type;
            int actualAge;
            int travelAge;
            int abilityLevel;
            bool isDead;
            int chanceAffected;
        public:
            Chrononaut();
            Chrononaut(std::string, int);
            void increaseTravelAge();
            void generateActualAge();
            void generateAbility();
            void improveAbility();
            void affectAbility();
            int getAbilityLevel();
            void display();
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
            void cure();
    };

    class Historian : public Chrononaut {
        private:
        public:
            Historian();
            Historian(std::string, int);
            void findInfo();
    };

    class Security : public Chrononaut {
        private:
        public:
            Security();
            Security(std::string, int);
            void interactLocal();
    };

    class ChronoPet : public Chrononaut {
        private:
        public:
            ChronoPet();
            ChronoPet(std::string, int);
            void protect();
    };

#endif
