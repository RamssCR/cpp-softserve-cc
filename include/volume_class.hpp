#pragma once
#include <stdexcept>
#include <cstring>

class AudioPlayer {
public:
    explicit AudioPlayer(const int volume) : volume_(volume), buffer_(new char[1]{'m'}) {
        if (volume < 0 || volume > 100) throw std::out_of_range("value out of range");
    }

    AudioPlayer(const AudioPlayer& other)
    : volume_(other.volume_), buffer_(new char[std::strlen(other.buffer_)]) {
        std::strcpy(buffer_, other.buffer_);
    }

    ~AudioPlayer();

    AudioPlayer& operator=(const AudioPlayer& other);

    [[nodiscard]] int volume() const;
    [[nodiscard]] char buffer() const;

    bool set_volume(int volume);

    void max_volume();

    void mute();

private:
    int volume_ = 0;
    char* buffer_;
};