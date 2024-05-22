/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2021
 *
 * @file      google_test_runner.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 * @brief     Google Test implementation template.
 */

#include "csc232.h"
#include "gtest/gtest.h"

/**
 * @brief Namespace to encapsulate course specific macros, declarations and definitions.
 */
namespace csc232
{
    static int possiblePoints;
    static int earnedPoints;
    static const int MAX_CORRECTNESS_PTS { 2 };

    /**
     * @brief Base test fixture that sets up grading for this assignment.
     */
    class CSC232BaseTestFixture : public ::testing::Test
    {
    protected:
        void SetUp ( ) override
        {
            ::testing::FLAGS_gtest_death_test_style = "threadsafe";
            // Redirect cout to our stringstream buffer or any other ostream
            sbuf = std::cout.rdbuf( );
            std::cout.rdbuf( buffer.rdbuf( ));

            AdditionalSetup( );

            possiblePoints += 1;
        }

        void TearDown ( ) override
        {
            // When done redirect cout to its old self
            std::cout.rdbuf( sbuf );
            sbuf = nullptr;

            AdditionalTearDown( );

            if ( !HasFailure( ))
            {
                earnedPoints += 1;
            }
        }

        virtual void AdditionalSetup ( )
        {
            /* template method for any customized additional setup */
        }

        virtual void AdditionalTearDown ( )
        {
            /* template method for any customized additional setup */
        }

        // Reusable objects for each unit test in this test fixture and any of its children
        std::stringstream buffer { };
        std::streambuf* sbuf;
    };

#if TEST_TASK1
    class Task1TestFixture : public CSC232BaseTestFixture
    {
    };

    TEST_F( Task1TestFixture, DefaultNodeNextPtrIsNullPtr )
    {
        Node<int> node;
        auto actual{ node.getNext( ) };
        auto expected{ nullptr };

        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task1TestFixture, DefaultNodeItemIsDefaultItemTypeValue )
    {
        Node<int> node;
        auto actual{ node.getItem( ) };
        auto expected{ int{ } };

        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task1TestFixture, PartiallyInitializedNodeNextPtrIsNullPtr )
    {
        Node<int> node{ 5 };
        auto actual{ node.getNext( ) };
        auto expected{ nullptr };

        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task1TestFixture, PartiallyInitializedNodeItemIsGivenItemTypeValue )
    {
        Node<int> node{ 5 };
        auto actual{ node.getItem( ) };
        auto expected{ 5 };

        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task1TestFixture, FullyInitializedNodeNextPtrIsValid )
    {
        Node<int> defNode{ 5 };
        auto actual{ defNode.getNext( ) };
        auto expected{ nullptr };

        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task1TestFixture, FullyInitializedNodeItemIsGivenItemTypeValue )
    {
        auto tailNode{ std::shared_ptr<Node<int>>{ }};
        Node<int> defNode{ 5, tailNode };
        auto actual{ defNode.getNext( ) };
        auto expected{ tailNode };

        EXPECT_EQ( expected, actual );
    }
#endif

#if TEST_TASK2
    class Task2TestFixture : public CSC232BaseTestFixture
    {

    };

    TEST_F( Task2TestFixture, DISABLED_DefaultPlainBoxHasDefaultItemTypeValue )
    {
        PlainBox<double> numberBox;
        auto expectedNumber{ double{ } };
        auto actualNumber{ numberBox.getItem( ) };
        
        EXPECT_EQ( expectedNumber, actualNumber );
    }

    TEST_F( Task2TestFixture, DISABLED_InitializedPlainBoxHasInitialItemTypeValue )
    {
        std::string name{ "CSC232" };
        PlainBox<std::string> nameBox{ name };
        auto const& expectedName{ name };
        auto const& actualName{ nameBox.getItem( ) };
        EXPECT_STREQ( expectedName.c_str( ), actualName.c_str( ) );
    }

//    TEST_F( Task2TestFixture, DISABLED_SmartRefactorIsSuccessful )
//    {
//        const std::string& name{ "CSC232" };
//        auto const& expected{ name };
//        auto actual{ csc232::plainFunctionSmartShared( name ) };
//        EXPECT_STREQ( expected.c_str( ), actual.c_str( ) );
//    }

    TEST_F( Task2TestFixture, TransferOwnershipIsSuccessful )
    {
        const std::string& expectedName{ "CSC232" };
        auto ptr = std::make_unique<PlainBox<std::string>>( expectedName );
        auto actualName{ csc232::transferOwnership( expectedName )->getItem( ) };
        EXPECT_STREQ( expectedName.c_str( ), actualName.c_str( ) );
    }

    TEST_F( Task2TestFixture, MoveArgumentIsSuccessful )
    {
        double initialValue{ 3.14159 };
        double expectedValue{ 2 * initialValue };
        auto ptr = std::make_unique<PlainBox<double>>( initialValue );
        ptr = csc232::changeBoxItem( std::move(ptr), initialValue * 2 );
        auto actualValue = ptr->getItem();
        EXPECT_DOUBLE_EQ( expectedValue, actualValue );
    }

#endif

#if TEST_TASK3
    class Task3TestFixture : public CSC232BaseTestFixture
    {

    };
    
#endif

} // end namespace

int main ( int argc, char** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    int result { RUN_ALL_TESTS( ) };
    std::cout << std::fixed << std::setprecision( 2 );
    std::cout << "\n\n";
    std::cout << std::left << std::setw( 21 ) << "Earned Points:"
              << std::right << std::setw( 5 ) << static_cast<double>(csc232::earnedPoints) << std::endl;
    std::cout << std::left << std::setw( 21 ) << "Possible Points:"
              << std::right << std::setw( 5 ) << static_cast<double>(csc232::possiblePoints) << std::endl;
    double percentCorrect { static_cast<double>(csc232::earnedPoints) / csc232::possiblePoints };
    double correctnessPoints { csc232::possiblePoints != 0 ? percentCorrect * csc232::MAX_CORRECTNESS_PTS
                                                           : 0 };
    std::cout << std::left << std::setw( 21 ) << "Correctness Points:"
              << std::right << std::setw( 5 ) << correctnessPoints << std::endl;
    return result;
}
