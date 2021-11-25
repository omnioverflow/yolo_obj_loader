#pragma once

#include <string>
#include <tuple>
#include <vector>

#ifdef ENABLE_DOUBLE_PRECISION
typedef double real_t;
#else
typedef float real_t;
#endif

namespace yolo
{
  class ObjLoader {
  public:
    ObjLoader() = delete;
    ObjLoader(const std::string& filePath);

    std::vector<std::tuple<real_t, real_t, real_t>> getVertexPositions() const;
    std::vector<std::tuple<int, int, int>> getTriangles() const;

  private:

    void processLine(const std::string& line);
    void readVertex(const std::string& line);
    void readFace(const std::string& line);
    static char getFirstChar(const std::string& str);

    void reportIOError() const;
    
  private:
    const bool mEnableCache;
    const std::string mFilePath;
  };
} // namespace