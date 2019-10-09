#ifndef POPULATION_CENTRE_H
#define POPULATION_CENTRE_H
    #include <iostream>
    #include <vector>
    #include "const.h"

    class TechEra {
        private:
            std::string name;
            TECHNOLOGY_ERA type;
            int level;
            double growRate;
        public:
            TechEra();
            TechEra(TECHNOLOGY_ERA);
            TechEra& operator=(const TechEra&);
            void display();
            void generateLevel(int, int);
            void generateGrowRate(double, double);
            void affectGrowRate();
            void affectLevel();
            void setLevel(int);
            int getLevel();
            void setGrowRate(double);
            double getGrowRate();
            TECHNOLOGY_ERA getTechEra();
    };

    class Element {
    private:
        int level;
        double growRate;
    public:
        void generateLevel(int, int);
        void affectGrowRate();
        void affectLevel();
        void setLevel(int);
        int getLevel();
        void setGrowRate(double);
        double getGrowRate();
    };

    class Functionality : public Element {
        private:
            std::string name;
            FUNCTION_TYPE type;
        public:
            Functionality();
            Functionality(FUNCTION_TYPE, std::string);
            void display();
    };

    class Population : public Element {
        private:
            int number;
        public:
            Population();
            Population(int);
            void generatePopImpact(TechEra);
            int getPopNum();
            void display();
    };

    class PopulationCentre {
        private:
            std::string name;
            POPULATION_CENTRE populationType;
            int yearSpent;
            int currentYear;
            void generateFunctionality();
        public:
            TechEra *technology;
            std::vector<Functionality> functionalities;
            Population *population;
            PopulationCentre();
            PopulationCentre(TechEra, int, int);
            PopulationCentre& operator++();
            ~PopulationCentre();
            int getCurrentYear();
            void setCurrentYear(int);
            void setTechEra(TechEra);
            void display();
    };

#endif
