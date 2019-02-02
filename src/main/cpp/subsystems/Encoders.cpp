#include <Subsystems/Encoders.h>
#include <frc/smartDashboard/SmartDashboard.h>
#include <String>

Encoders::Encoders(std::string shortName, unsigned int channelA, unsigned int channelB, bool reverseDirection) : frc::Subsystem("Encoders") {
	encoder = new frc::Encoder(channelA, channelB, reverseDirection, frc::Encoder::EncodingType::k4X);
	encoder->Reset();
	encoder->SetMaxPeriod(MAX_PERIOD);
	encoder->SetMinRate(MIN_RATE);
	encoder->SetReverseDirection(false);
	encoder->SetDistancePerPulse(PULSE);
	encoder->SetSamplesToAverage(SAMPLES_TO_AVE);
	frc::SmartDashboard::PutNumber(shortName + "count", encoder->Get());
	frc::SmartDashboard::PutNumber(shortName + "Raw Count", encoder->GetRaw());
	frc::SmartDashboard::PutNumber(shortName + "Distance", encoder->GetDistance());
	frc::SmartDashboard::PutNumber(shortName + "Rate", encoder->GetRate());
	frc::SmartDashboard::PutBoolean(shortName + "Direction", encoder->GetDirection());
	frc::SmartDashboard::PutBoolean(shortName + "Stopped", encoder->GetStopped());
}

double Encoders::getCount() const {
	return encoder->Get();
}

double Encoders::getRaw() const {
	return encoder->GetRaw();
}

double Encoders::getDistance() const {
  return encoder->GetDistance();
}


double Encoders::getRate() const {
  return encoder->GetRate();
}

double Encoders::getDirection() const {
	return encoder->GetDirection();
}

double Encoders::getStopped() const {
  return encoder->GetStopped();
}
void Encoders::reset() const {
  encoder->Reset();
}