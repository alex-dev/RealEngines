namespace base {
  template<typename Child, typename Numeric>
  constexpr Child & advanced_augmented_assignment<Child, Numeric>::operator*=(Numeric const & other) {
    static_cast<Child *>(this)->value *= other;
    return *this;
  }

  template<typename Child, typename Numeric>
  constexpr Child & advanced_augmented_assignment<Child, Numeric>::operator/=(Numeric const & other) {
    static_cast<Child *>(this)->value /= other;
    return *this;
  }
}
