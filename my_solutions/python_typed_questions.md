## Python questions

### How do you create markdown cell in Jupyter? (with keyboard commands)
You need to exit the current cell (by using `esc`) and then you can enter a new Markdown cell using `m`.

### How do you delete a cell in Jupyter (with keyboard command)?
You need to exit the current cell and then type `dd` to delete a cell.

### How do you add a cell above the current one in Jupyter (with keyboard command)?
You need to exit the current cell and then type `a` to create a new cell above the current one and enter above it.

### What advantage does conda environment provide over a system-wide installation of python?
It is advantageous as it allows to have multiple environments, where one can work with different versions of python and its libraries.
This is useful because sometimes python libraries do not interact well with new version of other libraries or python, so it is useful to 
have a separate environment where one can keep old ones.

### What does it mean that variables are dynamically typed in python?
It means that there is no need to assign type to variables. As such the interpreter understand at compile time what type each variable has

### What's the difference between python and C/C++ integers?
The main difference is that python integers do not have size limit as they are not constrained by the 8-bit representation of C/C++ int.

### Explain the difference between lists, sets and tuples in python.
The three above are all data containers with some peculiarities.\
Lists are mutable (and resizable) objects while tuples are immutable and hence faster.\ 
The peculiarity of sets is that they are mutable but they are unordered and do no contain duplicates (as mathematical sets would). As such we do NOT have indexing on sets while we do on the other 2. They are mutable but can only contain immutable objects.\

### What does negative index mean when accessing list elements?
It means that we start indexing at the end. So if we have a list *l* containing n elements l[-1] is equivalent to l[n-1] which accesses the last element of l (as indexing starts at 0).

### How do you print the first N elements of a list?
You can print them in many different ways, one uses slicing as in `print(l[0:N-1])`.

### How do you print every Nth element of a list?
A possible way would be to use `print(l[ : : N])`

### How do you print the reverse list?
A possible way would use l[::-1]

### Give an example of a list comprehension.
List comprehension is a pythonic to create a new list from a rule.\
One example if we have a list l and want a list l2 containing the square of each element
`l2 = [i*i for i in l]`

### Give an example of cell and line magic commands in Jupyter.
`!` runs inline bash commands and is an example of a line magic command.
`%%timeit` is a cell magic command and times the exection of the code in the cell.

### Write a "hello world" function in python (syntax errors are not ok in hello world even on paper).
def hello_world():
    print("Hello, world!")

### What are keyword function arguments in python and what is their advantage?
keyword function argumetns are arguments of a function which have a name and can be accessed using that and not necessarily by position. They are useful as they increase code clarity with functions and make it clearer what is the role of each argument.   

### Why shouldn't you do `from numpy import *`?
Because it creates confusion between numpy and other libraries functions as you are unable to understand from which library the function that python is using comes from.

### What is the advantage of using numpy arrays over lists? What are the dangers?
Numpy arrays are generally faster than python lists. One disadvantage is that they must store the same Datatype while lists can also contain different typed objects.\
A possible danger is that we can have overflow. Moreover, the fact that they have many functions makes looking for help harder.

### What's the most widely used package for plotting in python?
matplotlib. Usually people work with matplotlib.pyplot.

### What's the purpose of `__str__` method in a python class?
Its purpose is to be invoked when `print()` or `str()` is called on an object of that class and is supposed to return the details of the object.

### What package can you use in python for symbolic calculations?
A python package that can be used for symbolic calculation is `simpy`

### What are decorators? Write an example (minor syntax errors are ok here)
Decorators are functions used to modify other functions, so that they have added functionalities without having to retype or modify an object.
For example a decorator that will modify any function by returning negative its usual return is:
```
def change_sign(func):
    def wrapper(*args, **kwargs):
        return -func(*args, **kwargs)
    return wrapper
```

### Name two ways of calling c++ code from python.
One can use `pybind` or `ctypes`.

### What is pandas? Name at least 5 functions from that package.
Pandas is a python library that is widely used for ML and Data Analysis.
 - `read_csv()` : to read csv files
 - `DataFrame()` : to create pandas dataframes
 - `Series()` : to create pandas series objects.
 - `mean()` : used to return the mean of the values for the requested axis of a dataframe
 - `groupby()` : used to group variables according to some levels to perform some further manipulation.