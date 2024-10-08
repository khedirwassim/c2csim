#ifndef INCLUDE_SUMOINTEGRATOR_CORE_EGO_H
#define INCLUDE_SUMOINTEGRATOR_CORE_EGO_H


#include "../types/compound.h"
#include "Concern.h"
#include "Sumo.h"

#include <string>


namespace sumointegrator {

///
/// @AUTHOR            Mattia Affabris - mattia.affabris@antemotion.com
/// @DATE              2018-11-26
/// @MODDATE           2018-12-14
/// @VERSION           0.4.0-alpha4
/// @MODVERSION        4
/// @COPYRIGHT         Copyright (C) (2018) AnteMotion
///
/// @BRIEF  Exposes facilities related to the ego entity.
///
/// Handles the ego entity within SUMO's simulation. It is assumed only one "main" ego entity exists, although it is
/// possible to alter the state of other entities as if they were ego entities themselves.
///
/// @NOTE  May only be accessed as a pointer member class of `sumointegrator::Sumo` (`sumointegrator::Sumo::ego`).
///
class Sumo::Ego : private Sumo::Concern {
public:
    Ego(TraCIAPI&);
    ~Ego();

    ///
    /// @BRIEF  Subscribe to the data feed of neighbouring vehicles.
    ///
    /// Data is received from only those vehicles within a circle cantered in the ego vehicle and with the given radius.
    /// Once subscribed to a data feed, on each SUMO simulation tick that data is made available through `poll()`.
    ///
    /// @UNITS
    /// `start`   seconds (s)\n
    /// `end`     seconds (s)\n
    /// 'radius'  meters (m)
    ///
    /// @PARAM[in]      request  The requested data.
    /// @PARAM[in]      start    The time the subscription starts taking effect.
    /// @PARAM[in]      end      The time the subscription stops taking effect.
    /// @PARAM[in]      radius   The radius of the circle area.
    ///
    /// @DEBUG
    /// `DEBUG_INFO` - Subscription target.
    /// `DEBUG_DATA` - Number of vehicles in the radius.
    ///
    void subscribe(const std::vector<int>&, const double, const double, const double);

    ///
    /// @BRIEF  Poll the neighbouring vehicles data feed.
    ///
    /// It is assumed a subscription was previously made with `subscribe()`. The data is collected in an `std::map`
    /// (`types::Datamaps`) and can be index-accessed for usage; the amount of datasets received depends on
    /// the number of vehicles within the radius specified with `subscribe()`.
    ///
    /// @RETURN  An `std::map` of entries, the keys being the vehicles and the corresponding content being an `std::map`
    ///          of entries with all the requested data.
    ///
    /// @NOTE  No failure state is returned if no subscription was previously made.
    ///
    /// @DEBUG
    /// `DEBUG_DATA` - Number of datapoints received from the subscription for each vehicle.
    ///
    types::Datamaps poll();

    ///
    /// @BRIEF  Move an ego entity.
    ///
    /// The ego entity is placed at the given coordinates, with no interpolation or extrapolation made on its state
    /// vectors between subsequent `move()`s. SUMO is capable of interacting with this ego entity based on (subsequent)
    /// position(s) alone. The yaw angle is set by SUMO based on internal logic.
    ///
    /// @NOTE  The `id` of the SUMO entity acting as the ego entity must be set first with `set_id()`.
    ///
    /// @UNITS
    /// `position`  meters (m), meters (m), meters (m)
    ///
    /// @PARAM[in]      position  The target `3D` position.
    ///
    /// @THROWS  types::RuntimeException  If the `id` is not set.
    ///
    /// @SEE `move(const std::string&, const Position&)`
    ///
    void move(const types::Position&);

    ///
    /// @BRIEF  Move an ego entity.
    ///
    /// The ego entity is placed at the given coordinates, with no interpolation or extrapolation made on its state
    /// vectors between subsequent `move()`s. SUMO is capable of interacting with this ego entity based on (subsequent)
    /// position(s) alone.
    ///
    /// @NOTE  The `id` of the SUMO entity acting as the ego entity must be set first with `set_id()`.
    ///
    /// @UNITS
    /// `position`  meters (m), meters (m), meters (m)
    /// `yaw`       radians (rad)
    ///
    /// @PARAM[in]      position  The target `3D` position.
    /// @PARAM[in]      yaw       The target yaw angle.
    ///
    /// @THROWS  types::RuntimeException  If the `id` is not set.
    ///
    /// @SEE `move(const std::string&, const Position&)`
    ///
    void move(const types::Position&, const double yaw);

    ///
    /// @BRIEF  Move an ego entity.
    ///
    /// The SUMO entity identified by its `id` is placed in the given coordinates, with no interpolation or
    /// extrapolation made on its state vectors between subsequent `move(const std::string&, const Position&)`. This
    /// method is useful to move entities other than the "main" ego.
    ///
    /// @UNITS
    /// `position`  meters (m), meters (m), meters (m)
    ///
    /// @PARAM[in]      id        The `id` of the SUMO entity.
    /// @PARAM[in]      position  The target `3D` position.
    ///
    /// @SEE `move(const Position&)`
    ///
    void move(const std::string&, const types::Position&);

    ///
    /// @BRIEF  Get the `id` of the ego entity.
    ///
    /// @RETURN  The `id` of the ego entity.
    ///
    std::string get_id();

    ///
    /// @BRIEF  Set the `id` of the ego entity.
    ///
    /// @PARAM[in]      id  The `id` of the ego entity.
    ///
    void set_id(const std::string&);

private:
    std::string id;
};

}  // namespace sumointegrator


#endif  //INCLUDE_SUMOINTEGRATOR_CORE_EGO_H
