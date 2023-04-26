#include "Include4Turret.h"
using namespace frc;
using namespace nt;
frc::Joystick Pilot_Controller{0}; 

void Robot::TeleopPeriodic() 
{

  double y = Pilot_Controller.GetRawAxis(1);
  double s = Pilot_Controller.GetRawAxis(4);
 
  LeftFrontMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -y + s);
  LeftBackMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -y + s);
  RightFrontMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, y + s);
  RightBackMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, y + s);

  double tx = table->GetNumber("tx",0.0); 
  double ty = table->GetNumber("ty",0.0);
  double ta = table->GetNumber("ta",0.0);
  double tv = table->GetNumber("tv",0.0);
 
  if (tv >= 1 )
  {
    if ((tx > 1.0) || (tx < -1.0))
    {
     TurretLeftMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.02*tx); 
     TurretRightMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,-0.02*tx );
    }

    else if ((tx > -1.0) && (tx < 1.0))
    {
     TurretLeftMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0 ); 
     TurretRightMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0 );
    
    }
  }
  
  else if (tv = 0)
  {
    TurretLeftMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0 );
    TurretRightMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0 );
  }

  else
  {
    TurretLeftMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0 );
    TurretRightMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0 );
  }
  
}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif