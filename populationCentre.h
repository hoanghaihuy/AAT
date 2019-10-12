#ifndef POPULATION_CENTRE_H
#define POPULATION_CENTRE_H
    #include <iostream>
    #include <vector>
    #include "const.h"

    class TechEra {
        private:
            std::string name;
            TECHNOLOGY_ERA type;
            double level;
            double growRate;
        public:
            TechEra();
            TechEra(TECHNOLOGY_ERA);
            TechEra& operator=(const TechEra&);
            void display();
            void generateLevel(int, int);
            void generateGrowRate(double, double);
            void affectedByBreakthrough();
            void affectLevel(double otherLevel);
            void setLevel(double);
            double getLevel();
            void setGrowRate(double);
            double getGrowRate();
            TECHNOLOGY_ERA getTechEra();
            void increaseGrowRate();
            void increaseLevel();
    };

    class Element {
    private:
        double level;
        double growRate;
    public:
        void generateLevel(int, int);
        void affectGrowRate();
        void affectLevel();
        void setLevel(double);
        double getLevel();
        void setGrowRate(double);
        double getGrowRate();
        void increaseLevel();
    };

    class Functionality : public Element {
        private:
            std::string name;
            FUNCTION_TYPE type;
        public:
            Functionality();
            Functionality(FUNCTION_TYPE, std::string, TechEra);
            void display();
            FUNCTION_TYPE getType();
    };

    class Population : public Element {
        private:
            int number;
        public:
            Population();
            Population(int);
            void generatePopImpact(TechEra);
            int getPopNum();
            void setPopNum(int);
            void display();
            void increasePopNum();
            void affectedByRevolution(PopulationCentre&);
    };

    void identifyPopType(int, POPULATION_CENTRE&);
    void identifyFunctionality(POPULATION_CENTRE, std::string&, std::vector<Functionality>&, TechEra);

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
            void techEraAffected(TechEra);
            void display();
            int getYearSpent();
            void setYearSpent(int);
            std::string getName();
            void setName(std::string);
            POPULATION_CENTRE getType();
            void setType(POPULATION_CENTRE);
            void decreasePop(bool = false);
    };

#endif
