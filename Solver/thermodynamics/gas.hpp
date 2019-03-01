#pragma once
#include <memory>
#include <default_readwrite_property.hpp>
#include <properties.hpp>
#include "thermodynamics/molecular_gas.hpp"
#include "thermodynamics/quantities.hpp"

namespace solver {
  namespace thermodynamics {
    class Gas {
    public:
      constexpr Gas(std::shared_ptr<MolecularGas>&& gas, Amount n, Mass m);

    private:
      std::shared_ptr<MolecularGas> const gas;

    public:
      /// <summary>Quantity in mole.</summary>
      properties::DefaultReadWriteProperty<Amount> n;

      /// <summary>Mass.</summary>
      properties::DefaultReadWriteProperty<Mass> m;

#pragma region MolecularGas accessors

      struct Name : properties::ReadOnlyProperty<double, Name>, properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr std::string const& get() const;
      } const name{*gas};

      struct γ : properties::ReadOnlyProperty<double, γ>, properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr double const& get() const;
      } const γ{*gas};

      struct Cp : properties::ReadOnlyProperty<Entropy, Cp>, properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr Entropy const& get() const;
      } const Cp{*gas};

      struct Cv : properties::ReadOnlyProperty<Entropy, Cv>, properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr Entropy const& get() const;
      } const Cv{*gas};

      struct R : properties::ReadOnlyProperty<SpecificGasConstant, R>,
                 properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr SpecificGasConstant const& get() const;
      } const R{*gas};

      struct M : properties::ReadOnlyProperty<MolarMass, M>, properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr MolarMass const& get() const;
      } const M{*gas};

      struct UnitMass : properties::ReadOnlyProperty<std::optional<MolarMass>, UnitMass>,
                        properties::ReferencingProperty<MolecularGas> {
        using properties::ReferencingProperty<MolecularGas>::ReferencingProperty;

      protected:
        constexpr std::optional<MolarMass> const& get() const;
      } const unitMass{*gas};

#pragma endregion
    };
  }
}
