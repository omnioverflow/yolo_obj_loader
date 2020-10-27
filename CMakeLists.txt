cmake_minimum_required (VERSION 3.16)

set (CMAKE_CXX_STANDARD 14)
set (LIB_NAME yolo_obj_loader) 

project (${LIB_NAME})

# find impl source files
aux_source_directory(src/impl LIB_IMPL_FILES)

message ("\n========\nFound implementation files: \n"
         ${LIB_IMPL_FILES} "\n========\n")

add_library (${LIB_NAME} ${LIB_IMPL_FILES}) 

target_include_directories (${LIB_NAME} PUBLIC src/include)
set (HEADER_LIST src/include/yolo_obj_loader.h)

target_sources (${LIB_NAME} 
  PRIVATE
    ${LIB_IMPL_FILES}
  PUBLIC
    ${HEADER_LIST})
