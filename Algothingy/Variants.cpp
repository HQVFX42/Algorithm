#include <iostream>
#include <tuple>
#include <type_traits>
#include <string>

template<typename... Types>
class Variants
{
	std::tuple<Types...> data;
public:
	Variants(Types... args) : data(args...) {}

	template<typename T>
	T & get()
	{
		return std::get<T>(data);
	}

	template<typename T>
	const T & get() const
	{
		return std::get<T>(data);
	}

	static constexpr size_t size = sizeof...(Types);
};


template<typename... Types>
auto make_variants(Types... args)
{
	return Variants<Types...>(args...);
}

#define MAKE_VARIANTS_1(type0, value0) \
    make_variants((type0)value0)

#define MAKE_VARIANTS_2(type0, value0, type1, value1) \
    make_variants((type0)value0, (type1)value1)

#define MAKE_VARIANTS_3(type0, value0, type1, value1, type2, value2) \
    make_variants((type0)value0, (type1)value1, (type2)value2)

#define MAKE_VARIANTS_4(type0, value0, type1, value1, type2, value2, type3, value3) \
    make_variants((type0)value0, (type1)value1, (type2)value2, (type3)value3)

#define MAKE_VARIANTS_5(type0, value0, type1, value1, type2, value2, type3, value3, type4, value4) \
    make_variants((type0)value0, (type1)value1, (type2)value2, (type3)value3, (type4)value4)

#define GET_VARIANT_ITEM(variants, type, value) \
    value = variants.get<type>()

template<typename Variant, typename... Types>
void verify_variants(const Variant & variants, const Types&... original_values)
{
	bool all_match = true;
	std::cout << "Original values: ";
	((std::cout << original_values << ", "), ...);
	std::cout << "\nRetrieved values: ";

	auto check_value = [ & ] (const auto & original)
		{
			using Type = std::decay_t<decltype(original)>;
			Type retrieved;
			GET_VARIANT_ITEM(variants, Type, retrieved);
			std::cout << retrieved << ", ";
			if (retrieved != original)
			{
				all_match = false;
			}
		};

	(check_value(original_values), ...);

	std::cout << "\n" << (all_match ? "All values match!" : "Values do not match!") << std::endl;
}

int main()
{
	// 3개 요소 테스트
	int a = 0;
	double b = 1.5;
	int * c = &a;
	auto inst1 = MAKE_VARIANTS_3(int, a, double, b, int *, c);
	verify_variants(inst1, a, b, c);

	// 4개 요소 테스트
	std::string d = "hello";
	float e = 3.14f;
	char f = 'A';
	bool g = true;
	auto inst2 = MAKE_VARIANTS_4(std::string, d, float, e, char, f, bool, g);
	verify_variants(inst2, d, e, f, g);

	// 5개 요소 테스트
	long h = 1000000L;
	auto inst3 = MAKE_VARIANTS_5(int, a, double, b, std::string, d, char, f, long, h);
	verify_variants(inst3, a, b, d, f, h);

	return 0;
}