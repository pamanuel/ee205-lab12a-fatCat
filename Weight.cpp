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
#include <iostream>
#include <cassert>
#include <iomanip>
#include "Weight.h"

using namespace std;

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
    float currentWeight = convertWeight(weight, unitOfWeight, weightUnits);
    return currentWeight;
}
float Weight::getMaxWeight() const noexcept {
    assert(isWeightValid(maxWeight));
    return maxWeight;
}
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
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

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

void Weight::dump() const noexcept {
    cout << setw(80) << setfill('=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight" , "this" )        << this            << endl ;
    FORMAT_LINE( "Weight", "isKnown" )      << bIsKnown        << endl ;
    FORMAT_LINE( "Weight", "weight" )       << getWeight()     << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << getWeightUnit() << endl ;
    FORMAT_LINE( "Weight", "hasMax" )       << bHasMax         << endl ;
    FORMAT_LINE( "Weight", "maxWeight" )    << getMaxWeight()  << endl ;

}

///conversions///
float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
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
    switch(fromUnit){
        case POUND:
            switch(toUnit){
                case POUND: return POUND;
                case KILO:  return fromPoundToKilogram(fromWeight);
                case SLUG:  return fromPoundToSlug(fromWeight);
            }
            case KILO:
            switch(toUnit){
                case POUND: return fromKilogramToPound(fromWeight);
                case KILO:  return KILO;
                case SLUG:  return fromPoundToSlug(fromKilogramToPound(fromWeight));
            }
            case SLUG:
                switch(toUnit){
                    case POUND: return fromSlugToPound(fromWeight);
                    case KILO:  return fromPoundToKilogram(fromSlugToPound(fromWeight));
                    case SLUG:  return SLUG;
            }
    }
    return 0.0;
}

///operators///
std::ostream& operator<<( ostream& lhs_stream,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}
///bIsKnown ? is to check if there is a weight to compare
bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight == rhs_weight;
}
bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight <= rhs_weight;
}
Weight &Weight::operator+=(float rhs_addToWeight) {
    weight += rhs_addToWeight;
    return *this;
}
