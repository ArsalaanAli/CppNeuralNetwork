#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <iostream>
#include <vector>

class NeuralNetwork {
   public:
    // Constructor to initialize the neural network
    NeuralNetwork(int inputSize, std::vector<int> hiddenLayerSizes, int outputSize);

   private:
    int inputSize;                                       // Number of input nodes
    std::vector<int> hiddenLayerSizes;                   // Sizes of hidden layers
    int outputSize;                                      // Number of output nodes
    std::vector<std::vector<int>> layers;                // Neurons in each layer
    std::vector<std::vector<std::vector<int>>> weights;  // Weights between layers
    std::vector<std::vector<int>> biases;                // Biases for each layer
};

#endif  // NEURALNETWORK_H
