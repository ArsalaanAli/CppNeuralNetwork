#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(vector<float> input, vector<int> hiddenLayerSizes, int outputSize) {
    this->input = input;
    this->inputSize = input.size();
    this->hiddenLayerSizes = hiddenLayerSizes;
    this->outputSize = outputSize;

    cout << input.size() << endl;

    initializeLayers();
    initializeWeights();
    initializeBiases();
    initializeActivations();
}

void NeuralNetwork::forwardPropagation() {
    for (int l = 1; l < layers.size(); l++) {
        for (int j = 0; j < layers[l].size(); j++) {
            layers[l][j] = weightedSum(l, j);
            activations[l][j] = ReLU(layers[l][j]);
        }
    }
}

float NeuralNetwork::weightedSum(int l, int j) {
    float weightedSum = 0;
    for (int i = 0; i < weights[l].size(); i++) {
        float weight = weights[l][i][j] * activations[l - 1][i];
        weightedSum += weight;
    }
    weightedSum += biases[l][j];
    return weightedSum;
}

float NeuralNetwork::ReLU(float z) {
    return max(0.0f, z);
}

float NeuralNetwork::heInitialization(int prevLayerSize) {
    float randVal = (rand() / float(RAND_MAX)) * 2 - 1;
    return randVal * sqrt(2.0 / prevLayerSize);
}

void NeuralNetwork::initializeWeights() {
    weights.push_back({{}});
    for (int l = 1; l < layers.size(); l++) {
        vector<vector<float>> tempUpper;
        for (int i = 0; i < layers[l].size(); i++) {
            vector<float> tempLower;
            for (int j = 0; j < layers[l - 1].size(); j++) {
                tempLower.push_back(heInitialization(layers[l - 1].size()));
            }
            tempUpper.push_back(tempLower);
        }
        weights.push_back(tempUpper);
    }
}

void NeuralNetwork::initializeBiases() {
    for (int i = 0; i < layers.size(); i++) {
        biases.push_back(vector<float>(layers[i].size(), 0.1));
    }
}

void NeuralNetwork::initializeActivations() {
    activations.push_back(input);
    for (int i = 1; i < layers.size(); i++) {
        activations.push_back(vector<float>(layers[i].size()));
    }
}

void NeuralNetwork::initializeLayers() {
    layers.push_back(vector<float>(input));
    for (int layerSize : hiddenLayerSizes) {
        layers.push_back(vector<float>(layerSize));
    }
    layers.push_back(vector<float>(outputSize));
}
