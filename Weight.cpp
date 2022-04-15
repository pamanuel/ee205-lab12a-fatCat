///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author @Patrick Manuel <pamanuel@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "Weight.h"

const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;
const float Weight::UNKNOWN_WEIGHT   = -1;

const std::string POUND_LABEL = "Pound";
const std::string KILO_LABEL  = "Kilo";
const std::string SLUG_LABEL  = "Slug";

///constructors///
Weight::Weight() noexcept {

}
Weight::Weight(float newWeight) {

}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {

}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {

}
Weight::Weight(float newWeight, float newMaxWeight) {

}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {

}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setMaxWeight( newMaxWeight );
    assert( validate() );
}

///getters and setters///
bool Weight::isWeightKnown() const noexcept {
    return false;
}
bool Weight::hasMaxWeight() const noexcept {
    return false;
}
float Weight::getWeight() const noexcept {
    return 0;
}
float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return 0;
}
float Weight::getMaxWeight() const noexcept {
    return 0;
}
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::POUND;
}
void Weight::setWeight(float newWeight) {

}
void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {

}
void Weight::setMaxWeight(float newMaxWeight) {

}
