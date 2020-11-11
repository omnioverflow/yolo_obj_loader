#include "gtest/gtest.h"

#include "color.h"
#include "bmp/bmp.h"
#include "io/filesystem.h"

namespace engine
{
  namespace test
  {
    class BmpTest : public ::testing::Test
    {
    protected:
      // You can remove any or all of the following functions if their bodies would
      // be empty.

     BmpTest() 
     {
        // You can do set-up work for each test here.
     }

      ~BmpTest() override 
      {
        // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      // Code here will be called immediately after the constructor (right
      // before each test).
      void SetUp() override 
      {
        // Create an output test directory
//        fs::create_directories(fs::path(TEST_DIR));
      }

      // Code here will be called immediately after each test (right
      // before the destructor).
      void TearDown() override 
      {
        // Cleanup test output directory
//        fs::remove_all(fs::path(TEST_DIR));
      }

    protected:

      static constexpr char TEST_DIR[] = u8"bmp_test";
      static constexpr char BLACK_SQUARE_FILE[] = u8"black_square";
    }; // class BmpTest

    TEST_F(BmpTest, BmpRead)
    {
      std::string s = TEST_DIR;
//      Bmp bmp = Bmp::read(BLACK_SQUARE_FILE);
      // all pixels must be black

    }

    // Tests that write() method succeeds in writing to a file
    TEST_F(BmpTest, BmpWrite)
    {
    }

  }  // namespace test
}  // namespace engine