#ifndef SWAY_MATH_VECTOR_H
#define SWAY_MATH_VECTOR_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template<typename TYPE, std::size_t SIZE>
class TVector {
	static_assert(SIZE != 0, "Вектор не может иметь нулевой размер");

public:
	typedef TYPE type_t; /*!< Базовый тип данных. */

	enum: std::size_t {
		size = SIZE /*!< Размер вектора. */
	};

	/*!
	 * \brief 
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми значениями.
	 */
	TVector() {
		for(std::size_t i = 0; i != size; ++i)
			_data[i] = (TYPE) 0;
	}

	/**
	 * \brief
	 *    Возвращает необработанные данные.
	 * 
	 * \sa
	 *    data() const
	 */
	TYPE * data() {
		return _data;
	}

	/**
	 * \brief
	 *    Возвращает необработанные данные.
	 * 
	 * \sa
	 *    data()
	 */
    const TYPE * data() const {
		return _data;
	}

	/**
	 * \brief
	 *    Возвращает значение в заданной позиции.
	 * 
	 * \param[in] position
	 *    Позиция значения.
	 * 
	 * \sa
	 *    operator[](std::size_t) const
	 */
	TYPE & operator[](std::size_t position) {
		assert(position >= 0 && position <= SIZE);
		return _data[position];
	}

	/**
	 * \brief
	 *    Возвращает значение в заданной позиции.
	 * 
	 * \param[in] position
	 *    Позиция значения.
	 * 
	 * \sa
	 *    operator[](std::size_t)
	 */
	const TYPE operator[](std::size_t position) const {
		assert(position >= 0 && position <= SIZE);
		return _data[position];
	}

protected:
	TYPE _data[SIZE]; /*!< Данные вектора. */
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_VECTOR_H
