#include "LoadImages.h"

#include <fstream>
#include <iostream>

LoadImages::LoadImages() {
}

void LoadImages::loadAndTransformIdxImages(const std::string& filename, std::vector<std::vector<float>>& images) {
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    uint32_t magic_number, num_images, num_rows, num_cols;
    file.read(reinterpret_cast<char*>(&magic_number), 4);
    file.read(reinterpret_cast<char*>(&num_images), 4);
    file.read(reinterpret_cast<char*>(&num_rows), 4);
    file.read(reinterpret_cast<char*>(&num_cols), 4);

    // Convert to little-endian
    magic_number = __builtin_bswap32(magic_number);
    num_images = __builtin_bswap32(num_images);
    num_rows = __builtin_bswap32(num_rows);
    num_cols = __builtin_bswap32(num_cols);

    if (num_rows != 28 || num_cols != 28) {
        std::cerr << "Invalid image size, expected 28x28 but got " << num_rows << "x" << num_cols << std::endl;
        return;
    }

    images.resize(num_images);
    std::vector<uint8_t> pixels(784);

    for (uint32_t img_idx = 0; img_idx < num_images; ++img_idx) {
        file.read(reinterpret_cast<char*>(pixels.data()), 784);

        images[img_idx].resize(784);
        for (int i = 0; i < 784; ++i) {
            images[img_idx][i] = static_cast<float>(pixels[i]) / 255.0f;
        }
    }

    file.close();
}
