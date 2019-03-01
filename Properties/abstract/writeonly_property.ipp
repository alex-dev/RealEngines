namespace properties {
  namespace abstract {
    template<typename T, typename Child>
    constexpr T& WriteOnlyProperty<T, Child>::operator=(T const& value) {
      return (*this)(value);
    }

    template<typename T, typename Child>
    constexpr T& WriteOnlyProperty<T, Child>::operator=(T&& value) {
      return (*this)(std::forward(value));
    }

    template<typename T, typename Child>
    constexpr T& WriteOnlyProperty<T, Child>::operator()(T const& value) {
      return static_cast<Child*>(this)->set(value);
    }

    template<typename T, typename Child>
    constexpr T& WriteOnlyProperty<T, Child>::operator()(T&& value) {
      return static_cast<Child*>(this)->set(value);
    }

    template<typename T, typename Child>
    constexpr T& WriteOnlyProperty<T, Child>::set(T const& value) {
      return static_cast<Child*>(this)->set(T{value});
    }
  }
}
