# 7-Segment-Display-Neural-Network
This project is based on a LinkedIn Learning course which goes into depth on Neural Networks (NN). This project uses a NN to classify a 7-segment display input and outputs a predicted result. Written in C++, the NN doesn't use external libraries or frameworks outside STL. The GUI is built using QT.

![Banner](https://user-images.githubusercontent.com/59030389/178107541-488dc55c-128a-41c5-a55a-09c29b755e57.jpeg)

## Description
<p text-align="justify"><img src="https://user-images.githubusercontent.com/59030389/178108088-dea00ade-3577-46eb-a9ca-f2877b0d5179.png" width="150" align="right" />This project focuses on learning and building my skill set with Machine Learning (ML) and Neural Networks (NN). It includes C++ code to outline a basic NN using a specified amount of inputs, hidden layers, and the number of outputs. Once it is provided backpropagation, the NN will learn from the data given. The code only uses the STL making it easy, reliable, and portal. I built the UI using QT, but the code is segregated enough to use the NN files without the GUI. The project simulates a single 7-segment display; each segment panel may have its brightness. For example, the number 2 may have a segment that is 100% brightness and another than is 65% brightness. Another example is 0 on a segmented display; light may leak into the middle segment creating an 8. This NN is trained to look for patterns and similarities in the numbers. Using the GUI, users can set the brightness of each segment panel to create any numbers, and the NN will predict the number. Users can also tinker with the number of Epochs, seeing how the amount of learning will impact the final result.</p>

### Diagram
<img width="909" alt="NNwithlabels" src="https://user-images.githubusercontent.com/59030389/178115659-4f4ecc5e-937f-4387-9c94-cb7e0742c080.png">
The diagram above shows the network of inputs, neurons, and outputs. Seven inputs from each segment piece are fed into the network. The network then predicts what number is being displayed and will output a vector of 10 elements. The vector is then read to convert into a number in base 10. 

### Why Not Just Use Conditional Statements or a Decision Tree?
Conditional statements to check if the slider is on, off, or slightly on can lead to various issues. Code implementation would lead to a large conditional statement, not open for extensions, can't learn, and it is up to the developer to decide what brightness value is classified as "on ."With a NN, data is learned and can make accurate predictions even when the brightness is low or "broken". 

Building the model also allowed for ease of extension; there was no need to tinker or write new conditions if we wanted to do letters. Simply; adjust the number of layers, the number of outputs, and add the references of the letters. The NN will learn and predict!

## Getting Started
### Installing
Feel free to download the source code if you'd like to view it. For the NN, no additional frameworks are used outside of the STL built into C++. For the UI, QT must download to view and tinker. 

### Executing Program
Executing is simple and easy:
1. Download the release
2. Navigate to the Executable folder
3. Double click the SegmentDisplay_NN.exe!

![Execute](https://user-images.githubusercontent.com/59030389/178159266-214bfa3e-b7c0-4a78-bcaf-3a7b9f8e1ef3.gif)

### Using the Program
![NN gif](https://user-images.githubusercontent.com/59030389/178158415-37a08056-642f-4fdd-a50a-174dff3d90bf.gif)

The application interface is simple. Move the sliders to adjust the brightness of the segment display. Configure the number of epochs to run and see how it can affect predictions' error rate and certainty. Select the reset button to start over. On startup and reset, there are no epochs trained. 

## Authors
Contributors' names and contact info

Gavin Abeele
[@GitHub](https://github.com/Gabeele)
[@LinkedIn](https://www.linkedin.com/in/gavinabeele/)

## Version History
* 1.0
   * See [commit change]() or See [release history]()
    * Initial Release

## License
This project is licensed under the Gavin Abeele License - see the LICENSE.MD file for details

## Acknowledgments
Inspiration, code snippets, etc.
* [Learning Neural Networks in C++](https://www.linkedin.com/learning-login/share?account=2212217&forceAccount=false&redirect=https%3A%2F%2Fwww.linkedin.com%2Flearning%2Ftraining-neural-networks-in-c-plus-plus%3Ftrk%3Dshare_ent_url%26shareId%3Doik3vkn9Su2Jzx8ucTPu%252FQ%253D%253D)
* [Diagraming Tool](https://alexlenail.me/NN-SVG/index.html)
