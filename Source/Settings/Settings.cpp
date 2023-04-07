
#include "Settings.hpp"

using namespace std;

void Settings::init() {
    cout << "initializing device manager" << endl;
    juce::AudioDeviceManager deviceManager;
    deviceManager.initialiseWithDefaultDevices(0, 2);
    const juce::OwnedArray<juce::AudioIODeviceType> &deviceTypes = deviceManager.getAvailableDeviceTypes();
    const auto &host = *deviceTypes.begin();
    host->scanForDevices();
    const juce::StringArray names = host->getDeviceNames();
    for (auto name: names) {
        cout << "device name: " << name << endl;
    }
}