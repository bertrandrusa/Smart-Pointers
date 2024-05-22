/**
* @file demo.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the demo target.
* @version 0.1.1
* @date 2022-02-23
* 
* @copyright Copyright (c) 2022
* 
*/

#include "csc232.h"

template<typename ItemType>
auto getReferenceCount( std::shared_ptr<PlainBox<ItemType>>& sharedPtr1 )
{
	auto sharedPtr2 = sharedPtr1;
	auto sharedPtr3 = sharedPtr1;
	std::weak_ptr<PlainBox<ItemType>> weakPtr1 = sharedPtr1;
	auto weakPtr2 = weakPtr1;
	long use_count = sharedPtr1.use_count();

	std::cout << "sharedPtr1.use_count() = " << use_count << std::endl;
	return use_count;
}

int main(int argc, char* argv[])
{

#if IS_WORKING_ON_TASK2
	const std::string& expectedName{ "CSC232" };
	auto strPtr = std::make_unique<PlainBox<std::string>>( expectedName );
	auto actualName{ csc232::transferOwnership( expectedName )->getItem( ) };

	double initialValue{ 3.1459 };
	auto dblPtr = std::make_unique<PlainBox<double>>( initialValue );
	// TODO: Move the first argument instead of passing by value
	 dblPtr = csc232::changeBoxItem(std::move(dblPtr), initialValue * 2 );
#endif

#if IS_WORKING_ON_TASK3
	auto ptr = std::make_shared<PlainBox<double>>( );
	auto count = getReferenceCount( ptr );
	std::cout << "\ncount (calling function) = " << count << std::endl;
	std::cout << "count (ptr)              = " << ptr.use_count() << std::endl;
#endif

	return EXIT_SUCCESS;
}
