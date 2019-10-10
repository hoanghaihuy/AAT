CCC = clang++
CCFLAGS = -std=c++11
TARGETS = AAT.o errors.o artifact.o handlingData.o randoms.o chrononaut.o populationCentre.o findArtifact.o event.o
all: $(TARGETS)
	$(CCC) $(CCFLAGS) $(TARGETS) -o AAT
AAT.o: AAT.cpp errors.h handlingData.h randoms.h artifact.h chrononaut.h const.h populationCentre.h findArtifact.h
	$(CCC) $(CCFLAGS) -c AAT.cpp
errors.o: errors.cpp errors.h const.h
	$(CCC) $(CCFLAGS) -c errors.cpp
artifact.o: artifact.cpp artifact.h const.h
	$(CCC) $(CCFLAGS) -c artifact.cpp
handlingData.o: handlingData.cpp handlingData.h errors.h randoms.h artifact.h chrononaut.h const.h event.h
	$(CCC) $(CCFLAGS) -c handlingData.cpp
randoms.o: randoms.cpp randoms.h
	$(CCC) $(CCFLAGS) -c randoms.cpp
chrononaut.o: chrononaut.cpp chrononaut.h const.h populationCentre.h
	$(CCC) $(CCFLAGS) -c chrononaut.cpp
populationCentre.o: populationCentre.cpp populationCentre.h const.h randoms.h
	$(CCC) $(CCFLAGS) -c populationCentre.cpp
findArtifact.o: findArtifact.cpp findArtifact.h artifact.h chrononaut.h const.h populationCentre.h handlingData.h
	$(CCC) $(CCFLAGS) -c findArtifact.cpp
event.o: event.cpp event.h const.h populationCentre.h
	$(CCC) $(CCFLAGS) -c event.cpp
clean:
	rm -rf *o AAT
