#pragma once

#include "../App.hpp"
#include "../util/util.hpp"
#include "gfx.hpp"

namespace gfx {
class Shader {
 public:
  GLuint _handle;

  Shader();
  Shader(const char* vs_path, const char* fs_path);
  ~Shader();

  void use() const;

  void set_bool(const char* name, GLboolean value) const;
  void set_int(const char* name, GLint value) const;
  void set_float(const char* name, GLfloat value) const;
  void set_vec2(const char* name, glm::vec2 vec) const;
  void set_ivec2(const char* name, glm::ivec2 vec) const;
};
};  // namespace gfx