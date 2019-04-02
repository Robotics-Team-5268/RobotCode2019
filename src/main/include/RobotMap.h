#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/SpeedController.h>
#include <frc/WPILib.h>
//for the purposes of fixing the code I will assume these are correct
//put this on the "TODO" list for when I get the robot to prep for sneak-a-peak
#define DRIVE_SPEED_CONTROLLER_FL_CHANNEL 0
#define DRIVE_SPEED_CONTROLLER_FR_CHANNEL 1
#define DRIVE_SPEED_CONTROLLER_BL_CHANNEL 2
#define DRIVE_SPEED_CONTROLLER_BR_CHANNEL 3

#define SCFL_INVERTED false
#define SCBL_INVERTED false
#define SCFR_INVERTED false
#define SCBR_INVERTED false

#define GYRO_ANALOG_PORT 0
#define ULTRASONIC 1

#define ELEVATOR_SPEED_CONTROLLER_CHANNEL 5

#define GRABBER_SPEED_CONTROLLER_R_CHANNEL 6
#define GRABBER_SPEED_CONTROLLER_L_CHANNEL 7

#define ARM_SPEED_CONTROLLER_CHANNEL 8

#define HALL_SENSOR 6

#define PCM_PORT 10 //Pnuematics Control Module 10
#define DOUBLESOLENOID_FORWARD_CHANNEL 0
#define DOUBLESOLENOID_REVERSE_CHANNEL 1

#define CLOSED_DEGREES 30
#define OPEN_DEGREES 90

#define TROLLEY_VICTOR_SPX_CAN_BUS_ID 0 //Needs to be removed later 12