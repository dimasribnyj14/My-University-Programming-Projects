# C++ Lab Tasks

This repository contains materials and solutions for laboratory work on **C++** programming.
These materials were taken from documents with laboratory work, which belong to [Dnipro University of Technology](https://nmu.org.ua/).

![Screenshot of their logo](https://www.uni-bamberg.de/fileadmin/_processed_/3/0/csm_Logo_angl_goriz_cvet_08cabe7a30.webp)
---

## Lab Work #1: Data Types and Basic Algorithmic Operations

### Theoretical Foundations

The foundation of any program is the manipulation of variable values. Most programs come down to performing arithmetic, logical, or bitwise operations. C++ allows for the calculation of values with the ability to input initial values and get results almost instantly. Variables are not only needed for calculations but also for storing values in memory, and no program can do without them.

---

## Lab Work #2: Program Branching Based on Conditional Operators

### Theoretical Foundations

Just like in real life, a program might encounter a situation where the choice made depends on some event, and this choice determines the further path of calculations. In programming, such situations are called **branching**. Branching is one of the most important features of programming, allowing for different results depending on a given condition.

For this lab, you should learn to apply three methods of branching:
* **`if`** statements 
* **`switch`** statements 
* The **ternary operator** 

---

## Lab Work #3: Cyclic actions in programs

### Theoretical Foundations

Loops are an essential part of programming because they allow the same actions or operations to be performed multiple times.
In C++, looping is implemented using three main operators:
* **`for`** loop
* **`while`** loop
* **`do-while`** loop

---

## Lab Work #4: Arrays

### Theoretical Foundations

An array is a collection of logically related elements of the same type, stored sequentially in memory under one common name. This allows access to each element using an index.

Types of arrays in C++ include:
* **One-dimensional arrays**
* **Character arrays (strings)**
* **Multidimensional arrays**

---

## Lab Work #5: Functions

### Theoretical Foundations

**Function** – a named sequence of statements that performs a specific task.
It consists of a **prototype** and a **body**.

**Function prototype:** ***`ReturnType FunctionName(ParameterList);`***

**Example of the function:**
```cpp
double max(double a, double b);
void checkValue(int value);
```

If the function should return a value, it must include a `return` statement with a value.
However, **void** functions do not return a value and are called as independent statements.

**Recursive functions** are those that call themselves directly or indirectly.
Recursion simplifies some problems but may increase memory usage.

---

## Lab Work #6: Structures

### Theoretical Foundations

**Structure** – a composite object that contains elements of any type except functions. 
Unlike an array, these **elements** can store data of **different** types.

**Function prototype:** ***`struct [type] { type_1 item_1; type_2 item_2; };`***

**Example of the function:**
```cpp
struct student {
    char fio[30];
    long int num_zac;
    double sr_bal;
};
```

---

## Lab Work #7: Dynamic Memory Allocation

### Theoretical Foundations

**Dynamic memory allocation** – a method of requesting memory from the OS's heap at runtime as needed by the program, rather than using the **limited stack memory**.
Access to structure fields is performed using selection operations: `.` when referring to a field via a structure name and `->` when referring via a pointer.

For variables of the same structural type, the assignment operation is available **(element-by-element copying occurs)**. 
In addition, the structure can be passed to a **function** and returned as its value.

**Syntax:** ***`type *pointer = new type;`***

**Example:**
```cpp
int *ptr = new int(7); 
*ptr = 8; 
delete ptr; 
ptr = nullptr;
```

---

## Lab Work #8: OOP

### Theoretical Foundations

**Traditional** – functions operate on **separate data**.
**OOP** – combines **data and functions** into reusable objects.

**Class** - a custom data type grouping **data and methods**. Functionally identical to `struct`.
**Object** - an instance of a **class**.

**Access Modifiers**
* `public`: Accessible anywhere.
* `private`: Accessible only within the class.
* `protected`: Accessible only to friend and child classes.

**Example:**
```cpp
class DateClass { // Custom type
public:           // Access modifier
    int m_day;    // Property/data
    void print(); // Method
};
```

---

## Lab Work #9: Inheritance in C++

### Theoretical Foundations

**Inheritance** – a relationship between classes representing an *"is-a"* relationship.

**Parent class** – the class being inherited from.
**Child class** – the class that inherits.

**Core Rules:**
* **A child class inherits** both behavior and properties **from the parent class**, subject to access restrictions.
* These inherited **methods and variables become members of the child class**.
* Since child classes are complete classes, they **can also have their own unique members**.
* A class can simultaneously **act as a child and a parent**.

**Example:**
```cpp
#include <iostream>
using namespace std;

// Parent class
class Person {
public:
    void sayHello() {
        cout << "Hello!" << endl;
    }
};

// Child class
class Student : public Person {
};

int main() {
    Student s;
    s.sayHello(); // inherited method

    return 0;
}
```

---

## Lab Work #10: Constructors and Destructor

### Theoretical Foundations

**Constructor** – a special class method automatically called when an **object is created** and it's used to **initialize class data**.
**Destructor** – a special class method automatically called when an **object is destroyed** and it's used to **free resources or memory**.

**Constructor Rules:**
* Same name as the class.
* No return type.
* Can have parameters.

**Destructor Rules:**
* Same name as the class with ~.
* No parameters.
* No return type.
* Only one destructor per class.

**Example:**
```cpp
class Example {
public:
    Example() {        // Default constructor
        cout << "Object created\n";
    }

    Example(int x) {   // Constructor with parameter
        cout << "Object created with value\n";
    }

    ~Example() {       // Destructor
        cout << "Object destroyed\n";
    }
};
```
