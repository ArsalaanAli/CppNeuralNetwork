#include <iostream>

#include "LoadImages.h"
#include "NeuralNetwork.h"

using namespace std;

int main() {
    // load images
    vector<vector<float>> images;
    LoadImages loader;
    loader.loadAndTransformIdxImages("dataset/t10k-images.idx3-ubyte", images);

    // test input (1 image)
    vector<float> input = images[0];
    vector<int> hiddenLayers = {256, 128, 64};
    int outputSize = 10;
    NeuralNetwork network(input, hiddenLayers, outputSize);
    cout << "initiated neural network" << endl;

    return 0;
}