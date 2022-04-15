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
   weight       = UNKNOWN_WEIGHT;
   maxWeight    = UNKNOWN_WEIGHT;
   unitOfWeight = POUND;
   bIsKnown     = false;
   bHasMax      = false;
}
Weight::Weight(float newWeight) {
    weight       = newWeight;
    maxWeight    = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
    bIsKnown     = true;
    bHasMax      = false;
}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    weight       = UNKNOWN_WEIGHT;
    maxWeight    = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    bIsKnown     = false;
    bHasMax      = false;

}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    weight       = newWeight;
    maxWeight    = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    bIsKnown     = true;
    bHasMax      = false;
}
Weight::Weight(float newWeight, float newMaxWeight) {
    weight       = newWeight;
    maxWeight    = newMaxWeight;
    unitOfWeight = POUND;
    bIsKnown     = true;
    bHasMax      = true;
}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    weight       = UNKNOWN_WEIGHT;
    maxWeight    = newMaxWeight;
    unitOfWeight = newUnitOfWeight;
    bIsKnown     = false;
    bHasMax      = true;
}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    weight       = newWeight;
    maxWeight    = newMaxWeight;
    unitOfWeight = newUnitOfWeight;
    bIsKnown     = true;
    bHasMax      = true;
}
///getters and setters///
bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}
bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}
float Weight::getWeight() const noexcept {
    return weight;
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
