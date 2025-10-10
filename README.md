# C++ Lab Works

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
