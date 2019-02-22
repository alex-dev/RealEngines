namespace properties {
  template<typename T, typename Child>
  constexpr AbstractReadOnlyProperty<T, Child>::operator T const &() const {
    return static_cast<Child *>(this)();
  }

  template<typename T, typename Child>
  constexpr AbstractReadOnlyProperty<T, Child>::operator T &() {
    return static_cast<Child *>(this)();
  }

  template<typename T, typename Child>
  constexpr T const & AbstractReadOnlyProperty<T, Child>::operator() const {
    return static_cast<Child *>(this)->get();
  }

  template<typename T, typename Child>
  constexpr T & AbstractReadOnlyProperty<T, Child>::operator() {
    return static_cast<Child *>(this)->get();
  }

  template<typename T, typename Child, typename Char, typename Traits = std::char_traits<Char>>
  std::basic_ostream<Char, Traits> & operator<<(std::basic_ostream<Char, Traits> & stream,
	                                            AbstractReadOnlyProperty<T, Child> const & value) {
    return stream << static_cast<Child *>(&value)->get();
  }
}
