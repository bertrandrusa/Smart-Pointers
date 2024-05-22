/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    csc232.hxx
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.2021.11.21
 * @date    11/21/2021
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#ifndef CSC232_COMMON_H__
#define CSC232_COMMON_H__


#define FALSE 0
#define TRUE 1

#define IS_WORKING_ON_TASK2 TRUE
#define IS_WORKING_ON_TASK3 TRUE

#define TEST_TASK1 TRUE
#define TEST_TASK2 TRUE
#define TEST_TASK3 TRUE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

#include "expanded_templates.h"

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    // Add any user-defined functions prescribed in your assignment below

#if  IS_WORKING_ON_TASK2

    auto transferOwnership( const std::string& item )
    {
        auto ptr1 = std::make_unique<PlainBox<std::string>>(item);
        std::unique_ptr<PlainBox<std::string>> ptr2;

        ptr2 = std::move(ptr1); //  Use "std::move" to transfer ownership.

        // TODO: After discovering the error; transfer ownership of ptr1 to ptr2 using std::move
        return ptr2; // Returning ptr2 after transferring ownership
    }

    /**
     * @brief Changes the item in a PlainBox holding a double.
     */
    auto changeBoxItem(std::unique_ptr<PlainBox<double>> theBox, double item)
    {
        theBox->setItem(item);
        return theBox; // Returning the modified unique pointer
    }

#endif

    // DO NOT Modify anything below this line

    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    std::string GenerateUuid()
    {
        static std::random_device random_device;
        static std::mt19937 random_number_generator(random_device());

        std::uniform_int_distribution<int> dist(0, 15);

        const char* uuid_alphabet = "0123456789abcdef";
        const bool dash[] = { false, false, false, false, true, false, true, false,
                              true, false, true, false, false, false, false, false };

        std::string uuid;
        for (bool dash_location : dash)
        {
            if (dash_location)
                uuid += "-";
            uuid += uuid_alphabet[dist(random_number_generator)];
            uuid += uuid_alphabet[dist(random_number_generator)];
        }
        return uuid;
    }
} // namespace csc232

#endif // CSC232_COMMON_H__