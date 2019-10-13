#ifndef ARTIFACT_H
#define ARTIFACT_H
    #include <iostream>
    #include <vector>
    class Artifact {
        private:
            std::string name;
            std::string description;
            int estimatePeriod;
            double info;
        public:
            std::vector<int> clues;
            Artifact();
            Artifact(std::string, std::string, int, std::vector<int>);
            int getPeriod();
            void display();
            double getInfo();
            void setInfo(double);
            void gainInfo(double);
            std::string getName();
    };
#endif
