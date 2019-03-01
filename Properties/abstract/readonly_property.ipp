namespace properties {
  namespace abstract {
    template<typename T, typename Child>
    constexpr ReadOnlyProperty<T, Child>::operator T const&() const {
      return (*this)();
    }

    template<typename T, typename Child>
    constexpr T const* const ReadOnlyProperty<T, Child>::operator->() const {
      return &((*this)());
    }

    template<typename T, typename Child>
    constexpr T const& ReadOnlyProperty<T, Child>::operator()() const {
      return static_cast<Child*>(this)->get();
    }
  }
}
