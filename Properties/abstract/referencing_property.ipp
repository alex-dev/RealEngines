namespace properties {
  namespace abstract {
    template<typename R>
    constexpr ReferencingProperty<R>::ReferencingProperty(R& reference) : reference(reference) {}
  }
}
