#ifndef CHRONONAUT_H
#define CHRONONAUT_H
    #include <iostream>

    class Chrononaut {
        private:
            std::string name;
            int type;
            int actualAge;
            int travelAge;
            double abilityLevel;
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
            void display();
    };

    class JumpEngineer : virtual public Chrononaut {
        private:
        public:
            JumpEngineer();
            JumpEngineer(std::string, int);
            void makeJump();
    };

    class Doctor : virtual public Chrononaut {
        private:
        public:
            Doctor();
            Doctor(std::string, int);
            void cure();
    };

    class Historian : virtual public Chrononaut {
        private:
        public:
            Historian();
            Historian(std::string, int);
            void findInfo();
    };

    class Security : virtual public Chrononaut {
        private:
        public:
            Security();
            Security(std::string, int);
            void interactLocal();
    };

    class ChronoPet : virtual public Chrononaut {
        private:
        public:
            ChronoPet();
            ChronoPet(std::string, int);
            void protect();
    };

#endif