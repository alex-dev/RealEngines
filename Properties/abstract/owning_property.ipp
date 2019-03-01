namespace properties {
  namespace abstract {
    template<typename T>
    constexpr OwningProperty<T>::OwningProperty(T const& property) : property(property) {}

    template<typename T>
    constexpr OwningProperty<T>::OwningProperty(T&& property) : property(property) {}
  }
}
