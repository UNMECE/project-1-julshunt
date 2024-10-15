// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem Solving
// Project 1: (Calculating Voltage and Current across a capacitor as a function of time)
// FileName: "firstProject.cpp"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "capacitor.h"

using namespace std;

// function Declerations 
void initializeVariables (capacitor *cap, int steps, double timeStep);
void solveConstantCurrent (capacitor *cap, double constantCurrent, double timeStep, int steps);
void solveConstantVoltage (capacitor *cap, double constantVoltage, double resistance, double timeStep, int steps);
void displayResults (capacitor *cap, int steps, bool showVoltage = true);

// main function 
int main() {

	// Variable Declerations
	capacitor info;
	info.C = 100 * pow(10, -12); // capacitance in Farrads (100 picofarrads)
	double constantCurrent = 0.01; // in amps
	double constantVoltage = 10.00; // in volts 
	double resistance = 1000; // in ohms
	double timeStep = 1 * pow(10, -10); // in seconds
	double finalTime = 5 * pow(10, -6); // in seconds
	int steps = finalTime/timeStep; // number of timesteps
	
		
	// Allocating memory for capacitor & initializing the variables
	initializeVariables(&info, steps, timeStep);
	
	//solve for contstant current source 
	solveConstantCurrent(&info, constantCurrent, timeStep, steps);
	cout << "Results for conststant current charging: " << endl;
	displayResults(&info, steps); 
	
	initializeVariables(&info, steps, timeStep);
	
	// solve for constance voltage source 
	solveConstantVoltage(&info, constantVoltage, resistance, timeStep, steps);
	cout << "\n Results for constant voltage charging are " << endl;
	displayResults(&info, steps, false);
	
	//freeing previously allocated memory 
	free (info.Time);
	free (info.Voltage);
	free (info.Current);
	
	return 0;
	
}

void initializeVariables(capacitor *cap, int steps, double timesteps) {
 
	//allocating memory 
	cap->Time = (double*)malloc(steps * sizeof(double));
	cap->Voltage = (double*)malloc(steps * sizeof(double));
	cap->Current = (double*)malloc(steps * sizeof(double));
	
	// initializing arrays 
	for (int i = 0; i < steps; ++i) {
	cap->Time[i] = i * timesteps;
	cap->Voltage[i] = 0.0;
	cap->Current[i] = 0.0;
		}
}

void solveConstantCurrent(capacitor *cap, double constantCurrent, double timeStep, int steps) {

	for (int t = 1; t < steps; ++t) {
	
	cap->Voltage[t] = cap->Voltage[t - 1] + (constantCurrent * timeStep ) / (cap->C); 
	
	}	
}

void solveConstantVoltage(capacitor *cap, double finalTime, double resistance, double timeStep, int steps) {
	
	// initializing current at t=0
	cap->Current[0] = (finalTime/resistance);
	
	for (int t = 1; t < steps; ++t) {
	
	cap->Current[t] = cap->Current[t - 1] - (cap->Current[t - 1] * timeStep) / (resistance * cap->C);
	}
}

void displayResults(capacitor *cap, int steps, bool showVoltage) {
	for (int t = 0; t < steps; t += 200) {
		if(showVoltage) {
			cout << "Time: " << cap->Time[t] << " s, Voltage: " << cap->Voltage[t] << " V" << endl;
		} else { 
			cout << "Time: " << cap->Time[t] << " s, Voltage: " << cap->Voltage[t] << " V" << endl;
			} 
		}
	}
