# Neural Networks and Deep Learning (Chapter 1 Summary)

## Overview
This project is based on **Chapter 1** of Michael Nielsen's book, *Neural Networks and Deep Learning*, where I built a foundational understanding of neural networks, focusing on how they can learn to classify handwritten digits from the MNIST dataset. This chapter introduces the concept of artificial neural networks, explaining how they can be trained to recognize patterns, make predictions, and generalize from examples. Below is a summary of the key concepts and learnings from this chapter.

## Key Learnings

### 1. Perceptrons
- **Perceptrons** are the building blocks of neural networks. A perceptron takes several inputs, processes them by applying weights and biases, and produces a binary output based on a threshold.
- The equation for a perceptron is:
  \[
  \text{output} = 
  \begin{cases} 
  1 & \text{if } \sum w_i x_i + b > 0 \\ 
  0 & \text{otherwise} 
  \end{cases}
  \]
  where \( w_i \) are the weights, \( x_i \) are the inputs, and \( b \) is the bias.
- This helps in understanding the simplest form of a neural network: a single layer that can solve basic linear problems.

### 2. Sigmoid Neurons
- The limitation of perceptrons is that they produce binary outputs. **Sigmoid neurons** improve upon this by producing continuous outputs between 0 and 1 using the **sigmoid function**:
  \[
  \sigma(z) = \frac{1}{1 + e^{-z}}
  \]
  where \( z = \sum w_i x_i + b \).
- This allows the network to model more complex problems by introducing non-linearity.

### 3. The Architecture of Neural Networks
- Neural networks are composed of layers of neurons:
  - **Input Layer**: Receives the input features (e.g., pixel values of images).
  - **Hidden Layers**: Perform intermediate computations using weights, biases, and activation functions.
  - **Output Layer**: Produces the final predictions (e.g., digit classification in MNIST).
- Each neuron in a layer is connected to every neuron in the next layer. The network learns to map inputs to outputs by adjusting weights and biases during training.

### 4. Feedforward Neural Networks
- A **feedforward network** processes data by passing it through each layer sequentially, from the input layer to the output layer.
- In each layer, we compute the weighted sum of the inputs and apply an activation function (such as sigmoid or ReLU).
- The output from the final layer gives the network’s prediction.

### 5. Cost Function
- The **cost function** measures how well the neural network is performing by comparing its predictions to the actual labels. The **quadratic cost function** is commonly used:
  \[
  C = \frac{1}{2n} \sum (y - a)^2
  \]
  where \( y \) is the true label, \( a \) is the predicted output, and \( n \) is the number of training examples.
- The goal of training is to minimize this cost function by adjusting the weights and biases of the network.

### 6. Gradient Descent
- **Gradient descent** is an optimization algorithm used to minimize the cost function. It works by calculating the gradient (partial derivatives) of the cost function with respect to each weight and bias, and updating them in the opposite direction of the gradient:
  \[
  w = w - \eta \frac{\partial C}{\partial w}
  \]
  where \( \eta \) is the learning rate.
- By iteratively applying this update rule, the network slowly "learns" how to map inputs to outputs.

### 7. Backpropagation
- **Backpropagation** is the process of calculating the gradient of the cost function with respect to the weights and biases using the chain rule of calculus.
- It involves two steps:
  1. **Feedforward**: Compute the activations and the output.
  2. **Backward pass**: Compute the gradient of the cost function and propagate the error backward to update the weights.
- This is the key algorithm that enables neural networks to learn efficiently.

### 8. The Power of Neural Networks
- One of the main takeaways from this chapter is that neural networks have the power to model complex, non-linear functions and can learn intricate patterns in data.
- When applied to problems such as digit classification in the MNIST dataset, neural networks can generalize well from examples, providing a robust method for pattern recognition.




# Neural Network Implementation and MNIST Classification

## Neural Network from Scratch

 

### Key Details:
- **Architecture:** A fully connected neural network with ReLU activation in the hidden layer and softmax output for classification.
- **Loss Function:** Cross-entropy loss.
- **Optimizer:** Gradient descent with a learning rate of 0.1.
- **Epochs:** 100

### Results:
- **Test Accuracy:** 90.64%

## MNIST Classification with PyTorch

We re-implemented the neural network using PyTorch for comparison. PyTorch provides a more streamlined approach for building and training models.

### Key Details:
- **Architecture:** Same as the scratch implementation.
- **Loss Function:** Cross-entropy loss.
- **Optimizer:** Stochastic Gradient Descent (SGD) with a learning rate of 0.1.
- **Epochs:** 100

### Results:
- **Test Accuracy:** 96.69% 

## Comparison

### Ease of Use:
- **Scratch:** Requires manual implementation of forward and backward passes, gradient computation, and weight updates.
- **PyTorch:** Simplifies model creation and training with built-in functions and automatic differentiation.

### Performance:
- **Scratch:** Performance depends on manual optimization and might not utilize hardware acceleration efficiently.
- **PyTorch:** Provides better performance due to hardware acceleration and optimized computations.

### Flexibility:
- **Scratch:** Limited flexibility for experimenting with complex architectures.
- **PyTorch:** Offers greater flexibility for building complex models and experimenting with different architectures.

## Conclusion

Implementing a neural network from scratch provided valuable insights into the inner workings of neural networks, while using PyTorch demonstrated the advantages of modern deep learning frameworks in terms of ease of use, performance, and flexibility.




