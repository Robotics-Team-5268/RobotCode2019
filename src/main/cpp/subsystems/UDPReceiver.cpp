#include "RobotMap.h"
#include "CommandBase.h"

#include <sstream>
#include <errno.h>
#include <mutex> // For locking and unlocking

using namespace std;

// Constructor - sets up the socket to receive
UDPReceiver::UDPReceiver() : frc::Subsystem("UDPReceiver")
	// Initializer list - This weird syntax functions the same as:
	// mRun = true;
	, mRun(true)
	, mThread(&UDPReceiver::ThreadBody, this)
{
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in serv;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(5805);
	//serv.sin_addr.s_addr = inet_addr("10.52.68.71");

	hostent* record = gethostbyname("roboRIO-5268-FRC.local");
	in_addr* address = (in_addr*) record->h_addr;
	const char* ipaddress = inet_ntoa(*address);
	// This MUST be given an ip address, NOT a hostname
	serv.sin_addr.s_addr = inet_addr(ipaddress); // "10.52.68.71"

	bind(sockfd, (const sockaddr*) &serv, sizeof(serv));
}

void UDPReceiver::InitDefaultCommand() {
	// Set the default command for a subsystem here.
}

// Destructor (virtual is not a return type)
// To call this: delete udp;
UDPReceiver::~UDPReceiver() {
	mRun = false; // Tells thread to stop

	// Waits for the thread to stop before destructing UDPReceiver
	if (mThread.joinable()) {
		mThread.join();
	}
}

// Called by sighting with references to arrays
void UDPReceiver::GetContours(
	std::vector<double>& centerX_out,
	std::vector<double>& centerY_out,
	std::vector<double>& width_out,
	std::vector<double>& height_out,
	std::vector<double>& x1_out,
	std::vector<double>& y1_out, 
	std::vector<double>& x2_out, 
	std::vector<double>& y2_out, 
	std::vector<double>& angle_out) {

	centerX_out.assign(centerX.begin(), centerX.end());
	centerY_out.assign(centerY.begin(), centerY.end());
	width_out.assign(width.begin(), width.end());
	height_out.assign(height.begin(), height.end());
	x1_out.assign(x1.begin(), x1.end());
	x2_out.assign(x2.begin(), x2.end());
	y1_out.assign(y1.begin(), y1.end());
	y2_out.assign(y2.begin(), y2.end());
	angle_out.assign(angle.begin(), angle.end());

	// When this uses int vectors, it will be easy, ex:
	// centerX_out = centerX
}

// Runs continuously in the background
void UDPReceiver::ThreadBody() {
	while (mRun) {
		int rc = recv(sockfd, buffer, sizeof(buffer), 0);
		frc::SmartDashboard::PutBoolean("Error reading from socket", (rc < 0));

		if (rc < 0) {
			frc::SmartDashboard::PutString("Socket ErrNo", strerror(errno));
		}
		else { // No error reading from socket
			centerX.clear();
			centerY.clear();
			width.clear();
			height.clear();
			x1.clear();
			y1.clear();
			x2.clear();
			y2.clear();
			angle.clear();
			string msg = string(buffer);

			frc::SmartDashboard::PutString("Raw contours", msg);

			// Loop through all the contours
			vector<string> contours = split(msg, ";");
			for (unsigned int i = 0; i < contours.size(); i++) {

				// centerX, centerY, etc, for the current contour
				vector<string> properties = split(contours[i], ",");
				if (properties.size() >= 5) {
					centerX.push_back(strToInt(properties[0]));
					centerY.push_back(strToInt(properties[1]));
					width.push_back(strToInt(properties[2])); // Crashed here once when super close to target in teleop
					height.push_back(strToInt(properties[3]));
					x1.push_back(strToInt(properties[4]));
					y1.push_back(strToInt(properties[5]));
					x2.push_back(strToInt(properties[6]));
					y2.push_back(strToInt(properties[7]));
					angle.push_back(strToInt(properties[8]));
				}
			}
		}
	}
}

vector<string> UDPReceiver::split(string str, string delimiter) {
    vector<string> result;
    while (str.size()) {
        unsigned int index = str.find(delimiter);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + delimiter.size());
        } else {
            result.push_back(str);
            break;
        }
    }
    return result;
}

int UDPReceiver::strToInt(string str) {
	stringstream stream(str);
	int num = 0;
	stream >> num;
	return num;
}