///Gavin Abeele - gabeele2160@conestogac.on.ca
/// July 10th, 2022
/// Version 1.0
///
/// Single and Multilayered Perceptron neural network class
///

#include "mlp.h"

///
/// \brief frand generates weights for each perceptron
/// \return A random double value
///
double frand() {
    return (2.0 * (double)rand() / RAND_MAX) - 1.0;
}
///
/// \brief Perceptron::Perceptron Builds a perception object
/// \param inputs Specific number of inputs to the perception
/// \param bias Allows for a bias wight to be added to the perception
///
Perceptron::Perceptron(int inputs, double bias) {
    this->bias = bias;
    weights.resize(inputs + 1);
    generate(weights.begin(), weights.end(), frand);
}

///
/// \brief Perceptron::run Runs the perceptron algoritm
/// \param x The vector or inputs
/// \return The sigmoid result of the sum of weights
///
double Perceptron::run(vector<double> x) {
    x.push_back(bias);
    double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
    return sigmoid(sum);
}

///
/// \brief Perceptron::set_weights Sents the weights of a perception
/// \param w_init
///
void Perceptron::set_weights(vector<double> w_init) {
    weights = w_init;
}

///
/// \brief Perceptron::sigmoid Calculates the Sigmoid
/// \param x The sum of weights in the perceptron
/// \return The result of the sigmoid
///
double Perceptron::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

///
/// \brief MultiLayerPerceptron::train Trains the multilayered perception
/// \param epochs The amount of Epochs to be ran
/// \return The MSE
///
double MultiLayerPerceptron::train(int epochs){
    double MSE;


    for (int i = 0; i < epochs; i++) {
           MSE = 0.0;
                           //1 2 3 4 5 6 7
           MSE += this->bp({ 1,1,1,1,1,1,0 }, { 1,0,0,0,0,0,0,0,0,0 }); //0 pattern
           MSE += this->bp({ 0,1,1,0,0,0,0 }, { 0,1,0,0,0,0,0,0,0,0 }); //1 pattern
           MSE += this->bp({ 1,1,0,1,1,0,1 }, { 0,0,1,0,0,0,0,0,0,0 }); //2 pattern
           MSE += this->bp({ 1,1,1,1,0,0,1 }, { 0,0,0,1,0,0,0,0,0,0 }); //3 pattern
           MSE += this->bp({ 0,1,1,0,0,1,1 }, { 0,0,0,0,1,0,0,0,0,0 }); //4 pattern
           MSE += this->bp({ 1,0,1,1,0,1,1 }, { 0,0,0,0,0,1,0,0,0,0 }); //5 pattern
           MSE += this->bp({ 1,0,1,1,1,1,1 }, { 0,0,0,0,0,0,1,0,0,0 }); //6 pattern
           MSE += this->bp({ 1,1,1,0,0,0,0 }, { 0,0,0,0,0,0,0,1,0,0 }); //7 pattern
           MSE += this->bp({ 1,1,1,1,1,1,1 }, { 0,0,0,0,0,0,0,0,1,0 }); //8 pattern
           MSE += this->bp({ 1,1,1,1,0,1,1 }, { 0,0,0,0,0,0,0,0,0,1 }); //9 pattern
        }


    return MSE /= 10;
}

///
/// \brief MultiLayerPerceptron::convert Converts the output vector into a index/perdicted number
/// \param input Output vector of the MLP
/// \return The index/perdicted number
///
int MultiLayerPerceptron::convert(vector<double> input){
        int i;

    for ( i = 0; i < input.size(); i++) {
            if (round(input[i]) == 1) {
                return i;
                break;
            }
        }

    return 0;
}

///
/// \brief MultiLayerPerceptron::MultiLayerPerceptron Builds a MLP
/// \param layers Number of layers of the NN
/// \param bias Bias weights of the layers
/// \param eta The learning rate
///
MultiLayerPerceptron::MultiLayerPerceptron(vector<int> layers, double bias, double eta) {
    this->layers = layers;
    this->bias = bias;
    this->eta = eta;

    for (int i = 0; i < layers.size(); i++) {
        values.push_back(vector<double>(layers[i], 0.0));
        d.push_back(vector<double>(layers[i], 0.0));
        network.push_back(vector<Perceptron>());
        if (i > 0)
            for (int j = 0; j < layers[i]; j++)
                network[i].push_back(Perceptron(layers[i - 1], bias));
    }
}


///
/// \brief MultiLayerPerceptron::set_weights Sets the wieghts of each perceptron
/// \param w_init The vector to set to.
///
void MultiLayerPerceptron::set_weights(vector<vector<vector<double> > > w_init) {
    for (int i = 0; i < w_init.size(); i++)
        for (int j = 0; j < w_init[i].size(); j++)
            network[i + 1][j].set_weights(w_init[i][j]);
}

///
/// \brief MultiLayerPerceptron::print_weights Prints the weights to the console
///
void MultiLayerPerceptron::print_weights() {
    cout << endl;
    for (int i = 1; i < network.size(); i++) {
        for (int j = 0; j < layers[i]; j++) {
            cout << "Layer " << i + 1 << " Neuron " << j << ": ";
            for (auto& it : network[i][j].weights)
                cout << it << "   ";
            cout << endl;
        }
    }
    cout << endl;
}

///
/// \brief MultiLayerPerceptron::run Runs the MLP algorithm
/// \param x Input vectors
/// \return The output value
///
vector<double> MultiLayerPerceptron::run(vector<double> x) {
    values[0] = x;
    for (int i = 1; i < network.size(); i++)
        for (int j = 0; j < layers[i]; j++)
            values[i][j] = network[i][j].run(values[i - 1]);
    return values.back();
}

///
/// \brief MultiLayerPerceptron::bp BackPropergation Algorithm is used to calculate weight updates through the network.
/// \param x Fed sample
/// \param y Expected sample set output
/// \return The MSE
///
double MultiLayerPerceptron::bp(vector<double> x, vector<double> y) {


    // STEP 1: Feed a sample to the network
    vector<double> outputs = run(x);

    // STEP 2: Calculate the MSE
    vector<double> error;
    double MSE = 0.0;
    for (int i = 0; i < y.size(); i++) {
        error.push_back(y[i] - outputs[i]);
        MSE += error[i] * error[i];
    }
    MSE /= layers.back();

    // STEP 3: Calculate the output error terms
    for (int i = 0; i < outputs.size(); i++)
        d.back()[i] = outputs[i] * (1 - outputs[i]) * (error[i]);

    // STEP 4: Calculate the error term of each unit on each layer
    for (int i = network.size() - 2; i > 0; i--)
        for (int h = 0; h < network[i].size(); h++) {
            double fwd_error = 0.0;
            for (int k = 0; k < layers[i + 1]; k++)
                fwd_error += network[i + 1][k].weights[h] * d[i + 1][k];
            d[i][h] = values[i][h] * (1 - values[i][h]) * fwd_error;
        }

    // STEPS 5 & 6: Calculate the deltas and update the weights
    for (int i = 1; i < network.size(); i++)
        for (int j = 0; j < layers[i]; j++)
            for (int k = 0; k < layers[i - 1] + 1; k++) {
                double delta;
                if (k == layers[i - 1])
                    delta = eta * d[i][j] * bias;
                else
                    delta = eta * d[i][j] * values[i - 1][k];
                network[i][j].weights[k] += delta;
            }
    return MSE;
}

