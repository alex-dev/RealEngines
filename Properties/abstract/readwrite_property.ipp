namespace properties {
  namespace abstract {
    template<typename T, typename Child>
    constexpr ReadWriteProperty<T, Child>::operator T&() {
      return (*this)();
    }

    template<typename T, typename Child>
    constexpr T* const ReadWriteProperty<T, Child>::operator->() {
      return &((*this)());
    }

    template<typename T, typename Child>
    constexpr T& ReadWriteProperty<T, Child>::operator()() {
      return static_cast<Child*>(this)->get();
    }

    template<typename T, typename Child>
    constexpr T& ReadWriteProperty<T, Child>::get() {
      return const_cast<T&>(const_cast<Child const*>(static_cast<Child*>(this))->get());
    }
  }
}
