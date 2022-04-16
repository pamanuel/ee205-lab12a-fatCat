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
    assert(isWeightValid(maxWeight));
    return maxWeight;
}
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::POUND;
}
void Weight::setWeight(float newWeight) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
}
void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    unitOfWeight = weightUnits;
}
void Weight::setMaxWeight(float newMaxWeight) {
    assert(isWeightValid(newMaxWeight));
    maxWeight =  newMaxWeight;
}

///validation///
bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(checkWeight <= 0){
        return false;
    }
    if(bHasMax){
        assert(checkWeight <= maxWeight);
    }
    return true;
}
bool Weight::validate() const noexcept {
    assert(isWeightValid(weight));
    assert(isWeightValid(maxWeight));
    return false;
}
void Weight::dump() const noexcept {

}

///conversions///
float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND ;;
}
float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}
float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}
float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}
float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    return 0;
}

///operators///
bool Weight::operator==(const Weight &rhs_Weight) const {
    return false;
}
bool Weight::operator<(const Weight &rhs_Weight) const {
    return false;
}
Weight &Weight::operator+=(float rhs_addToWeight) {
}
