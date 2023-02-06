#run this file with `python anim.py` from command line
#open the .gif in whatever you usually open them with to check that it worked
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def extend_matrix_naive(A):
    """
    Given a matrix surrounds it by a frame of zeros
    This could be implemented better by pasting two rows and columns instead of 
      iterating through the whole thing
    """
    nrow = len(A) # Nrows
    ncol = len(A[0]) #Ncol assuming A is not empty
    R = np.zeros((nrow + 2, ncol + 2), dtype = "int")
    for i in range(1, nrow+1):
        for j in range(1, ncol+1):
            R[i][j] = A[i-1][j-1]
    return R

def count_neighbours(A, i, j):
    count = A[i-1][j-1] + A[i-1][j] + A[i-1][j+1] + A[i][j-1] + A[i][j+1] + A[i+1][j-1] + A[i+1][j] + A[i+1][j+1]
    return count

def Conway(A, max_iter):
    """
    Given a matrix A and a number of maximum iterations it simulates Conway Game of life.
    Alive cells are denoted by 1 and dead ones are denoted by 0
    """
    # I enlarge the matrix A to be surrounded by some empty cells which will not be modified
    # First of all we add a row on top and a row at the bottom of zeroes
    nrow = len(A) # Nrows
    ncol = len(A[0]) #Ncol assuming A is not empty
    A = extend_matrix_naive(A)
    k = 0 #Number of iterations the system survives
    while(np.sum(A) != 0):
        k += 1
        A_new = A.copy()
        for i in range(1, nrow+1):
            for j in range(1, ncol+1):
                c = count_neighbours(A, i, j)
                match A[i][j]:
                    case 1: #Alive
                        if c < 2 or c > 3:
                            A_new[i][j] = 0
                    case 0: #Dead
                        if c==3:
                            A_new[i][j] = 1
        A = A_new
    plt.imshow(A)
                                     

        


fig=plt.figure()
#you can put something depending on i here
A = np.array([[1, 0, 1, 1], [0, 0, 1, 0], [0, 1, 1, 0]])
def animate(i): 
   print(i)
   Conway(A, i)
   

     
anim = animation.FuncAnimation(fig,animate,frames=np.arange(1, 3, 1), interval=10)

# save the animation as an gif
anim.save("conway.gif") 

