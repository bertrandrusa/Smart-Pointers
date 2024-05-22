/**
* @file main.cxx
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the main target.
* @version 0.1.1
* @date 2022-02-23
*
* @copyright Copyright (c) 2022
*
*/
#include "csc232.h"


    int main()
    {
        std::cout << "Hello, Main Target!" << std::endl;

        Node<int> aDefaultNode{};
        Node<int> aPartiallyInitializedNode{5};

        Node<int> aFullyInitializedNode{6, std::make_shared<Node<int>>(aDefaultNode)};

        std::cout << "Default node item: " << aDefaultNode.getItem() << "\n";
        std::cout << "A partially initialized node item: " << aPartiallyInitializedNode.getItem() << "\n";
        std::cout << "A fully initialized node item: " << aFullyInitializedNode.getItem() << "\n";

        return EXIT_SUCCESS;
    }

