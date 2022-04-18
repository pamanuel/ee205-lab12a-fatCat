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

const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL  = "Kilo";
const std::string Weight::SLUG_LABEL  = "Slug";

///constructors///
Weight::Weight() noexcept {
   weight       = UNKNOWN_WEIGHT;
   maxWeight    = UNKNOWN_WEIGHT;
   unitOfWeight = POUND;
   bIsKnown     = false;
   bHasMax      = false;
   assert(validate());
}
Weight::Weight(float newWeight) {
    setWeight(newWeight);
    maxWeight    = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
    bIsKnown     = true;
    bHasMax      = false;
    assert(validate());
}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    weight       = UNKNOWN_WEIGHT;
    maxWeight    = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    bIsKnown     = false;
    bHasMax      = false;
    assert(validate());
}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    setWeight(newWeight, newUnitOfWeight);
    maxWeight    = UNKNOWN_WEIGHT;
    bIsKnown     = true;
    bHasMax      = false;
    assert(validate());
}
Weight::Weight(float newWeight, float newMaxWeight) {
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
    unitOfWeight = POUND;
    bIsKnown     = true;
    bHasMax      = true;
    assert(validate());
}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    weight       = UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    unitOfWeight = newUnitOfWeight;///redundant but has warning if not included.
    bIsKnown     = false;
    bHasMax      = true;
    assert(validate());
}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setWeight(newWeight, newUnitOfWeight);
    setMaxWeight(newMaxWeight);
    bIsKnown     = true;
    bHasMax      = true;
    assert(validate());
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
        weight = convertWeight(newWeight,Weight::POUND, weightUnits);
        unitOfWeight = weightUnits;
}
void Weight::setMaxWeight(float newMaxWeight) {
    assert(validate());
    maxWeight =  newMaxWeight;
    bHasMax = true;
}

///validation///
bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(checkWeight <= 0 && checkWeight > Weight::maxWeight){
        cout << "invalid weight" << endl;
        return false;
    }
    if(bHasMax){
        assert(checkWeight <= maxWeight);
    }
    return true;
}
bool Weight::validate() const noexcept {
    if(isWeightValid(weight)){
        return true;
    }
    if(isWeightValid(maxWeight)){
        return true;
    }
    else{
        cout << "Weight not Valid" << endl;
        return false;
    }
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
                case POUND: return fromWeight;///no conversion
                case KILO:  return fromPoundToKilogram(fromWeight);
                case SLUG:  return fromPoundToSlug(fromWeight);
            }
        case KILO:
            switch(toUnit){
                case POUND: return fromKilogramToPound(fromWeight);
                case KILO:  return fromWeight;///no conversion
                case SLUG:  return fromPoundToSlug(fromKilogramToPound(fromWeight));
            }///kilo to pound, pound to slug
        case SLUG:
            switch(toUnit){
                case POUND: return fromSlugToPound(fromWeight);
                case KILO:  return fromPoundToKilogram(fromSlugToPound(fromWeight));
                case SLUG:  return fromWeight;///no conversion
            }///slug to pound, pound to kilo;
    }
    return 0.0;
}

///operators///
std::ostream& operator<<( ostream& lhs_stream,Weight::UnitOfWeight rhs_UnitOfWeight );
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
    this->weight += rhs_addToWeight;
    return *this;
}
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

void Weight::dump() const noexcept {
    cout << setw(80) << setfill('=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight" , "this" )        << this            << endl ;
    FORMAT_LINE( "Weight", "isKnown" )      << isWeightKnown() << endl ;
    FORMAT_LINE( "Weight", "weight" )       << getWeight()     << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << getWeightUnit() << endl ;
    FORMAT_LINE( "Weight", "hasMax" )       << hasMaxWeight()  << endl ;
    FORMAT_LINE( "Weight", "maxWeight" )    << getMaxWeight()  << endl ;

}

