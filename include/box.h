/**
 * @file box.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CSC232_BOX_H
#define CSC232_BOX_H

/**
 * @brief An abstraction of a box.
 * 
 * @tparam ItemType the type of item stored in this Box.
 */
template<typename ItemType>
class Box
{
public:
    /**
     * @brief Set the item in this Box object.
     * 
     * @param anItem the item to place in this Box.
     */
    virtual void setItem( const ItemType& anItem ) = 0;

    /**
     * @brief Get the item currently stored in this Box.
     * 
     * @return the item currently stored in this Box.
     */
    virtual ItemType getItem( ) const = 0;

    /**
     * @brief Destroy this Box object.
     * 
     */
    virtual ~Box( ) = default;
};

#endif
