#ifndef LOAD_IMAGES_H
#define LOAD_IMAGES_H

#include <cstdint>
#include <string>
#include <vector>

class LoadImages {
   public:
    LoadImages();
    void loadAndTransformIdxImages(const std::string& filename, std::vector<std::vector<float>>& images);
};

#endif  // LOAD_IMAGES_H
