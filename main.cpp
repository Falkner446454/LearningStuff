#include <iostream>
#include <vector>
#include <cmath>

struct object {
	double Xcoord{};
	double Ycoord{};
	double Zcoord{};
	double mass{};
	double Xvelo{};
	double Yvelo{};
	double Zvelo{};
	double Xacc{};
	double Yacc{};
	double Zacc{};
	double Xforce{};
	double Yforce{};
	double Zforce{};

};

constexpr double gravconst{ 1 };


int main() {
	
	std::cout << "Welcome to the physics simulator,\nThe current version is 1.0, that being an extremely basic simulator, with just a few very basic things.\n";
	std::cout << "The world around you contains three unit vectors and time, along with forces\n Let us simulate 2 object of a certain mass, and gravity between them.\n";
	
	std::cout << "Please enter the unit vectors and then mass of object A\n";
	double AXcoord{};
	double AYcoord{};
	double AZcoord{};
	double Amass{};
	std::cin >> AXcoord;
	std::cin >> AYcoord;
	std::cin >> AZcoord;
	std::cin >> Amass;
	object PlanetA { AXcoord, AYcoord, AZcoord , Amass};
	
	std::cout << "Please enter the unit vectors and then mass of object B\n";
	double BXcoord{};
	double BYcoord{};
	double BZcoord{};
	double Bmass{};
	std::cin >> BXcoord;
	std::cin >> BYcoord;
	std::cin >> BZcoord;
	std::cin >> Bmass;
	object PlanetB{ BXcoord, BYcoord, BZcoord , Bmass};
	
	double AXsepar{};
	double BXsepar{};

	std::cout << "Please enter the desired time of simulation\n";
	double endtime{};
	std::cin >> endtime;
	double time{};
	double deltaTime{0.01};
	while (time <= endtime) {

		/* Lets just try the xcoordinate for now*/

		
		AXsepar = PlanetB.Xcoord - PlanetA.Xcoord;
		BXsepar = PlanetA.Xcoord - PlanetB.Xcoord;
		if (AXsepar <= 4 && AXsepar >= -4) {
			deltaTime = 0.00001;
		}
		else {
			deltaTime = 0.01;
		}
		if (AXsepar <= 1 && AXsepar >= -1) {
			deltaTime = 0.00000001;
		}
		else {
			deltaTime = 0.01;
		}
		std::cout << "deltaTime is " << deltaTime << "\n";

		if (AXsepar < 0) {
			PlanetA.Xforce = (gravconst * PlanetA.mass * PlanetB.mass) / (AXsepar * AXsepar * -1.00);
		}
		else{
			PlanetA.Xforce = (gravconst * PlanetA.mass * PlanetB.mass) / (AXsepar * AXsepar );
		}
		
		PlanetB.Xforce = PlanetA.Xforce * -1.00;


			PlanetA.Xacc = PlanetA.Xforce / PlanetA.mass;
			PlanetB.Xacc = PlanetB.Xforce / PlanetB.mass;
			if (PlanetA.Xacc < 0) {
				PlanetA.Xcoord = (0.5 * PlanetA.Xacc * PlanetA.Xacc * -1) + (PlanetA.Xvelo * deltaTime) + PlanetA.Xcoord; //Integrate constant acceleration twice, constants of integration being the current starting velocity and the current Xcoordinate
			}
			else {
				PlanetA.Xcoord = (0.5 * PlanetA.Xacc * PlanetA.Xacc ) + (PlanetA.Xvelo * deltaTime) + PlanetA.Xcoord;
			}
			if (PlanetB.Xacc < 0) {
				PlanetB.Xcoord = (0.5 * PlanetB.Xacc * PlanetB.Xacc * -1) + (PlanetB.Xvelo * deltaTime) + PlanetB.Xcoord;
			}
			else {
				PlanetB.Xcoord = (0.5 * PlanetB.Xacc * PlanetB.Xacc) + (PlanetB.Xvelo * deltaTime) + PlanetB.Xcoord;
			}
			std::cout << PlanetA.Xacc << " Is the Acceleration of A     " << PlanetB.Xacc << " Is the Acceleration of B\n";
			std::cout << PlanetA.Xvelo << " Is the Velocity of A     " << PlanetB.Xvelo << " Is the Velocity of B\n";
			PlanetA.Xvelo = PlanetA.Xvelo + (PlanetA.Xacc * deltaTime);
			PlanetB.Xvelo = PlanetB.Xvelo + (PlanetB.Xacc * deltaTime);

			std::cout << PlanetA.Xcoord << "     " << PlanetB.Xcoord << "\n";


		
		
            time = time + deltaTime;
	}


	
	


	



	
	return 0;
}