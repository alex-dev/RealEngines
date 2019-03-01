namespace base {
  template<typename Child>
  constexpr Child& simple_augmented_assignment<Child>::operator++() {
    ++static_cast<Child*>(this)->value;
    return *this;
  }

  template<typename Child>
  constexpr Child& simple_augmented_assignment<Child>::operator--() {
    --static_cast<Child*>(this)->value;
    return *this;
  }

  template<typename Child>
  constexpr Child simple_augmented_assignment<Child>::operator++(int) {
    Child clone = *this;
    ++static_cast<Child*>(this)->value;
    return clone;
  }

  template<typename Child>
  constexpr Child simple_augmented_assignment<Child>::operator--(int) {
    Child clone = *this;
    --static_cast<Child*>(this)->value;
    return clone;
  }

  template<typename Child>
  constexpr Child& simple_augmented_assignment<Child>::operator+=(Child const& other) {
    static_cast<Child*>(this)->value += other.value;
    return *this;
  }

  template<typename Child>
  constexpr Child& simple_augmented_assignment<Child>::operator-=(Child const& other) {
    static_cast<Child*>(this)->value -= other.value;
    return *this;
  }
}
