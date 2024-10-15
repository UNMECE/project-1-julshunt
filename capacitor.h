// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem Solving
// Project 1: (Calculating Voltage and Current across a capacitor as a function of time)
// FileName: "capacitor.h"


struct _capacitor {
	
	double *Time; // Time Array (in seconds)
	double *Voltage; // Voltage Array (In Volts)
	double *Current; // Current Array (In amps)
	double C; // Capacitance Value (In Farrads)
};
typedef struct _capacitor capacitor;



capacitor info;
