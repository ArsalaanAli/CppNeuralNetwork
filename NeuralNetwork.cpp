#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class NeuralNetwork {
    /*
    1. Input Layer with N input nodes
    2. Output Layer with O output nodes
    3. Hidden Layers with specified number of nodes
    */
   public:
    NeuralNetwork(vector<double> input, vector<int> hiddenLayerSizes, int outputSize) {
        this->input = input;
        this->inputSize = input.size();
        this->hiddenLayerSizes = hiddenLayerSizes;
        this->outputSize = outputSize;

        initializeLayers();

        initializeWeights();

        initializeBiases();

        initializeActivations();
    }

    void forwardPropagation() {
        for (int l = 1; l < layers.size(); l++) {
            for (int j = 0; j < layers[l].size(); j++) {
                layers[l][j] = weightedSum(l, j);
                activations[l][j] = ReLU(layers[l][j]);
            }
        }
    }

   private:
    vector<double> input;
    int inputSize;
    vector<int> hiddenLayerSizes;
    int outputSize;
    vector<vector<double>> layers;
    vector<vector<vector<double>>> weights;
    vector<vector<double>> biases;
    vector<vector<double>> activations;

    // weighted sum of jth neuron in lth layer
    double weightedSum(int l, int j) {
        double weightedSum = 0;
        for (int i = 0; i < weights[l].size(); i++) {
            double weight = weights[l][i][j] * activations[l - 1][i];
            weightedSum += weight;
        }
        weightedSum += biases[l][j];
        return weightedSum;
    }

    double ReLU(double z) {
        return max(0.0, z);
    }

    double heInitialization(int prevLayerSize) {
        double randVal = (rand() / double(RAND_MAX)) * 2 - 1;
        return randVal * sqrt(2.0 / prevLayerSize);
    }

    void initializeWeights() {
        weights.push_back({{}});
        for (int l = 1; l < layers.size(); l++) {
            vector<vector<double>> tempUpper;
            for (int i = 0; i < layers[l].size(); i++) {
                vector<double> tempLower;
                for (int j = 0; j < layers[l - 1].size(); j++) {
                    tempLower.push_back(heInitialization(layers[l - 1].size()));
                }
                tempUpper.push_back(tempLower);
            }
            weights.push_back(tempUpper);
        }
    }

    void initializeBiases() {
        for (int i = 0; i < layers.size(); i++) {
            biases.push_back(vector<double>(layers[i].size(), 0.1));
        }
    }

    void initializeActivations() {
        activations.push_back(input);
        for (int i = 1; i < layers.size(); i++) {
            activations.push_back(vector<double>(layers[i].size()));
        }
    }

    void initializeLayers() {
        layers.push_back(vector<double>(input));
        for (int layerSize : hiddenLayerSizes) {
            layers.push_back(vector<double>(layerSize));
        }
        layers.push_back(vector<double>(outputSize));
    }
};