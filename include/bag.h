/**
 * @file bag.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CSC232_BAG_H
#define CSC232_BAG_H

/**
 * @brief An abstraction of a bag of items.
 * 
 * @tparam ItemType the type of item contained in this Bag
 */
template<typename ItemType>
class Bag
{
public:
    /**
     * @brief Get the number of items in this Bag.
     * 
     * @return the number of items in this Bag
     */
    virtual int getCurrentSize() const = 0;

    /**
     * @brief Assess whether this Bag contains any items.
     * 
     * @return true if there is at least one item in this Bag
     * @return false if there are no items in this Bag
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Add an item to this Bag.
     * 
     * @param newEntry the item to add to this Bag
     * @return true if the new item was successfully added to this Bag
     * @return false if the new item was unable to be added to this Bag
     */
    virtual bool add(const ItemType& newEntry) = 0;

    /**
     * @brief Remove an item from this Bag.
     * 
     * @param anEntry the target item to be removed from this Bag.
     * @return true if the target item was successfully removed from this Bag
     * @return false if the target item could not be removed from this Bag
     */
    virtual bool remove(const ItemType& anEntry) = 0;

    /**
     * @brief Empty the contents of this Bag.
     */
    virtual void clear() = 0;

    /**
     * @brief Get the number of occurrences of some item in this Bag.
     * 
     * @param anEntry the item whose frequency we desire
     * @return the number of occurrences of the given item in this Bag
     */
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

    /**
     * @brief Assess whether this Bag contains a given item.
     * 
     * @param anEntry The target of this assessment
     * @return true if this Bag contains the target item
     * @return false if this Bag does not contain the target item
     */
    virtual bool contains(const ItemType& anEntry) const = 0;

    /**
     * @brief Provides a view into the contents of this Bag.
     * 
     * @return a vector representation of this Bag
     */
    virtual std::vector<ItemType> toVector() const = 0;

    /**
     * @brief Destroy this Bag.
     */
    virtual ~BagInterface() = default;
};

#endif
