
class Settings {
    public:
        Settings() {
            mDeviceManager = std::make_unique<juce::AudioDeviceManager>();
        }
        void init();
    private:
        std::unique_ptr<juce::AudioDeviceManager> mDeviceManager;
};