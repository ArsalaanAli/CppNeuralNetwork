#include <iostream>

#include "NeuralNetwork.h"

using namespace std;

int main() {
    int inputSize = 784;
    vector<int> hiddenLayers = {256, 128, 64};
    int outputSize = 10;
    NeuralNetwork nn(inputSize, hiddenLayers, outputSize);

    cout << "initiated neural network" << endl;
    return 0;
}