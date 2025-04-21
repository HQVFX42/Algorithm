#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace ca
{
	template <typename T>
	class Vector
	{
	public:
		Vector(size_t cap = DEFAULT_CAP)
			: mArr(new T[ cap ])
			, mSize(0)
			, mCapaciry(cap)
		{

		}
		Vector(const Vector& other)
			: mArr(new T[ other.mCapaciry ])
			, mSize(other.mSize)
			, mCapaciry(other.mCapaciry)
		{
			for (size_t i = 0; i < mSize; i++)
			{
				mArr[ i ] = other[ i ];
			}
		}
		Vector(const Vector&& other)
			: mArr(std::move(other.mArr))
			, mSize(other.mSize)
			, mCapaciry(other.mCapaciry)
		{
			other = nullptr;
			other.mSize = 0;
			other.mCapaciry = 0;
		}
		~Vector()
		{
			delete[] mArr;
		}

		Vector& operator=(const Vector& other)
		{
			if (this != nullptr)
			{
				if (mCapaciry < other.mCapaciry)
				{
					delete[] mArr;
					mArr = nullptr;
					mCapaciry = other.mCapaciry;
					mArr = new T[ mCapaciry ];
				}

				mSize = other.mSize;
				for (size_t i = 0; i < mSize; i++)
					mArr[ i ] = other.mArr[ i ];
			}

			return *this;
		}
		Vector& operator=(Vector&& other)
		{
			std::swap(mArr, other.mArr);
			std::swap(mSize, other.mSize);
			std::swap(mCapaciry, other.mCapaciry);
		}

	public:
		T* begin() const { return mArr; }
		T* end() const { return mArr; }
		T& front() { return mArr[ 0 ]; }
		T& back() { return mArr[ mSize - 1 ]; }
		const T& back() const { return mArr[ mSize - 1 ]; }

		T& operator[](size_t idx) { return mArr[ idx ]; }
		const T& operator[](size_t idx) const { return mArr[ idx ]; }

	public:
		void push_back(const T& value)
		{
			if (mSize > mCapaciry)
			{
				if (mCapaciry < DEFAULT_CAP)
					mCapaciry = DEFAULT_CAP;
				else
					mCapaciry *= 2;

				T* newmArr = new T[ mCapaciry ];
				for (size_t i = 0; i < mSize; i++)
				{
					newmArr[ i ] = mArr[ i ];
				}
				delete[] mArr;

				mArr = newmArr;
			}
			mArr[ mSize++ ] = value;
		}
		void push_back(const T&& value)
		{
			if (mSize > mCapaciry)
			{
				if (mCapaciry < DEFAULT_CAP)
					mCapaciry = DEFAULT_CAP;
				else
					mCapaciry *= 2;

				T* newmArr = new T[ mCapaciry ];
				for (size_t i = 0; i < mSize; i++)
				{
					newmArr[ i ] = mArr[ i ];
				}
				delete[] mArr;

				mArr = newmArr;
			}
			mArr[ mSize++ ] = std::move(value);
		}
		void pop_back() { mSize = mSize > 0 ? mSize - 1 : 0; };
		void resize(size_t n, T value = T())
		{
			T* newmArr = new T[ n ];
			mSize = mSize < n ? mSize : n;
			mCapaciry = n;

			for (size_t i = 0; i < mSize; i++)
				newmArr[ i ] = mArr[ i ];
			for (size_t i = mSize; i < mCapaciry; i++)
				newmArr[ i ] = value;

			delete[] mArr;
			mArr = newmArr;
			mSize = n;
		}
		void swap(Vector& other)
		{
			std::swap(mArr, other.mArr);
			std::swap(mSize, other.mSize);
			std::swap(mCapaciry, other.mCapaciry);
		}
		size_t capacity() const { return mCapaciry; }
		size_t size() const { return mSize; }
		bool empty() const { return mSize == 0; }
		void clear() { mSize = 0; }

		bool operator==(const Vector& other) const
		{
			if (mSize != other.mSize)
				return false;

			for (size_t i = 0; i < size; i++)
				if (mArr[ i ] != other[ i ])
					return false;

			return true;
		}
		bool operator!=(const Vector& other) const
		{
			return !(*this == other);
		}
		bool operator< (const Vector& other)
		{
			bool isSame = true;
			size_t minmSize = mSize < other.mSize ? mSize : other.mSize;
			size_t idx = 0;

			for (; idx < minmSize; idx++)
			{
				if (mArr[ idx ] != other[ idx ])
				{
					isSame = false;
					break;
				}
			}

			if (isSame)
			{
				if (mSize < other.mSize)
					return true;
			}
			else
			{
				if (mArr[ idx ] < other[ idx ])
					return true;
			}
			return false;
		}
		bool operator<=(const Vector& other) const
		{
			return !(other < *this);
		}
		bool operator> (const Vector& other) const
		{
			return (other < *this);
		}
		bool operator>=(const Vector& other) const
		{
			return !(*this < other);
		}

	private:
		static constexpr size_t DEFAULT_CAP = 32;
		T* mArr;
		size_t mSize;
		size_t mCapaciry;
	};
}




int main()
{
	ca::Vector<int> vector;
	vector.resize(15);


	vector[ 0 ] = 2;
	vector[ 10 ] = 2;
	vector.clear();
	vector[ 0 ] = 2;

	std::vector<int> stdVector;
	stdVector.resize(15);
	stdVector[ 0 ] = 2;
	stdVector[ 10 ] = 2;
	stdVector.clear();
	//stdVector[ 0 ] = 2;

	return 0;
}