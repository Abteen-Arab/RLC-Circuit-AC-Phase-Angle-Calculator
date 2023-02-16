#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

// Function to calculate the impedance of a component
complex<double> impedance(double frequency, double resistance, double capacitance, double inductance) {
    complex<double> j(0, 1);  // imaginary unit

    double omega = 2 * M_PI * frequency;
    complex<double> z_r(resistance, 0);
    complex<double> z_c(0, -1 / (omega * capacitance));
    complex<double> z_l(0, omega * inductance);

    return z_r + z_c + z_l;
}

int main() {
    double frequency = 1e3;  // Hz
    double resistance = 1e3;  // Ohm
    double capacitance = 1e-6;  // F
    double inductance = 1e-3;  // H

    complex<double> v_in(1, 0);  // AC source voltage

    complex<double> z = impedance(frequency, resistance, capacitance, inductance);
    complex<double> i = v_in / z;  // Current in the circuit

    // Potential at each node in the circuit
    complex<double> v_r = i * resistance;
    complex<double> v_c = i / (complex<double>(0, 1) * frequency * capacitance);
    complex<double> v_l = i * complex<double>(0, 1) * frequency * inductance;

    cout << "Potential drop across resistor: " << abs(v_r) << " V at " << arg(v_r) << " radians" << endl;
    cout << "Potential drop across capacitor: " << abs(v_c) << " V at " << arg(v_c) << " radians" << endl;
    cout << "Potential drop across inductor: " << abs(v_l) << " V at " << arg(v_l) << " radians" << endl;

    return 0;
}
