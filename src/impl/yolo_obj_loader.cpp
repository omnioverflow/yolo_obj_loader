#include "yolo_obj_loader.h"

#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace yolo;

ObjLoader::ObjLoader(const std::string& filePath) 
: mFilePath(filePath)
// TODO: implement caching of input data
, mEnableCache(false)  {
  assert(mFilePath.size());

  auto inFileStream = std::ifstream(mFilePath);
  if (inFileStream.is_open()) {
    for (std::string nextLine; std::getline(inFileStream, nextLine);)
      processLine(nextLine);
  } else {
    reportIOError();
  }
}

/*===---------------------------------------------------------------------===*/

std::vector<std::tuple<real_t, real_t, real_t>> ObjLoader::getVertexPositions() const {
  // FIXME: return member var
  auto vertexPositions = std::vector<std::tuple<real_t, real_t, real_t>>{};
  return vertexPositions;
}
std::vector<std::tuple<int, int, int>> ObjLoader::getTriangles() const {
  // FIXME: return member var  
  auto triangles = std::vector<std::tuple<int, int, int>>{};
  return triangles;
}

/*===---------------------------------------------------------------------===*/

void ObjLoader::processLine(const std::string& line) {
  if (line.empty())
    return;

  const auto firstCharOnLine = getFirstChar(line);
  switch (firstCharOnLine) {
    case 'v': {
      readVertex(line);
     break;
    }
    case 'f': {
      readFace(line);
      break;
    }
    default: {
      break;
    }
  }
}

void ObjLoader::readVertex(const std::string& line) {
  std::istringstream inStrStream(line);
  // FIXME: deal with literal issue float vs double
  real_t vx{};
  real_t vy{};
  real_t vz = {};
  if (!(inStrStream >> vx >> vy >> vz)) {
    assert(false); 
  }
}

void ObjLoader::readFace(const std::string& line) {
  std::istringstream inStrStream(line);  
  std::string vertId;
  while (inStrStream >> vertId) {
    //vertIds.push_back(std::stoi(vertId));
  }

  /*const auto nbVerts = vertIds.size();
  if (nbVerts < 3 || nbVerts > 4) {
    assert(false);
    return;
  } else {
    for (int i = 0; i < 3; ++i)
      
  }*/
}

char ObjLoader::getFirstChar(const std::string& str) {
  if (str.size() == 0)
    assert(false);

  return str.at(0);
}

void ObjLoader::reportIOError() const {
  std::cerr << "Cannot open file " << mFilePath << std::endl;
  assert(false);
}