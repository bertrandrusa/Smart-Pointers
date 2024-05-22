/**
 * @file node.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef CSC232_NODE_H
#define CSC232_NODE_H

#include <memory>

/**
 * @brief A singly-linked node.
 *
 * @tparam ItemType the type of item contained in this Node
 */
template<typename ItemType>
class Node
{
private:
    ItemType item;
    std::shared_ptr<Node<ItemType>> next;
public:

    /**
     * @brief Construct a new Node object.
     *
     * @param item
     * @param next
     */
    explicit Node( const ItemType& item = ItemType{ }, std::shared_ptr<Node<ItemType>> nextNodePtr = nullptr );

    /**
     * @brief Get the item encapsulated by this Node
     *
     * @return the item encapsulated by this Node
     */
    ItemType getItem( ) const;

    /**
     * @brief Get a pointer to the Node referenced by this Node.
     *
     * @return a pointer to the Node referenced by this Node
     */
    auto getNext( ) const;

    /**
     * @brief Update the item encapsulated by this Node.
     *
     * @param anItem an item to encapsulatd in this Node
     */
    void setItem( const ItemType& anItem );

    /**
     * @brief Update the pointer used to reference some Node.
     *
     */
    void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
};

#endif