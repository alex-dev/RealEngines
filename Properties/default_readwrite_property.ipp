namespace properties {
  template<typename T>
  constexpr T const& DefaultReadWriteProperty<T>::get() const {
    return OwningProperty<T>::property;
  }

  template<typename T>
  constexpr T& DefaultReadWriteProperty<T>::get() {
    return OwningProperty<T>::property;
  }

  template<typename T>
  constexpr T& DefaultReadWriteProperty<T>::set(T const& value) {
    return OwningProperty<T>::property = value;
  }

  template<typename T>
  constexpr T& DefaultReadWriteProperty<T>::set(T&& value) {
    return OwningProperty<T>::property = value;
  }
}
