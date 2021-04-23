#pragma once
#include <iostream>
#include <initializer_list>

namespace math
{
	class matrix
	{
	private:
		double *mtrx;
		size_t size_row;
		size_t size_col;

		static size_t count;
		size_t id;

	public:
		/* # Конструкторы и деструктор #  */
		matrix();
		matrix(const std::initializer_list < std::initializer_list < double >> &Elems);
		matrix(size_t size);
		matrix(size_t size_a, size_t size_b);
		matrix(const matrix &other);
		matrix(matrix&&);
		~matrix();

		/* # Доступ к элементам матрицы # */
		size_t get_id() const;
		static size_t get_count();
		size_t get_size_row() const;
		size_t get_size_col() const;
		double get_value(size_t i, size_t j) const;
		void set_value(size_t i, size_t j, double a);
		const double & at(size_t i, size_t j) const;
		double & at(size_t i, size_t j);

		/* # Методы проверки и поиска min/max значения # */
		bool pos_mul(const matrix &b) const;
		bool pos_sum(const matrix &b) const;
		double max_element() const;
		double min_element() const;

		/* # Перегрузка операторов # */
		const double* operator[](size_t index) const;
		double* operator[](size_t index);
		matrix& operator=(const matrix &other);
		matrix& operator=(matrix && other);
		matrix& operator=(const std::initializer_list < std::initializer_list < double >> &Elems);
		matrix& operator+=(const matrix &other);
		matrix& operator-=(const matrix &other);
		matrix& operator*=(const matrix &other);
		matrix& operator*=(double scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const matrix& a);
	};

	matrix operator+(const matrix& a, const matrix& b);
	matrix operator-(const matrix& a, const matrix& b);
	matrix operator*(const matrix &a, const matrix &b);
	matrix operator*(const matrix &a, double scalar);
}