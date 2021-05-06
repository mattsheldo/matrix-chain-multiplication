# Matrix Chain Multiplication

Matrix multiplication is used in many algorithms but it can be an expensive operation. The code in this repository is a dynamic programming solution for finding the most efficient way of  multiplying a string of matrices of any size. Say we have a chain of matrices A, B, C, and D that we need to multiply, we want to know if (((A * B) * C) * D) is better than ((A * B) * (C * D)) before we do the multiplication because that kind of matrix multiplication is expensive. Before we acutally do the multiplication we can determine the number of steps needed to complete the multiplication which will indicate to us the cost that the multiplication will have. That is what this algorithm does it calculates the steps needed to multiply a group of 2 or more matrices so that the best order can be found before the multiplication is done.

## Simple Example

Say we have 3 matrices A, B, and C and they have the following dimensions
A = 2x10
B = 10x50
C = 50x20

Mathmatically A * (B * C) = (A * B) * C but they are very different in terms of computation

First lets look at A * (B * C)<br>
B * C requires 10,000 steps (10 * 50 * 20) These are the dimensions of the two matrices<br>
A * (B * C) requires 400 additional steps<br>
Total Steps: 10,400

Now lets look at (A * B) * C<br>
A * B requires 1,000 (2 * 10 * 50)<br>
(A * B) * C requires 2,000 additional steps<br>
Total Steps: 3,000

As you can see knowing which order is better can save an extremely large amount of resources as more matrices are being multiplied together

## Incoding the Data

### Input
The input for this algorithm will be an array that contains the deminsions of the matrices that are being multiplied because the amount of steps needed is calculated from the deminsionso f the matrices. Matrices must have a common deminsion to be multiplied so even though we are only using one array we can encode more than just the deminsions. We also can identify the Matrices by the indices of the array. This difficult to put into words so I will show an example.

![image](https://user-images.githubusercontent.com/83359136/117325112-6e8faa80-ae5e-11eb-997e-44937a952569.png)

The bottom array is the input array but from it we can infer the information in the top array.

### Output
The output is a pair of matrices we can call matrix N and matrix K. Matrix N stores the steps calculations as we compute them and eventually will contain the lowest ammount of steps in the top right courner of the matrix. Matrix K will keep track of the order used to achieve the final solution stored in matrix K. I will explain how these matrices are filled out in the next section.

## How the Algorithm Works

In this section I will be refering to the input array shown in the input section above to make things easier to understand. We first initialize our N and K matrices with 0's across the diagonal so that [0][0], [1][1], [2][2], etc. are all 0. Then we will start to calculate the steps need for multiplying each pair of matrices.

## Try it yourself!

Use Git to clone the repository and run the program. On your machine navigate to your desired folder and run the following command.

```bash
git clone https://github.com/mattsheldo/shortest-paths.git
```

Once you have the repository cloned on your machine you can run the following commands to compile and run the code.

To Compile:
```bash
g++ main.cpp Timer.cpp
```
To Run:
```bash
./a.out
```

