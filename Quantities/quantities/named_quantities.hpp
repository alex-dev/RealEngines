﻿#pragma once
#include "quantities/dimensions/dimensions.hpp"
#include "quantities/quantities/quantity.hpp"

namespace quantities {
  using Length = quantities::Quantity<dimensions::Length>;
  using Mass = quantities::Quantity<dimensions::Mass>;
  using Time = quantities::Quantity<dimensions::Time>;
  using Current = quantities::Quantity<dimensions::Current>;
  using Temperature = quantities::Quantity<dimensions::Temperature>;
  using Amount = quantities::Quantity<dimensions::Amount>;
  using LuminousIntensity = quantities::Quantity<dimensions::LuminousIntensity>;
  using Angle = quantities::Quantity<dimensions::Angle>;

  // The solid angle is really the square of the angle: for instance, the surface
  // element on the sphere is cos(θ) dθ dφ, and the cylinder with radius r and
  // height 2r, whose surface is equal to that of the sphere, has a surface of
  // 2r × 2πr: the steradian is the square of the radian.
  using SolidAngle = Square<Angle>;

  using Speed = Variation<Length>;
  using Acceleration = Variation<Speed>;
  using Momentum = Product<Mass, Speed>;
  using Force = Variation<Momentum>;
  using Stiffness = Quotient<Force, Length>;

  using Energy = Product<Force, Length>;
  using Power = Variation<Energy>;
  using Action = Product<Energy, Time>;

  // There is some ambiguity regarding the choice of units for torque.  We choose
  // to make the moment of inertia free from angles, which introduces a
  // multiplicative angle in the torque.
  // Calls to Wedge in mechanics will often require the result to be multiplied by
  // Radian, and the application of a bivector will often require the result to be
  // divided by Radian.  An inner product of bivectors will occasionally have
  // to be divided by Radian².
  // It's because of the latter rule that torque sometimes has an inverse angle.
  using MomentOfInertia = Product<Square<Length>, Mass>;
  using AngularFrequency = Variation<Angle>;
  using AngularAcceleration = Variation<AngularFrequency>;
  using AngularMomentum = Product<MomentOfInertia, AngularFrequency>;
  using Torque = Variation<AngularMomentum>;

  using GravitationalParameter = Quotient<Exponentiation<Length, 3>, Exponentiation<Time, 2>>;
  using Degree2SphericalHarmonicCoefficient = Product<GravitationalParameter, Exponentiation<Length, 2>>;
  using Degree3SphericalHarmonicCoefficient = Product<GravitationalParameter, Exponentiation<Length, 3>>;

  // Astrodynamics
  using SpecificImpulse = Quotient<Momentum, Mass>;
  using SpecificEnergy = Quotient<Energy, Mass>;
  using SpecificAngularMomentum = Quotient<AngularMomentum, Mass>;

  // Thermodynamics
  using Area = Square<Length>;
  using Volume = Cube<Length>;
  using Pressure = Quotient<Force, Area>;
  using Entropy = Quotient<Energy, Temperature>;
  using Density = Quotient<Mass, Volume>;
  using SpecificVolume = Quotient<Volume, Mass>;
  using MolarVolume = Quotient<Volume, Amount>;

  // Fluid dynamics
  using DynamicViscosity = Product<Pressure, Time>;
  using KinematicViscosity = Quotient<Area, Time>;

  // Chemistry
  using Concentration = Quotient<Amount, Volume>;
  using MolarMass = Quotient<Mass, Amount>;
  using CatalyticActivity = Quotient<Amount, Time>;

  // Optics
  using Wavenumber = Quotient<Angle, Length>;

  // Spectroscopy
  using Frequency = Inverse<Time>;
  using SpectroscopicWavenumber = Inverse<Length>;

  // Electromagnetism
  using Charge = Product<Current, Time>;
  using Voltage = Quotient<Energy, Charge>;
  using Capacitance = Quotient<Charge, Voltage>;
  using Resistance = Quotient<Voltage, Current>;
  using Conductance = Quotient<Current, Voltage>;
  using MagneticFlux = Quotient<Energy, Current>;
  using MagneticFluxDensity = Quotient<MagneticFlux, Area>;
  using Inductance = Quotient<MagneticFlux, Current>;
  using ElectricField = Quotient<Force, Charge>;

  // The angular element for permittivity comes from the integral form of Gauss's
  // law: the surface integral includes a solid angle of one Steradian, the volume
  // integral has no angle whatsoever, the permittivity compensates.
  using Permeability = Product<Quotient<Inductance, Length>, SolidAngle>;
  using Permittivity = Quotient<Quotient<Capacitance, Length>, SolidAngle>;

  using ElectricDisplacementField = Product<ElectricField, Permittivity>;
  using MagneticField = Quotient<MagneticFluxDensity, Permeability>;

  // Radiometry
  using RadiantIntensity = Quotient<Power, SolidAngle>;
  using Radiance = Quotient<RadiantIntensity, Area>;
  using RadiantFlux = Power;
  using RadiantEnergy = Product<RadiantFlux, Time>;
  using Irradiance = Quotient<RadiantFlux, Area>;
  using RadiantExposure = Product<Irradiance, Time>;

  // Photometry
  using Luminance = Quotient<LuminousIntensity, Area>;
  using LuminousFlux = Product<LuminousIntensity, SolidAngle>;
  using LuminousEnergy = Product<LuminousFlux, Time>;
  using Illuminance = Quotient<LuminousFlux, Area>;
  using LuminousExposure = Product<Illuminance, Time>;
  using LuminousEfficacy = Quotient<LuminousFlux, RadiantFlux>;
}
