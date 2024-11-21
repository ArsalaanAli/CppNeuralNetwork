#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class NeuralNetwork {
   public:
    NeuralNetwork(vector<float> input, vector<int> hiddenLayerSizes, int outputSize);

    void forwardPropagation();

   private:
    vector<float> input;
    int inputSize;
    vector<int> hiddenLayerSizes;
    int outputSize;
    vector<vector<float>> layers;
    vector<vector<vector<float>>> weights;
    vector<vector<float>> biases;
    vector<vector<float>> activations;

    // weighted sum of jth neuron in lth layer
    float weightedSum(int l, int j);

    float ReLU(float z);

    float heInitialization(int prevLayerSize);

    void initializeWeights();

    void initializeBiases();

    void initializeActivations();

    void initializeLayers();
};

#endif  // NEURALNETWORK_H
