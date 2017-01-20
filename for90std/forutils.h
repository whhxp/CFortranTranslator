#pragma once

// WARNING: DEPRECATED
#if (defined(_MSC_VER) && _MSC_VER <= 1900)
namespace std {
	template<class F, class...Args>
	struct is_callable
	{
		template<class U> static auto test(U* p) -> decltype((*p)(std::declval<Args>()...), void(), std::true_type());
		template<class U> static auto test(...) -> decltype(std::false_type());

		static constexpr bool value = decltype(test<F>(0))::value;
	};
}
#endif

namespace for90std {

#define CHECK_AND_SET(A, INITIAL) if (!A.inited()) { \
		A = INITIAL; \
	}

	template<typename T, typename Return, Return(T::*)()>
	struct func_matcher;

	template<typename T, typename Return, Return(T::*)()const>
	struct const_func_matcher;
	
#define MAKE_FUNC_TEST(TYPENAME, MATCHERNAME) struct is_##TYPENAME { \
		template<typename T> \
		constexpr static bool test(MATCHERNAME<T>) {\
			return true; \
		} \
		template<typename T> \
		constexpr static bool test(...){ \
			return false; \
		} \
	};

	template <typename T>
	struct function_traits
		: public function_traits<decltype(&T::operator())>
	{};
	// For generic types, directly use the result of the signature of its 'operator()'

	template <typename ClassType, typename ReturnType, typename... Args>
	struct function_traits<ReturnType(ClassType::*)(Args...) const>
	{
		// we specialize for pointers to member function
		enum { arity = sizeof...(Args) };
		// arity is the number of arguments.
		typedef ReturnType result_type;
		template <size_t i>
		struct arg
		{
			typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
			// the i-th argument is equivalent to the i-th tuple element of a tuple
			// composed of those arguments.
		};
	};

	template <typename T>
	class for_reference_wrapper {
	public:
		// types
		typedef T type;

		// construct/copy/destroy
		for_reference_wrapper(T& ref) noexcept : _ptr(std::addressof(ref)) {}
		for_reference_wrapper(T&&) = delete;
		for_reference_wrapper(const for_reference_wrapper&) noexcept = default;
		for_reference_wrapper() {}

		// assignment
		for_reference_wrapper& operator=(const for_reference_wrapper& x) noexcept = default;

		// access
		operator T& () const noexcept { return *_ptr; }
		T& get() const noexcept { return *_ptr; }

		void change(T& ref) noexcept {
			_ptr = std::addressof(ref);
		}

		template< class... ArgTypes >
		typename std::result_of<T&(ArgTypes&&...)>::type
			operator() (ArgTypes&&... args) const {
			return std::invoke(get(), std::forward<ArgTypes>(args)...);
		}

	private:
		T* _ptr;
	};


	template <int I>
	struct Int2Type
	{
		enum { value = I };
	};
}