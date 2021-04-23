#include "pch.h"
#include "matrix.h"

using namespace std;

namespace math
{
	size_t matrix::count = 0;

	matrix::matrix()
	{
		id = count++;
		cout << "-> Конструктор матрицы с id: " << id << endl;

		mtrx = nullptr;
		size_row = 0;
		size_col = 0;
	}

	matrix::matrix(const std::initializer_list < std::initializer_list < double >> &Elems) : matrix()
	{
		*this = Elems;
	}

	matrix::matrix(size_t size) : matrix(size, size)
	{
	}

	matrix::matrix(size_t size_row, size_t size_col) : matrix()
	{
		this->size_row = size_row;
		this->size_col = size_col;
		if (size_row * size_col != 0)
			this->mtrx = new double[this->size_col * this->size_row];
	}

	matrix::matrix(const matrix &other) : matrix()
	{
		*this = other;
	}

	matrix::matrix(matrix &&A) : matrix()
	{
		swap(mtrx, A.mtrx);
		swap(size_row, A.size_row);
		swap(size_col, A.size_col);
	}

	matrix:: ~matrix()
	{
		cout << "-> Деструктор  матрицы с id: " << id << endl;

		if (mtrx != nullptr)
		{
			delete[] mtrx;
			mtrx = nullptr;
			size_row = 0;
			size_col = 0;
		}
	}

	size_t matrix::get_id() const
	{
		return id;
	}

	size_t matrix::get_count()
	{
		return matrix::count;
	}

	size_t matrix::get_size_row() const
	{
		return size_row;
	}

	size_t matrix::get_size_col() const
	{
		return size_col;
	}

	double matrix::get_value(size_t i, size_t j) const
	{
		if (i < size_row && j < size_col)
		{
			return mtrx[i * size_col + j];
		}
		throw exception("Этого элемента не существует! id: ", id);
	}

	void matrix::set_value(size_t i, size_t j, double a)
	{
		if (i < size_row && j < size_col)
		{
			this->mtrx[i * size_col + j] = a;
		}
		else
		{
			throw exception("Невозможно получить значение этого элемента! id: ", id);
		}
	}

	const double & matrix::at(size_t i, size_t j) const
	{
		if (i < size_row && j < size_col)
		{
			return mtrx[i * size_col + j];
		}
		throw exception("Невозможная операция! id: ", id);
	}

	double & matrix::at(size_t i, size_t j)
	{
		if (i < size_row && j < size_col)
		{
			return mtrx[i * size_col + j];
		}
		throw exception("Невозможная операция! id: ", id);
	}

	bool matrix::pos_mul(const matrix &b) const
	{
		return size_col == b.size_row;
	}

	bool matrix::pos_sum(const matrix &b) const
	{
		return size_row == b.size_row && size_col == b.size_col;
	}

	double matrix::max_element() const
	{
		if (mtrx != nullptr)
		{
			double max = mtrx[0];
			for (size_t i = 1; i < size_row * size_col; i++)
			{
				if (mtrx[i] > max)
				{
					max = mtrx[i];
				}
			}
			return max;
		}
		throw exception("Невозможно получить максимальный элемент матрицы! id: ", id);
	}

	double matrix::min_element() const
	{
		if (mtrx != nullptr)
		{
			double min = mtrx[0];
			for (size_t i = 1; i < size_row * size_col; i++)
			{
				if (mtrx[i] < min)
				{
					min = mtrx[i];
				}
			}
			return min;
		}
		throw exception("Невозможно получить минимальный элемент матрицы! id: ", id);
	}

	const double* matrix::operator[](size_t index) const
	{
		return mtrx + index * size_row;
	}

	double* matrix::operator[](size_t index)
	{
		return mtrx + index * size_row;
	}

	matrix& matrix::operator=(const matrix &other)
	{
		if (this == &other) return *this;

		if (size_row * size_col != other.size_row * other.size_col)
		{
			if (mtrx)
			{
				delete[] mtrx;
				mtrx = nullptr;
			}
			size_row = other.size_row;
			size_col = other.size_col;
			if (size_row * size_col != 0)
				this->mtrx = new double[size_row * size_col];
		}
		else
		{
			size_row = other.size_row;
			size_col = other.size_col;
		}

		for (size_t i = 0; i < other.size_row * other.size_col; i++)
			mtrx[i] = other.mtrx[i];

		return *this;
	}

