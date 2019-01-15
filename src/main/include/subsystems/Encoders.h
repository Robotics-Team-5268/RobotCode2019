#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

class Encoders : public frc::Subsystem {
 private:
 
 public:
  double getCount() const;
	double getRaw() const;
	double getDistance() const;
	double getRate() const; //const keyword is placed afterwards so that the accessor method will be checked to make sure it doesn't modify variable values.
	double getDirection() const;
	double getStopped() const;
	void reset() const;
	Encoders(std::string shortName, unsigned int channelA, unsigned int channelB, bool reverseDirection);
  Encoders();
  void InitDefaultCommand() override;
  private:
  const double MAX_PERIOD = .1;
	const double MIN_RATE = .05;
	const double PULSE = 0.06545;// in cm
	const double SAMPLES_TO_AVE = 7;
	frc::Encoder *encoder;
};
