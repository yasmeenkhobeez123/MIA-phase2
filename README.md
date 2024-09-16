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




