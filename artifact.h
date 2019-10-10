#ifndef ARTIFACT_H
#define ARTIFACT_H
    #include <iostream>
    class Artifact {
        private:
            std::string name;
            std::string description;
            int estimatePeriod;
            double info;
        public:
            Artifact();
            Artifact(std::string, std::string, int);
            int getPeriod();
            void display();
            double getInfo();
            void gainInfo(double);
    };
#endif
