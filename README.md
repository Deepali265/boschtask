[README.md](https://github.com/Deepali265/boschtask/files/7026112/README.md)
# boschtask
Consider a 3 X 3 input matrix {3, 0, 1, 1, 0, 1, 1, 0, 1, 0}
0 1 1       0 1 1
0 1 1  -->  0 1 2
0 1 0       0 1 0
The input vector analysed as a matrix of 3 X 3 as shown above on the left hand side, on transition using the algorithm below results in the matrix on the right hand side.


1. Elements of first row and column of the input matrix are kept as it is as they cannot form a square matrix by themselves.

2. Elements starting at (1,1), (1,2), (2,1) and (2,2) are computed as expained in the next step 
3. If the element at any of the positions above are '1' then it can form a square matrix if the elements on the top, left and top left corner are '1'
   Example : TL T
             L  1 
4. Therefore in the transition matrix the values (1,1), (1,2), (2,1) and (2,2) are computed as --> min(TL, T, L)+ 1 
5. If the element in the input matrix is '0' then it is kept as it is, because a '0' in the right bottom corner cannot form sub squarematrix
6. Highest value in the matrix is the size of the largest sub square matrix.
