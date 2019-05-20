import sys

import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm
from scipy import io

mnist_data = io.loadmat("C://Users//a2001//Desktop//STEM//Computer Science//CS189 Intro to ML//homework//hw1//problems//data//mnist_data.mat")
mnist_parsed = mnist_data["training_data"][:10000]
mnist_data = mnist_data["training_data"][10000:]

spam_data = io.loadmat("C://Users//a2001//Desktop//STEM//Computer Science//CS189 Intro to ML//homework//hw1//problems//data//spam_data.mat")
spam_20p = int(0.2*spam_data["training_data"].shape[0])
spam_parsed = spam_data["training_data"][:spam_20p]
spam_data = spam_data["training_data"][spam_20p:]

cifar10_data = io.loadmat("C://Users//a2001//Desktop//STEM//Computer Science//CS189 Intro to ML//homework//hw1//problems//data//cifar10_data.mat")
np.random.shuffle(cifar10_data["training_data"])
cifar10_parsed = cifar10_data["training_data"][:5000]
cifar10_data = cifar10_data["training_data"][5000:]
