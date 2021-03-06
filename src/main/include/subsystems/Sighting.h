#ifndef Sighting_H
#define Sighting_H

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

#include <atomic>
#include <chrono> // May not be needed
#include <cstdint>
#include <iomanip>
#include <thread>

#define Y_ERROR_MARGIN 15 // PIXELS
#define X_ERROR_MARGIN 20
#define AREA_ERROR_MARGIN .15 // PERCENT ERROR

class Sighting : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Sighting();
	void InitDefaultCommand();
	void cleanContours();
	double findFacingAngle();
	double DistanceToTarget();
	void readTable();
	bool TwoContoursAvailable();
	double getCenterX();
	double distanceFromTarget();
	double d1;
	double d2;
	double boardAng;
	double pixelWidth1, pixelWidth2;

	std::vector<double> area, centerX, centerY, height, width;
};

#endif  // Sighting_H