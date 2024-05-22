/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2020
 *
 * @file    expanded_templates.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Class template expansions.
 */

#ifndef MSU_CSC232_EXPANDED_TEMPLATES_H__
#define MSU_CSC232_EXPANDED_TEMPLATES_H__

#include <string>

/* Include class template implementation files as needed */
#include "node.cpp"
template class Node<int>;

#include "plain_box.cpp"
template class PlainBox<double>;
template class PlainBox<std::string>;

#endif // MSU_CSC232_EXPANDED_TEMPLATES_H__
