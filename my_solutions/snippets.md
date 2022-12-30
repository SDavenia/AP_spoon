### Snippet 1
if x==0:
print('x is zero')
elif x>0:
print('x is greater then zero')
elif x<0:
print('x is smaller than zero')

The problem here is that there is no indentation and python requires it to run the cells.

if x==0:
    print('x is zero')
elif x>0:
    print('x is greater than zero')
elif x<0:
    print('x is smaller than zero')


### Snippet 2
t = tuple(range(10))
t[5]=100
print(t[5])

The problem here is that tuples are immutable objects, so it is wrong to try and alter an element.\
To do that we can use lists for example

t = list(range(10))
t[5]=100
print(t[5])

### Snippet 3
class MySecondClass:
    def __init__(number):
        self.number = number
a=MySecondClass(4)

The problem here is that we have not passed `self` as an argument to the `__init__` function, which is mandatory.
class MySecondClass:
    def __init__(self, number):
        self.number = number
a=MySecondClass(4)
