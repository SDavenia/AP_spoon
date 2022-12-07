## Lecture 1
### Name at least 5 variable types in c++
Here are some variable types in c++:
 - int
 - float
 - double
 - char
 - std::string (inside header cstring)

### What is int overflow
int overflow occurs when we try to store in a variable of type integer a value that is larger than the allowed one.

### Why using namespace std might not be a good idea
It is not a good idea because for complex programs it can create conflicts when we have multiple header files.

### Which header do you have to include for access to std::cout?
You have to include the iostream header.

### What would the simplest legal program be in c++?
int main(){
}

### What is the difference between struct and class in c++?
Both are used to define classes. The difference is that by default all struct member attributes are pubblic, while those of class are private.

### What does break statement do in a loop?
It exits the loop

### What does continue statement do in a loop?
It exits the current interation of the loop and moves to the next one.

### How do you define a static array of type int and size 7?
int arr[7];

### What can you use to read interactive input
You can use the std::cin function contained in the iostream header. We have to use it in conjuction with the extraction operator >>.

## Lecture 2
### What is a reference.
A reference value is an alias, i.e. another name for an existing variable. It has to be initialized when defined using the type& name{value} syntax.

### What is a difference between passing variables to functions by reference and by value.
When we pass variables to functions by value we actually use a dummy (a copy) of that variable inside the scope of that function, which stops existing when we exit the function. On the contrary if we pass a variable by referece we are working with the same object as outside the function scope.

### If a functions accepts pointers (signature is int function(int* a)), how do you pass a variable defined as int x to it?
We need to pass the address to that variable to the function:
auto function(&x).

### Why do we want to use the const modifier whenever possible?
There are many reasons to use the const modifier when we do not want to alter the variable.
 - To avoid mistakes where we accidentally modify the variable
 - Suppose we want to pass an object by reference because it is to large to a function, but we want it unaltered (would have to pass by value). We can then pass it by const reference, which ensures that we do not create a copy of the object (and hence no memory waste) but also ensures we do not risk modifying it inside the function.

### If you have a pointer named p, how do you access the value it points to?
We need to de-reference the pointer explicitly, by using the dereferencing operator *.

### What value is stored in the pointer variable itself?
The pointer variable contains the address of the variable it points to.

### What can you say about a function that has signature void function()?
It is a function that does not return anything, so it could be a print function or a function which modifies an object.

### What is an auto keyword?
auto can be specified when we assign to a variable the output of a function. It will implicitly be converted to the return type of that function.

### What is function overloading?
Function overloading occurs when we specify functions with the same name but different return type or different number / type of parameters.

### What is a recursive function?
A recursive function is a function that calls itself inside its body.

### What is the role of a constructor in a class?
The aim of a constructor is to initialize the member variables of that class.

### How can we change private member variables of a class?
We can change private member variables of a class by defining a member function of that class which alters them.

## Lecture 3
### How do you create an object file with g++
To create an object file you use g++ -c filename.cpp

### Why can't you just have everything in one file
Because it makes the code confusing, especially for large projects

### What is the purpose of a header guard?
The purpose of a header guard is to avoid multiple inclusions when using header files. If a function is included more than once then this results into an error. This can occur when we have multiple header files with dependencies.

### What does -IFOLDER_NAME mean when passed to g++
It tells the compiler to look for header files in the folder named FOLDER_NAME

### Do tabs matter in a Makefile?
Yes they do as the commands in a rule MUST BE specified after a TAB.

### What does $@ mean in a makefile
It evaluates to the name of the current target

### What does $^ mean in a makefile
It evaluates to the names of all the prerequisites in the current rule, separated by a space.

### How to use make with a makefile that is not named Makefile.
You need to add the additional flag --file=MyMakefileName when you call make.

### What does it mean if a function is a friend of a class?
It means that the function can access the private members of objects of that class, just like any member function would.

### Why should non-class member operator be friends of classes?
Because they need to be able to access the private members varianbles

### Which header do you need to include to work with files?
You need to include the fstream header from the standard library.

### How do you open a file in append mode
To open a file test.txt in append mode you need to open it using
filevar.open("test.txt", std::ios_base::app);