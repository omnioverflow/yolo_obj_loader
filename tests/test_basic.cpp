#include "gtest/gtest.h"

#include "yolo_obj_loader.h"

namespace yolo
{
  namespace test
  {
    class YoloObjLoaderTest : public ::testing::Test
    {
    protected:
      // You can remove any or all of the following functions if their bodies would
      // be empty.

     YoloObjLoaderTest() 
     {
        // You can do set-up work for each test here.
     }

      ~YoloObjLoaderTest() override 
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

      static constexpr auto TEST_DATA_DIR = "../data";
      static constexpr auto TETRAHEDRON = "tetrahedron.obj";
    }; // class YoloObjLoaderTest

    TEST_F(YoloObjLoaderTest, ObjSimpleRead)
    {
      ObjLoader ldr;
      ASSERT_TRUE(true);
    }

    // Tests that write() method succeeds in writing to a file
    TEST_F(YoloObjLoaderTest, ObjReadVertices)
    {
    }

  }  // namespace test
}  // namespace yolo