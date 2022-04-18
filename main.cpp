///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author @Patrick Manuel <pamanuel@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(){
    cout << "Starting Fat Cat" << endl;

    ///testing constructors//
    Weight cWeight1 = Weight();
    Weight cWeight2 = Weight(10);
    Weight cWeight3 = Weight(Weight::KILO);
    Weight cWeight4 = Weight(30, Weight::SLUG);
    Weight cWeight5 = Weight(160, 200);
    Weight cWeight6 = Weight(Weight::KILO, 80);
    Weight cWeight7 = Weight(155.5, Weight::SLUG, 225);
/*
    cWeight1.dump();
    cWeight2.dump();
    cWeight3.dump();
    cWeight4.dump();
    cWeight5.dump();
    cWeight6.dump();
    cWeight7.dump();
*/
    ///testing invalid set values///
/*  cWeight2.setWeight(-5);
    cWeight4.setWeight(-10,Weight::SLUG);
    Weight overWeight = Weight(225,135);
*/
    ///testing comparison///
/*  cout << Weight::convertWeight(1, Weight::POUND, Weight::SLUG) << endl;
    cout << Weight::convertWeight(1, Weight::POUND, Weight::KILO) << endl;
    cout << Weight::convertWeight(1, Weight::SLUG, Weight::KILO)  << endl;
    cout << Weight::convertWeight(1, Weight::KILO, Weight::SLUG)  << endl;
    cout << endl;
    ///should be same as above///
    cout << Weight::fromPoundToSlug(1)                              << endl;
    cout << Weight::fromPoundToKilogram(1)                          << endl;
    cout << Weight::fromPoundToKilogram(Weight::fromSlugToPound(1)) << endl;
    cout << Weight::fromPoundToSlug(Weight::fromKilogramToPound(1)) << endl;
    cout << endl;
    ///output should be 1///
    cout << Weight::convertWeight(1, Weight::SLUG, Weight::SLUG)   << endl;
    cout << Weight::convertWeight(1, Weight::POUND, Weight::POUND) << endl;
    cout << Weight::convertWeight(1, Weight::KILO, Weight::KILO)   << endl;
    cout << endl;
*/
    ///testing operators///
    Weight heavyWeight = Weight(10);
    Weight lightWeight = Weight(1);

    bool isEqualTo = (heavyWeight == lightWeight);
    bool isLessThan = (heavyWeight < lightWeight);
/*
    assert(isEqualTo);///should fail
    assert(isLessThan);///should fail
*/
    Weight addTo = (lightWeight += 9);
    cout << addTo.getWeight() << endl;

    bool isequalto = (heavyWeight == addTo);
    bool islessthan = (heavyWeight < addTo);
/*
    assert(isequalto);///should pass
    assert(islessthan);///should pass
*/
    cout << "End of Fat Cat" << endl;

}
