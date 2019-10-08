#ifndef ARTIFACT_H
#define ARTIFACT_H
    #include <iostream>
    class Artifact {
        private:
            std::string name;
            std::string description;
            int estimatePeriod;
            int info;
        public:
            Artifact();
            Artifact(std::string, std::string, int);
            void display();
    };
#endif
