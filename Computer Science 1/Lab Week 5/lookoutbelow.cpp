#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// input variables
	double distance, speed, verDist;

	// get inputs
	cout << "How far is your friend (feet): "; cin >> distance;
	cout << "How fast are they walking (feet/sec): "; cin >> speed;
	cout << "How hight are you before dropping your balloon (feet): "; cin >> verDist;

	// calculate how long it takes for friend to reach the balloon point
	const double targetToBalloonPointTime = distance / speed;

	// set up vaiables for finding the time for balloon to hit the ground
	const double drag = .0012, g = 32, timeStep = .001, epsilon = .01;
	double v = 0, x = 0;
	double waitTime = 0;

	// calculating when the balloon will hit the ground
	do {
		v -= (drag * v - g) * timeStep;
		x += v * timeStep;
		waitTime += timeStep;
	} while (x < verDist);

	// output data
	cout << fixed << setprecision(2);
	cout << "It will take " << targetToBalloonPointTime << " seconds for them to reach the balloon point" << endl;
	cout << "It will take " << waitTime << " seconds for for your balloon to travel to the ground" << endl;

	// output results
	if (abs(waitTime - targetToBalloonPointTime) <= epsilon)
		cout << "Bingo, you hit your friend successfully" << endl;
	else if (waitTime > targetToBalloonPointTime)
		cout << "It is too late to drop your balloon" << endl;
	else
		cout << "If you wait " << targetToBalloonPointTime - waitTime << " seconds, you will hit them" << endl;
	
	return 0;
}
