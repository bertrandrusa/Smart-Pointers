/**
 * @file plain_box.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CSC232_PLAIN_BOX_H_
#define CSC232_PLAIN_BOX_H_

#include "box.h"

template<typename ItemType>
class PlainBox : public Box<ItemType>
{
private:
    ItemType item;
public:
    explicit PlainBox( const ItemType& src = ItemType{ } );
    ItemType getItem( ) const override;
    void setItem( const ItemType& anItem ) override;
};

#endif
