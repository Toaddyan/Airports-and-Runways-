CXXFLAGS =-Wall

all: testFacility testCode testRunway testSiteNumber airport distance

testFacility: testFacility.o Facility.o gcdistance.o
	$(CXX) -o $@ $^

testCode: testCode.o  Facility.o gcdistance.o
	$(CXX) -o $@ $^

testRunway: testRunway.o Runway.o
	$(CXX) -o $@ $^

testSiteNumber: testSiteNumber.o Facility.o Runway.o gcdistance.o
	$(CXX) -o $@ $^

airport: airport.o Facility.o Runway.o gcdistance.o 
	$(CXX) -o $@ $^

distance: distance.o Facility.o Runway.o gcdistance.o 
	$(CXX) -o $@ $^

clean: 
		rm -f $(execs) *.o
