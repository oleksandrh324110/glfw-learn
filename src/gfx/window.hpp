#pragma once

#include "../App.hpp"
#include "../util/util.hpp"
#include "gfx.hpp"

namespace gfx {
struct Button {
  bool down, last, pressed;
};

struct Mouse {
  Button buttons[GLFW_MOUSE_BUTTON_LAST];
  glm::vec2 position;
  glm::vec2 delta;
  glm::vec2 scroll;

  glm::vec2 smooth_position;
  glm::vec2 smooth_delta;
  glm::vec2 smooth_scroll;
};

struct Keyboard {
  Button keys[GLFW_KEY_LAST];
};

class Window {
 public:
  glm::vec2 size;
  const char* title;

  Mouse mouse;
  Keyboard keyboard;

  VAO vao;
  VBO vbo;
  VBO ebo;

  double time;
  double last_time;
  double delta_time;

  Window(glm::vec2 size, const char* title);
  ~Window();

  void update();
  void render() const;

  void clear() const;
  void swap() const;

  bool should_close() const;
  void set_should_close(bool value);

  ImGuiIO& get_imgui_io() const;

 private:
  GLFWwindow* _handle;
};
}  // namespace gfx