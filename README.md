[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/aXA4nN3s)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=12642968)
# LAB06 - Working with Smart Pointers

C++ allows the programmer to reference memory locations. While this allows you to finely tune the application's memory management, you need to know when and how to return an object's memory to the operating system. The techniques for these actions are error-prone and, if done improperly, can lead to crashed programs and security vulnerabilities. **Smart pointers** take care of these memory management details for you, the programmer.

## Background

Before proceeding with this lab, the student should take the time to read

* [C++ Interlude 4 - Safe Memory Management Using Smart Pointers](https://online.vitalsource.com/reader/books/9780134477473/epubcfi/6/216%5B%3Bvnd.vst.idref%3DP7001011925000000000000000002CE7%5D!/4/2%5BP7001011925000000000000000002CE7%5D/2/2%5BP700101192500000000000000000B108%5D/7:2%5B%2Cafe%5D)

### Smart Pointers

A **smart pointer**, or **managed pointer**, is an object that acts like a raw pointer but also provides some automatic memory management features. Memory deallocation with smart pointers occurs as soon as it can be determined that an object is no longer needed. Typically, this action happens when either the last reference to the object goes out of scope—often when a method or function ends—or the smart pointer is set to `nullptr`. As a result, some of the performance issues of garbage collection are avoided and as much unused memory as possible is made available for the application.

When you declare a smart pointer, it is placed on the application stack. When a smart pointer references an object, we say the object is **managed**. When the smart pointer goes out of scope, its destructor automatically invokes the destructor of the referenced object. Thus, when you use a smart pointer to reference an object, you do not need to use the delete operator. By design, the syntax of a smart pointer is almost like that of a raw pointer. In many cases, adapting our code to use smart pointers requires changes only to memory allocation statements.

To incorporate them into your program, you need the following directive:

```c++
#include <memory>
```

## Objective

Upon successful completion of this lab, the student has learned when, how, and where to declare and use

* unique pointers
* shared pointers
* weak pointers

In this lab we cover three of the types of smart-pointer templates available in C++:

`shared_ptr` -- Provides _shared_ ownership of an object. Several instances of this class can reference the same object. These instances, which we will call **shared pointers**, use reference counting to detect when an object is no longer reachable by a smart pointer.

`unique_ptr` -- Provides _unique ownership_ of an object. During the time that an instance of this class, known as a **unique pointer**, references an object, no other smart pointer can reference the same object. A unique pointer uses a simplified form of reference counting to maintain a reference count of either 0 or 1 for its managed object.

`weak_ptr` -- Provides a "weak," or non-owning, reference to an object that is already managed by a shared pointer. Since a **weak pointer** does not have ownership of the object, it cannot affect the object’s lifetime. That is, you cannot use this type of pointer to delete the object. As you will see, you can use it when you want two objects to reference each other. _Weak pointers do not use reference counting_.

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/aXA4nN3s), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd ${REPOSITORY_HOME}
```

where `${REPOSITORY_HOME}` is the directory containing your cloned repository.

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```bash
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git branch
```

_You may have to type the `q` character to get back to the command line prompt after viewing the branch(es)._

## Tasks

This lab consists of three tasks:

* Task 1: Working with Shared Pointers
* Task 2: Working with Unique Pointers
* Task 3: Working with Weak Pointers

### Task 1: Working with Shared Pointers

In this task, we're going to update the `Node` class used in the `LinkedBag` implementation of the `Bag` interface. We'll replace the raw pointer to the next `Node` with a `shared_ptr` to the next `Node`.

We can use shared pointers in our earlier `Node` and `LinkedBag` classes to help ensure that we handle memory correctly. We begin by revising the `Node` class originally found in Listings 4-1 and 4-2 of Chapter 4. We replace the raw pointer type `Node<ItemType>*` of the data field next with a shared pointer type `std::shared_ptr<Node<ItemType>>`. Since the default constructor of `shared_ptr` initializes `next` to `nullptr`, we do not need to include `next` in the initializer list of our default constructor. The `getNext` method returns the data field `next`, so the compiler can easily determine the method’s return type from `next`'s data type. Listings C4-1 and C4-2 reflect our revised `Node` class.

1. Include the `memory` library in the `Node` header file [include/node.h](include/node.h) so we have access to the `shared_ptr` class template.

   ```c++
   #include <memory>
   ```

2. Change the type of `next` from `Node<ItemType>*` to `std::shared_ptr<Node<ItemType>>`
3. Change the return type of the `getNext()` method to `auto`
4. Change the type of the `setNext()` parameter from `Node<ItemType>*` to `std::shared_ptr<Node<ItemType>>`
5. When you've completed this task, you can check your work by toggling the `TEST_TASK1` from `FALSE` to `TRUE` and run the `google-tests` target.

### Task 2: Working with Unique Pointers

Here we work with a different kind of managed pointer, that known as the unique pointer.

#### Transferring Ownership: Assignment operator

1. Verify that you can build the `demo` target.
2. Modify the `include/csc232.h` header file by toggling the `IS_WORKING_ON_TASK2` from `FALSE` to `TRUE` and try to build the `demo` target (or any target that includes this header file.). You should get a compiler error; Take note of it.
3. Comment out the offending line of code in the `transferOwnership` function.
4. Follow the guideline suggested by the `TODO`. Do not move until you can build the `demo` target. Ask for help if you still can't get it to build.

#### Transferring Ownership: Parameter passing

1. Uncomment the line of code that attempts to assign a value to `dblPtr`

   ```c++
   // dblPtr = csc232::changeBoxItem( dblPtr, initialValue * 2 );
   ```

2. Attempt to build the `demo` target again. You should get a compiler error; take not of it.
3. Follow the guideline suggested by the `TODO`. Do not move until you can build the `demo` target. Ask for help if you still can't get it to build.

Finally, when you're ready to test your efforts in Task 2, toggle the `TEST_TASK2` macro from `FALSE` to `TRUE` in the `include/csc232.h` header file. Build and execute the `google-tests` target.

### Task 3: Working with Weak Pointers

In our third and final task, we'll see how to work with weak pointers.

1. Modify the `include/csc232.h` header file by toggling the `IS_WORKING_ON_TASK2` from `FALSE` to `TRUE`.
2. Verify that you can build the `demo` target (it should build).
3. Execute the `demo` target and note the output. Explain the output in the `questions.txt` file (Question 1).
4. Change parameter passing mechanism in the `getReferenceCount` function from pass-by-value to pass-by-reference.
5. Rebuild and execute the `demo` target and again, note the output (it should be slightly different). Explain your new output in the `questions.txt` file (Question 2)

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Blackboard, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `trunk` branch. Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) Blackboard using a Text Submission. Please note: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.

### Due Date

Your assignment submission is due by 11:59 PM, Saturday, October 21, 2023.

### Grading Rubric

This assignment is worth **3 points**.

|Criteria          | Exceeds Expectations        | Meets Expectations                 | Below Expectations | Failure                                             |
|------------------|-----------------------------|------------------------------------|--------------------|-----------------------------------------------------|
|Pull Request (20%)| Submitted early, correct url| Submitted on-time; correct url     | Incorrect URL            | No pull request was created or submitted      |
|Code Style (20%)  | Exemplary code style        | Consistent, modern coding style    | Inconsistent coding style| No style whatsoever or no code changes present|
|Correctness^ (60%)| All unit tests pass         | At least 80% of the unit tests pass| At least 60% of the unit tests pass| Less than 50% of the unit tests pass|

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24 hour period following the due date, this lab will be penalized 0.6 point meaning the grading starts at 2.4 (out of 3 total possible) points.
* In the second 24 hour period following the due date, this lab will be penalized 1.2 points meaning the grading starts at 1.8 (out of 3 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 3 possible points.