	matrix & matrix::operator=(matrix && other)
	{
		if (this == &other) return *this;

		if (mtrx)
			delete[] mtrx;

		mtrx = other.mtrx;
		size_col = other.size_col;
		size_row = other.size_row;

		other.mtrx = nullptr;
		other.size_col = 0;
		other.size_row = 0;

		return *this;
	}

	matrix& matrix::operator=(const std::initializer_list<std::initializer_list<double>> &Elems)
	{
		if (Elems.size() != 0)
		{
			if (Elems.begin()->size() != 0)
			{
				for (auto &x : Elems)
				{
					if (x.size() != Elems.begin()->size())
					{
						throw exception("Передаются разные листы, бро! id: ", id);
					}
				}

				if (size_row * size_col != Elems.size() * Elems.begin()->size())
				{
					if (mtrx)
						delete[] mtrx;
					size_row = Elems.size();
					size_col = Elems.begin()->size();
					if (size_row * size_col != 0)
						mtrx = new double[size_col * size_row];
				}
				else
				{
					size_row = Elems.size();
					size_col = Elems.begin()->size();
				}

				if (size_row * size_col != 0)
				{
					int pos = 0;
					for (const auto& i : Elems)
					{
						for (const auto& j : i)
						{
							mtrx[pos++] = j;
						}
					}
				}
			}
			else
			{
				size_row = Elems.size();
				size_col = Elems.begin()->size();
				if (mtrx)
				{
					delete[] mtrx;
					mtrx = nullptr;
				}
			}
		}
		else
		{
			size_row = Elems.size();
			size_col = Elems.size();
			if (mtrx)
			{
				delete[] mtrx;
				mtrx = nullptr;
			}
		}

		return *this;
	}

	matrix & matrix::operator+=(const matrix & other)
	{
		if (pos_sum(other))
		{
			for (size_t i = 0; i < size_row * size_col; i++)
			{
				this->mtrx[i] += other.mtrx[i];
			}
			return *this;
		}
		throw exception("Невозможно прибавить к первой матрице вторую! id: ", id);
	}

	matrix& matrix::operator-=(const matrix &other)
	{
		if (pos_sum(other))
		{
			for (size_t i = 0; i < size_row * size_col; i++)
			{
				this->mtrx[i] -= other.mtrx[i];
			}
			return *this;
		}
		throw exception("Невозможно отнять от первой матрицы вторую! id: ", id);
	}

	matrix& matrix::operator*=(const matrix &B)
	{
		if (pos_mul(B))
		{
			matrix C(size_row, B.size_col);
			for (size_t i = 0; i < size_row; ++i)
			{
				for (size_t j = 0; j < B.size_col; ++j)
				{
					C.mtrx[i*B.size_col + j] = 0;
					for (size_t k = 0; k < size_col; ++k)
						C.mtrx[i*B.size_col + j] += mtrx[i*size_col + k] * B.mtrx[k*B.size_col + j];
				}
			}

			std::swap(size_col, C.size_col);
			std::swap(mtrx, C.mtrx);

			return *this;
		}
		throw exception("Невозможно выполнить эту операцию! id: ", id);
	}

	matrix & matrix::operator*=(double scalar)
	{
		for (size_t i = 0; i < size_col * size_row; i++)
		{
			mtrx[i] = mtrx[i] * scalar;
		}
		return *this;
	}

	matrix operator+(const matrix& a, const matrix& b)
	{
		matrix c = a;
		return c += b;
	}

	matrix operator-(const matrix& a, const matrix& b)
	{
		return matrix(a) -= b;
	}

	matrix operator*(const matrix& a, const matrix &b)
	{
		matrix c(a);
		return c *= b;
	}

	matrix operator*(const matrix& a, double scalar)
	{
		return matrix(a) *= scalar;
	}

	std::ostream& operator<<(std::ostream& ostream, const matrix& a)
	{
		std::streamsize width = ostream.width();
		for (size_t i = 0; i < a.get_size_row(); i++)
		{
			for (size_t j = 0; j < a.get_size_col(); j++)
			{
				ostream.width(width);
				ostream << a[i][j];
				if (!width)
					std::cout << " ";
			}
			ostream << endl;
		}
		return ostream;
	}
}