#ifndef SRC_SUBSYSTEMS_UDPRECEIVER_H_
#define SRC_SUBSYSTEMS_UDPRECEIVER_H_

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

#include <atomic>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

class UDPReceiver : public frc::Subsystem {

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	void ThreadBody();
	std::vector<std::string> split(std::string str, std::string delimiter);
	int strToInt(std::string str);

	// The order of these is important
	// So the thread doesn't start before everything's ready
	std::atomic_bool mRun;
	std::thread mThread;
	int sockfd;
	char buffer[256]; // Don't access this outside of receive

public:
	UDPReceiver();
	virtual ~UDPReceiver();
	void InitDefaultCommand();
	int GetCount() const; // Temporary
	void GetContours( // Switch to int vectors later
			std::vector<double>& centerX_out,
			std::vector<double>& centerY_out,
			std::vector<double>& width_out,
			std::vector<double>& height_out,
			std::vector<double>& x1_out,
			std::vector<double>& y1_out, 
			std::vector<double>& x2_out, 
			std::vector<double>& y2_out, 
			std::vector<double>& angle_out);
	void AddSmartDashboardItems();
	// May become private later
	std::vector<double> centerX, centerY, height, width, x1, y1, x2, y2, angle;
};

#endif /* SRC_SUBSYSTEMS_UDPRECEIVER_H_ */