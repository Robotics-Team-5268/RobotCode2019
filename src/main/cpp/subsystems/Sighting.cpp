#include "subsystems/Sighting.h"
#include "RobotMap.h"
#include "CommandBase.h"
#include <math.h>
#include <vector>

const double OFFSET_TO_FRONT = 9.0; // Theortically distance from center of robot to camera
const double DISTANCE_CONSTANT = 5561.0; // Magic number, When we copied this code from the internet it came with this number
const double MAGIC_NUMBER = 1.37; // Makes distance accurate, because theoretical method is not perfect. Based on tape measure values.
const double IN_BETWEEN_CONTOURS = 11.5; // Distance between middle of contours in inches
// Camera's resolution
//const int yres = 480; // y resolution of Microsoft Life Camera - commented out because currently unused
const int xres = 640; // x resolution of Microsoft Life Camera

// Camera's field of view in radians
//const double vertFOV = 0.36397895; //20.85 degrees
const double horiFOV = 0.58800142; // 33.69 degrees
const double tanHoriFOV = 0.666665;

struct Sighting::Group selectedGroupTarget;

Sighting::Sighting() : frc::Subsystem("Sighting") {
}

void Sighting::InitDefaultCommand() {
	// Set the default command for a subsystem here.
}

double Sighting::findFacingAngle() { // comments in driver laptop
	if (centerX.size() >= 1)
		frc::SmartDashboard::PutNumber("First centerX", centerX[selectedGroupTarget.leftContourNum]);

		if (TwoContoursAvailable()) {
			const double inPerPx = IN_BETWEEN_CONTOURS / abs(centerX[selectedGroupTarget.leftContourNum] - centerX[selectedGroupTarget.rightContourNum]);
			double distanceFromCenterPixels = ((centerX[selectedGroupTarget.leftContourNum] + centerX[selectedGroupTarget.rightContourNum]) / 2) - (xres / 2);
			double distanceFromCenterInch = distanceFromCenterPixels * inPerPx;
			double angleToGoal = atan(distanceFromCenterInch / distanceFromTarget());
			angleToGoal = (angleToGoal / 3.14159265) * 180;
			frc::SmartDashboard::PutNumber("Angle To Goal", angleToGoal);
			return angleToGoal;
		}
}

double Sighting::distanceFromTarget(){
	/*// distance costant divided by length between centers of contours
	double lengthBetweenContours = (centerX[0] - centerX[1]) / 2;
	return (DISTANCE_CONSTANT / lengthBetweenContours) - OFFSET_TO_FRONT;*/

	findClosestGroup(groupContours());
	frc::SmartDashboard::PutNumber("number of contours", centerX.size());
	if (centerX[selectedGroupTarget.leftContourNum] !=0 && centerX[selectedGroupTarget.rightContourNum] !=0) {

	}

	// Written to assume it's only getting two valid contours
	if (TwoContoursAvailable()) {
		double pxBetweenContours = abs(centerX[selectedGroupTarget.leftContourNum] - centerX[selectedGroupTarget.rightContourNum]);
		double distanceToTarget = IN_BETWEEN_CONTOURS * xres / (2 * pxBetweenContours * tanHoriFOV) * MAGIC_NUMBER;
		frc::SmartDashboard::PutNumber("Distance to target", distanceToTarget);

		/*double xDistance = distanceToTarget * sin((CommandBase::drive->getGyroAngle()*3.14159/180.0));
		frc::SmartDashboard::PutNumber("X Distance", xDistance);*/
		if (distanceToTarget > 200) {
			frc::SmartDashboard::PutNumber("Distance to target", -1);
			return -1;
		}
		return distanceToTarget;
	}
	frc::SmartDashboard::PutNumber("Distance to target", -2);
	return -1;
}

//Update contour vectors
void Sighting::readTable() {
	CommandBase::udp->GetContours(centerX, centerY, width, height, angle);

	if (TwoContoursAvailable()) {
		frc::SmartDashboard::PutNumber("distance between contours", centerX[0] - centerX[1]);
	}
}

bool Sighting::TwoContoursAvailable() {
	return centerX.size() == 2; // returns true if there are 2 contours
}
// Get the center of the whole target by averaging the contours together
double Sighting::getCenterX() {
	if (TwoContoursAvailable())
		return (centerX[0] + centerX[1]) / 2.0;
	else return -1.0;
}

inline bool Sighting::pointWithContourBound(double x, double y, int contourNum) {
	if (abs(x - centerX[contourNum]) <= width[contourNum] / 2 && abs(y - centerY[contourNum]) <= height[contourNum] / 2) {
		return true;
	}
	return false;
}

char Sighting::contourOrientation(int contourNum) {
	if (angle[contourNum] > 90 && angle[contourNum] < 120) {
		return 'r';
	} else if (angle[contourNum] < 90 && angle[contourNum] > 60) {
		return 'l';
	} else {
		return 'n';
	}
}

std::vector<Sighting::Group> Sighting::groupContours() {
	//Created so we can actually return values
	std::vector<Sighting::Group> returnGroups;
	//Indices of all of the contours on the left side of a target
  	std::vector<int> leftSideContours;
  	std::vector<int> rightSideContours;
	//Used to store the group to be pushed onto the vector to be returned
	Group currentGroup;
	  
 	for (int i = 0; i < centerX.size(); i++) {
		char currentContourOrientation = contourOrientation(i);
		//Pushes contour number onto vector based off of its side that it is on the target
		if (currentContourOrientation == 'l') {
			leftSideContours.push_back(i);
	 	} else if (currentContourOrientation == 'r') {
			rightSideContours.push_back(i);
	  	}
	}

	for (int r = 0; r < rightSideContours.size(); r++) {
		//The values assigned to the first two variables are almost arbritary.
		//Distance starts off high and searches for lower numbers
		//The contour number variable must start off at some value so an arbritary is selected
		int closestContourNum = -1;
		double distanceFromClosestContour = (int) xres;
		for (int l = 0; l < leftSideContours.size(); l++) {
			//Checking to make sure that the x position of the right contour is greater than the left contour postition
			if (centerX[rightSideContours[r]] > centerX[leftSideContours[l]]) {
				//Does the distance formula to find distance between contours
				//The loop only accepts the closest contour that is on the correct side of the right contour
				double distanceFromOtherContour = sqrt(pow(centerX[rightSideContours[r]] - centerX[leftSideContours[l]], 2.0) + pow(centerY[rightSideContours[r]] - centerY[leftSideContours[l]], 2.0));
				//If new distance is less than set the closestContourNum variable
				if (distanceFromOtherContour < distanceFromClosestContour) {
					distanceFromClosestContour = distanceFromOtherContour;
					closestContourNum = leftSideContours[l];
				}
			}
		}
		//Writes to group than pushes it onto the vector
		if (closestContourNum >= 0) {
			currentGroup.leftContourNum = closestContourNum;
			currentGroup.rightContourNum = r;
			returnGroups.push_back(currentGroup);
			closestContourNum = -1;
		}
	}
	return returnGroups;	
}

void Sighting::findClosestGroup(std::vector<Sighting::Group> Groups) {
	for (int i = 0; i < Groups.size(); i++){
		if (i == 0 || height[Groups[i].leftContourNum] + height[Groups[i].rightContourNum] > height[selectedGroupTarget.leftContourNum] + height[selectedGroupTarget.rightContourNum]) {
			selectedGroupTarget = Groups[i];
		}		
	}
}
