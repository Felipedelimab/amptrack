#include <emscripten/bind.h>
#include <string>
#include <vector>

using namespace emscripten;

class Device {
private:
    std::string name;
    double resistance;

public:
    Device(std::string n, double r) : name(n), resistance(r) {}
    std::string getName() const { return name; }
    double calculatePower(double voltage) const {
        return (resistance <= 0) ? 0 : voltage * (voltage / resistance);
    }
    double calculateCurrent(double voltage) const {
        return (resistance <= 0) ? 0 : voltage / resistance;
    }
};

class Circuit {
private:
    double voltage;
    double maxCurrent;
    std::vector<Device> devices;

public:
    Circuit(double initialVoltage, double maxI) : voltage(initialVoltage), maxCurrent(maxI) {}
    
    // Passamos o dispositivo por valor para facilitar a interação com JavaScript no início
    void addDevice(Device d) { devices.push_back(d); }
    void setVoltage(double v) { voltage = v; }
    
    double getTotalPower() const {
        double totalPower = 0;
        for (const auto& device : devices) totalPower += device.calculatePower(voltage);
        return totalPower;
    }

    double getTotalCurrent() const {
        double totalCurrent = 0;
        for (const auto& device : devices) totalCurrent += device.calculateCurrent(voltage);
        return totalCurrent;
    }
};

// Aqui é onde a mágica acontece: expondo para o JavaScript!
EMSCRIPTEN_BINDINGS(my_module) {
    class_<Device>("Device")
        .constructor<std::string, double>()
        .function("getName", &Device::getName)
        .function("calculatePower", &Device::calculatePower)
        .function("calculateCurrent", &Device::calculateCurrent);

    class_<Circuit>("Circuit")
        .constructor<double, double>()
        .function("addDevice", &Circuit::addDevice)
        .function("setVoltage", &Circuit::setVoltage)
        .function("getTotalPower", &Circuit::getTotalPower)
        .function("getTotalCurrent", &Circuit::getTotalCurrent);
}