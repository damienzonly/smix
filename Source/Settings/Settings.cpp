
#include "Settings.hpp"

using namespace std;

void Settings::init() {
    cout << "initializing device manager" << endl;
    juce::AudioDeviceManager deviceManager;
    deviceManager.initialiseWithDefaultDevices(0, 2);
    const juce::OwnedArray<juce::AudioIODeviceType> &deviceTypes = deviceManager.getAvailableDeviceTypes();
    for (auto &deviceType: deviceTypes) {
        cout << "typename: " << deviceType->getTypeName() << endl;
        deviceType->scanForDevices();
        const juce::StringArray names = deviceType->getDeviceNames();
        for (auto name: names) {
            cout << "device name: " << name.toRawUTF8() << endl;
        }
    }
}