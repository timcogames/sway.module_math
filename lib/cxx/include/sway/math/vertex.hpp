#ifndef SWAY_MATH_VERTEX_HPP
#define SWAY_MATH_VERTEX_HPP

#include <sway/core.hpp>
#include <sway/math/color.hpp>
#include <sway/math/vector2.hpp>
#include <sway/math/vector3.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Базовая структура представления вершины.
 *
 * @note Содержит только позицию вершины.
 */
struct VertexPosition {
  f32_t x, y, z;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @sa VertexPosition(const vec3f_t &)
   */
  VertexPosition() { x = y = z = 0.0F; }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @sa VertexPosition()
   */
  VertexPosition(const vec3f_t &position) { setPosition(position); }

  /**
   * @brief Устанавливает позицию вершины.
   *
   * @param[in] position Значение позиции вершины.
   */
  void setPosition(const vec3f_t &position) {
    x = position.getX();
    y = position.getY();
    z = position.getZ();
  }

  /**
   * @brief Возвращает позицию вершины.
   */
  auto getPosition() const -> vec3f_t { return Vector3<f32_t>(x, y, z); }
};

/**
 * @brief Структура представления вершины.
 * @note Содержит позицию и цвет вершины.
 */
struct VertexColor : public VertexPosition {
  f32_t r, g, b, a;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @sa VertexColor(const vec3f_t &, const col4f_t &)
   */
  VertexColor() { r = g = b = a = 0.0F; }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @sa VertexColor()
   */
  VertexColor(const vec3f_t &position, const col4f_t &color)
      : VertexPosition(position) {
    setColor(color);
  }

  /**
   * @brief Устанавливает цвет вершины.
   *
   * @param[in] color Значение цвета вершины.
   */
  void setColor(const col4f_t &color) {
    r = color.getR();
    g = color.getG();
    b = color.getB();
    a = color.getA();
  }

  /**
   * @brief Возвращает цвет вершины.
   */
  auto getColor() const -> col4f_t { return Color<f32_t>(r, g, b, a); }
};

/**
 * @brief Структура представления вершины.
 *
 * @note Содержит позицию, цвет и текстурные координаты вершины.
 */
struct VertexTexCoord : public VertexPosition {
  f32_t u, v;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @sa VertexTexCoord(const vec3f_t &, const vec2f_t &)
   */
  VertexTexCoord() { u = v = 0.0F; }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @sa VertexTexCoord()
   */
  VertexTexCoord(const vec3f_t &position, const vec2f_t &texCoord)
      : VertexPosition(position) {
    setTexCoord(texCoord);
  }

  /**
   * @brief Устанавливает текстурные координаты.
   *
   * @param[in] texCoord Значение текстурных координат.
   */
  void setTexCoord(const vec2f_t &texCoord) {
    u = texCoord.getX();
    v = texCoord.getY();
  }

  /**
   * @brief Возвращает текстурные координаты.
   */
  auto getTexCoord() const -> vec2f_t { return Vector2<f32_t>(u, v); }
};

struct VertexTexCoordEx {
  f32_t x, y, z;
  f32_t r, g, b, a;
  f32_t u, v;

  VertexTexCoordEx() {
    x = y = z = 0.0F;
    r = g = b = a = 0.0F;
    u = v = 0.0F;
  }

  VertexTexCoordEx(const math::vec3f_t &position, const math::col4f_t &color, const math::vec2f_t &texCoord) {
    setPosition(position);
    setColor(color);
    setTexCoord(texCoord);
  }

  void setPosition(const math::vec3f_t &position) {
    x = position.getX();
    y = position.getY();
    z = position.getZ();
  }

  [[nodiscard]] auto getPosition() const -> math::vec3f_t { return math::Vector3<f32_t>(x, y, z); }

  void setColor(const math::col4f_t &color) {
    r = color.getR();
    g = color.getG();
    b = color.getB();
    a = color.getA();
  }

  [[nodiscard]] auto getColor() const -> math::col4f_t { return math::Color<f32_t>(r, g, b, a); }

  void setTexCoord(const math::vec2f_t &texCoord) {
    u = texCoord.getX();
    v = texCoord.getY();
  }

  auto getTexCoord() const -> math::vec2f_t { return math::Vector2<f32_t>(u, v); }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VERTEX_HPP
