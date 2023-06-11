// NOLINTBEGIN
#include "readers_util.h"

LimitReader::LimitReader(std::unique_ptr<Reader> reader, size_t limit) : reader_(std::move(reader)), limit_(limit) {
}

size_t LimitReader::Read(char *buf, size_t len) {
    size_t max_read = std::min(len, limit_);
    size_t ret = reader_->Read(buf, max_read);
    limit_ -= ret;
    return ret;
}

TeeReader::TeeReader(std::vector<std::unique_ptr<Reader>> readers) : readers_(std::move(readers)) {
}
size_t TeeReader::Read(char *buf, size_t len) {
    while (true) {
        if (current_ == readers_.size()) {
            return 0;
        }
        size_t ret = readers_[current_]->Read(buf, len);
        if (ret == 0) {
            ++current_;
            continue;
        }
        return ret;
    }
}

HexDecodingReader::HexDecodingReader(std::unique_ptr<Reader> reader) : reader_(std::move(reader)) {
}
char Hex2Num(char c) {
    if ('0' <= c && c <= '9') {
        return (c - '0');
    } else {
        return (c - 'A' + 10);
    }
}
size_t HexDecodingReader::Read(char *buf, size_t len) {
    std::string raw(len + 2, '\0');
    size_t read_len = reader_->Read(&(raw[0]), raw.size());
    for (size_t i = 0; i < read_len; i += 2) {
        buf[i / 2] = (Hex2Num(raw[i])) << 4 | Hex2Num(raw[i + 1]);
    }
    return read_len / 2;
}
// NOLINTEND