#include "volume_class.hpp"

// Exercise added to CMake executable files

int AudioPlayer::volume() const { return volume_; }
char AudioPlayer::buffer() const { return *buffer_; }

AudioPlayer &AudioPlayer::operator=(const AudioPlayer &other) {
    if (&other == this) return *this;

    volume_ = other.volume_;
    *buffer_ = *other.buffer_;
    return *this;
}

AudioPlayer::~AudioPlayer() { delete[] buffer_; }

bool AudioPlayer::set_volume(const int volume) {
    if (volume < 0 || volume > 100) return false;
    if (volume == volume_) return true;

    volume_ = volume;
    return true;
}

void AudioPlayer::max_volume() { volume_ = 100; }

void AudioPlayer::mute() { volume_ = 0; }