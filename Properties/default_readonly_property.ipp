namespace properties {
  template<typename T>
  constexpr T const& DefaultReadOnlyProperty<T>::get() const {
    return OwningProperty<T>::property;
  }
}
