/**
 * @file plain_box.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "plain_box.h"

template<typename ItemType>
PlainBox<ItemType>::PlainBox( const ItemType& anItem ) : item{ anItem }
{

}

template<typename ItemType>
ItemType PlainBox<ItemType>::getItem( ) const
{
    return item;
}

template<typename ItemType>
void PlainBox<ItemType>::setItem( const ItemType& anItem )
{
    item = anItem;
}
