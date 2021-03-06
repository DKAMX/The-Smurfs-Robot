/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  leftrear.Follow(leftfront);
  rightrear.Follow(rightfront);
  basedrive.SetExpiration(0.1);

  cs::UsbCamera baseeye = frc::CameraServer::GetInstance()->StartAutomaticCapture();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }

  gyro.SetFusedHeading(0);
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }

  /*double angle = 90;
  while (gyro.GetFusedHeading() <= angle) {
    double diff = gyro.GetFusedHeading() - angle;
    double turn = diff * 0.0125;
    basedrive.ArcadeDrive(0.0, turn);
  }*/
  basedrive.ArcadeDrive(0.0, gyro.GetFusedHeading() * 0.01);
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  double rate = 0.7;
  basedrive.ArcadeDrive(-f310.GetRawAxis(1) * rate, (f310.GetRawAxis(3) - f310.GetRawAxis(2)) * rate);
  /*if (g29.GetRawButton(5)) {
    double power = 0.8;
    basedrive.ArcadeDrive(power, g29.GetRawAxis(0));
  } else if (g29.GetRawButton(6)) {
    double power = -0.8;
    basedrive.ArcadeDrive(power, g29.GetRawAxis(0));
  } else {
    double power = 0;
    basedrive.ArcadeDrive(power, g29.GetRawAxis(0));
  }*/
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
