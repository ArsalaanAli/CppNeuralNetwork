#include <iostream>
#include <vector>

using namespace std;

class NeuralNetwork{
    /*
    1. Input Layer with N input nodes
    2. Output Layer with O output nodes
    3. Hidden Layers with specified number of nodes
    */
public:
    NeuralNetwork(int inputSize, vector<int> hiddenLayerSizes, int outputSize){
        this->inputSize = inputSize;
        this->hiddenLayerSizes = hiddenLayerSizes;
        this->outputSize = outputSize;
    }

private:
    int inputSize;
    vector<int> hiddenLayerSizes;
    int outputSize;

};