#pragma once
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <frc/SerialPort.h>
#include "frc/Errors.h"
#include <frc/drive/MecanumDrive.h>
#include "cameraserver/CameraServer.h"
#include <frc/TimedRobot.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
using namespace nt;

std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

class Robot : public frc::TimedRobot 
{
 public:
  
  void TeleopPeriodic() override;

    double pilot_left_joystick_x = 0.0;
    double pilot_left_joystick_y = 0.0;
    double pilot_right_joystick_x = 0.0;    
    double pilot_right_joystick_y = 0.0;

    ctre::phoenix::motorcontrol::can::TalonSRX LeftFrontMotor{6}; 
    ctre::phoenix::motorcontrol::can::TalonSRX LeftBackMotor{5}; 
    ctre::phoenix::motorcontrol::can::TalonSRX RightFrontMotor{3}; 
    ctre::phoenix::motorcontrol::can::TalonSRX RightBackMotor{1}; 
    ctre::phoenix::motorcontrol::can::TalonSRX TurretLeftMotor{4}; 
    ctre::phoenix::motorcontrol::can::TalonSRX TurretRightMotor{2}; 
};