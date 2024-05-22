/**
* @file node.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2022-10-16
*
* @copyright Copyright (c) 2022
*
*/

#include "node.h"

template<typename ItemType>
Node<ItemType>::Node( const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr ) : item{ anItem }, next{ nextNodePtr }
{
    // Intentionally empty
}

template<typename ItemType>
ItemType Node<ItemType>::getItem( ) const
{
    return item;
}

template<typename ItemType>
void Node<ItemType>::setItem( const ItemType& anItem )
{
    item = anItem;
}

template<typename ItemType>
auto Node<ItemType>::getNext( ) const
{
    return next;
}

template<typename ItemType>
void Node<ItemType>::setNext( std::shared_ptr<Node<ItemType>> nextNodePtr )
{
    next = nextNodePtr;
}