
#include "Settings.hpp"

using namespace std;

void Settings::init() {
    cout << "initializing device manager" << endl;
    mDeviceManager->initialiseWithDefaultDevices(0, 2);
    const juce::OwnedArray<juce::AudioIODeviceType> &deviceTypes = mDeviceManager->getAvailableDeviceTypes();
    const auto &host = *deviceTypes.begin();
    if (host == nullptr) throw runtime_error("no host found");
    host->scanForDevices();
    const juce::StringArray names = host->getDeviceNames();
    for (auto name: names) {
        cout << "device name: " << name << endl;
    }
    const auto &currentDevice = mDeviceManager->getCurrentAudioDevice();
    cout << "current audio device " << currentDevice->getName() << endl;
    cout << "is playing " << currentDevice->isPlaying() << endl;
    cout << "output channels: " << currentDevice->getActiveOutputChannels().toInteger() << endl;
}