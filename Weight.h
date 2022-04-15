///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author @Patrick Manuel <pamanuel@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>

class Weight;

class Weight {
public: ////////////// Enumerations //////////////
    /// A unit of measure for weight
    enum UnitOfWeight { POUND, KILO, SLUG };

    static const float KILOS_IN_A_POUND ;
    static const float SLUGS_IN_A_POUND ;
    static const float UNKNOWN_WEIGHT;

    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;

private:
    bool bIsKnown;
    bool bHasMax;
    enum UnitOfWeight unitOfWeight;
    float weight;
    float maxWeight;

public:///constructors///
    Weight() noexcept;
    Weight(float newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

public:///getters and setters///
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);

public:///validation///

};

