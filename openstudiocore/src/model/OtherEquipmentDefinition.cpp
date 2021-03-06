/**********************************************************************
 *  Copyright (c) 2008-2014, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <model/OtherEquipmentDefinition.hpp>
#include <model/OtherEquipmentDefinition_Impl.hpp>

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_OtherEquipment_Definition_FieldEnums.hxx>

#include <utilities/math/FloatCompare.hpp>

#include <utilities/core/Assert.hpp>

#include <boost/algorithm/string.hpp>  

namespace openstudio {
namespace model {

namespace detail {

  ATTRIBUTE_IMPLEMENTATION(1,0,0,designLevel,DesignLevel,
                           OtherEquipmentDefinition,0,OS_OtherEquipment_Definition,DesignLevel)

  ATTRIBUTE_IMPLEMENTATION(1,0,0,wattsperSpaceFloorArea,WattsperSpaceFloorArea,
                           OtherEquipmentDefinition,0,OS_OtherEquipment_Definition,WattsperSpaceFloorArea)

  ATTRIBUTE_IMPLEMENTATION(1,0,0,wattsperPerson,WattsperPerson,
                           OtherEquipmentDefinition,0,OS_OtherEquipment_Definition,WattsperPerson)

  ATTRIBUTE_IMPLEMENTATION(0,1,0,fractionRadiant,FractionRadiant,
                           OtherEquipmentDefinition,0,OS_OtherEquipment_Definition,FractionRadiant)

  ATTRIBUTE_IMPLEMENTATION(0,1,0,fractionLatent,FractionLatent,
                           OtherEquipmentDefinition,0,OS_OtherEquipment_Definition,FractionLatent)

  ATTRIBUTE_IMPLEMENTATION(0,1,0,fractionLost,FractionLost,
                           OtherEquipmentDefinition,0,OS_OtherEquipment_Definition,FractionLost)


  OtherEquipmentDefinition_Impl::OtherEquipmentDefinition_Impl(const IdfObject& idfObject, 
                                                               Model_Impl* model, 
                                                               bool keepHandle)
    : SpaceLoadDefinition_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == OtherEquipmentDefinition::iddObjectType());
  }

  OtherEquipmentDefinition_Impl::OtherEquipmentDefinition_Impl(
      const openstudio::detail::WorkspaceObject_Impl& other,
      Model_Impl* model,
      bool keepHandle)
    : SpaceLoadDefinition_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == OtherEquipmentDefinition::iddObjectType());
  }

  OtherEquipmentDefinition_Impl::OtherEquipmentDefinition_Impl(
      const OtherEquipmentDefinition_Impl& other,
      Model_Impl* model,
      bool keepHandle)
    : SpaceLoadDefinition_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& OtherEquipmentDefinition_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType OtherEquipmentDefinition_Impl::iddObjectType() const {
    return OtherEquipmentDefinition::iddObjectType();
  }

  std::string OtherEquipmentDefinition_Impl::designLevelCalculationMethod() const {
    boost::optional<std::string> value = getString(OS_OtherEquipment_DefinitionFields::DesignLevelCalculationMethod,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> OtherEquipmentDefinition_Impl::designLevel() const {
    return getDouble(OS_OtherEquipment_DefinitionFields::DesignLevel,true);
  }

  boost::optional<double> OtherEquipmentDefinition_Impl::wattsperSpaceFloorArea() const {
    return getDouble(OS_OtherEquipment_DefinitionFields::WattsperSpaceFloorArea,true);
  }

  boost::optional<double> OtherEquipmentDefinition_Impl::wattsperPerson() const {
    return getDouble(OS_OtherEquipment_DefinitionFields::WattsperPerson,true);
  }

  double OtherEquipmentDefinition_Impl::fractionLatent() const {
    boost::optional<double> value = getDouble(OS_OtherEquipment_DefinitionFields::FractionLatent,true);
    OS_ASSERT(value);
    return value.get();
  }

  //bool OtherEquipmentDefinition_Impl::isFractionLatentDefaulted() const {
  //  return isEmpty(OS_OtherEquipment_DefinitionFields::FractionLatent);
  //}

  double OtherEquipmentDefinition_Impl::fractionRadiant() const {
    boost::optional<double> value = getDouble(OS_OtherEquipment_DefinitionFields::FractionRadiant,true);
    OS_ASSERT(value);
    return value.get();
  }

  //bool OtherEquipmentDefinition_Impl::isFractionRadiantDefaulted() const {
  //  return isEmpty(OS_OtherEquipment_DefinitionFields::FractionRadiant);
  //}

  double OtherEquipmentDefinition_Impl::fractionLost() const {
    boost::optional<double> value = getDouble(OS_OtherEquipment_DefinitionFields::FractionLost,true);
    OS_ASSERT(value);
    return value.get();
  }

  //bool OtherEquipmentDefinition_Impl::isFractionLostDefaulted() const {
  //  return isEmpty(OS_OtherEquipment_DefinitionFields::FractionLost);
  //}

  bool OtherEquipmentDefinition_Impl::setDesignLevel(boost::optional<double> designLevel) {
    bool result = false;
    if (designLevel) {
      result = setString(OS_OtherEquipment_DefinitionFields::DesignLevelCalculationMethod,"EquipmentLevel");
      OS_ASSERT(result);
      result = setDouble(OS_OtherEquipment_DefinitionFields::DesignLevel, designLevel.get());
      OS_ASSERT(result);
      result = setWattsperSpaceFloorArea(boost::none);
      OS_ASSERT(result);
      result = setWattsperPerson(boost::none);
    } else {
      result = setString(OS_OtherEquipment_DefinitionFields::DesignLevel, "");
    }
  
    return result;
  }

  bool OtherEquipmentDefinition_Impl::setWattsperSpaceFloorArea(boost::optional<double> wattsperSpaceFloorArea) {
    bool result = false;
    if (wattsperSpaceFloorArea) {
      result = setString(OS_OtherEquipment_DefinitionFields::DesignLevelCalculationMethod,"Watts/Area");
      OS_ASSERT(result);
      setDesignLevel(boost::none);
      result = setDouble(OS_OtherEquipment_DefinitionFields::WattsperSpaceFloorArea, wattsperSpaceFloorArea.get());
      OS_ASSERT(result);
      result = setWattsperPerson(boost::none);
    } else {
      result = setString(OS_OtherEquipment_DefinitionFields::WattsperSpaceFloorArea, "");
    }
    return result;
  }

  bool OtherEquipmentDefinition_Impl::setWattsperPerson(boost::optional<double> wattsperPerson) {
    bool result = false;
    if (wattsperPerson) {
      result = setString(OS_OtherEquipment_DefinitionFields::DesignLevelCalculationMethod,"Watts/Person");
      OS_ASSERT(result);
      setDesignLevel(boost::none);
      result = setWattsperSpaceFloorArea(boost::none);
      OS_ASSERT(result);
      result = setDouble(OS_OtherEquipment_DefinitionFields::WattsperPerson, wattsperPerson.get());
    } else {
      result = setString(OS_OtherEquipment_DefinitionFields::WattsperPerson, "");
    }
    return result;
  }

  bool OtherEquipmentDefinition_Impl::setFractionLatent(double fractionLatent) {
    bool result = false;
    result = setDouble(OS_OtherEquipment_DefinitionFields::FractionLatent, fractionLatent);
    return result;
  }

  //void OtherEquipmentDefinition_Impl::resetFractionLatent() {
  //  bool result = setString(OS_OtherEquipment_DefinitionFields::FractionLatent, "");
  //  OS_ASSERT(result);
  //}

  bool OtherEquipmentDefinition_Impl::setFractionRadiant(double fractionRadiant) {
    bool result = false;
    result = setDouble(OS_OtherEquipment_DefinitionFields::FractionRadiant, fractionRadiant);
    return result;
  }

  //void OtherEquipmentDefinition_Impl::resetFractionRadiant() {
  //  bool result = setString(OS_OtherEquipment_DefinitionFields::FractionRadiant, "");
  //  OS_ASSERT(result);
  //}

  bool OtherEquipmentDefinition_Impl::setFractionLost(double fractionLost) {
    bool result = false;
    result = setDouble(OS_OtherEquipment_DefinitionFields::FractionLost, fractionLost);
    return result;
  }

  //void OtherEquipmentDefinition_Impl::resetFractionLost() {
  //  bool result = setString(OS_OtherEquipment_DefinitionFields::FractionLost, "");
  //  OS_ASSERT(result);
  //}

  double OtherEquipmentDefinition_Impl::getDesignLevel(double floorArea, double numPeople) const {
    std::string method = designLevelCalculationMethod();

    if (method == "EquipmentLevel") {
      return designLevel().get();
    }
    else if (method == "Watts/Area") {
      return wattsperSpaceFloorArea().get() * floorArea;
    }
    else if (method == "Watts/Person") {
      return wattsperPerson().get() * numPeople;
    }

    OS_ASSERT(false);
    return 0.0;
  }

  double OtherEquipmentDefinition_Impl::getPowerPerFloorArea(double floorArea, 
                                                                  double numPeople) const
  {
    std::string method = designLevelCalculationMethod();

    if (method == "EquipmentLevel") {
      if (equal(floorArea,0.0)) {
        LOG_AND_THROW("Calculation would require division by zero.");
      }
      return designLevel().get() / floorArea;
    }
    else if (method == "Watts/Area") {
      return wattsperSpaceFloorArea().get();
    }
    else if (method == "Watts/Person") {
      if (equal(floorArea,0.0)) {
        LOG_AND_THROW("Calculation would require division by zero.");
      }
      return wattsperPerson().get() * numPeople / floorArea;
    }

    OS_ASSERT(false);
    return 0.0;
  }

  double OtherEquipmentDefinition_Impl::getPowerPerPerson(double floorArea, double numPeople) const
  {
    std::string method = designLevelCalculationMethod();

    if (method == "EquipmentLevel") {
      if (equal(numPeople,0.0)) {
        LOG_AND_THROW("Calculation would require division by zero.");
      }
      return designLevel().get() / numPeople;
    }
    else if (method == "Watts/Area") {
      if (equal(numPeople,0.0)) {
        LOG_AND_THROW("Calculation would require division by zero.");
      }
      return wattsperSpaceFloorArea().get() * floorArea / numPeople;
    }
    else if (method == "Watts/Person") {
      return wattsperPerson().get();
    }

    OS_ASSERT(false);
    return 0.0;
  }
 
  bool OtherEquipmentDefinition_Impl::setDesignLevelCalculationMethod(const std::string& method, 
                                                                      double floorArea, 
                                                                      double numPeople)
  {
    std::string wmethod(method);
    boost::to_lower(wmethod);

    if (wmethod == "equipmentlevel") {
      setDesignLevel(getDesignLevel(floorArea,numPeople));
      return true;
    }
    else if (wmethod == "watts/area") {
      return setWattsperSpaceFloorArea(getPowerPerFloorArea(floorArea,numPeople));
    }
    else if (wmethod == "watts/person") {
      return setWattsperPerson(getPowerPerPerson(floorArea,numPeople));
    }
    
    return false;
  }

} // detail

OtherEquipmentDefinition::OtherEquipmentDefinition(const Model& model)
  : SpaceLoadDefinition(OtherEquipmentDefinition::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::OtherEquipmentDefinition_Impl>());
  setDesignLevel(0.0);
}

IddObjectType OtherEquipmentDefinition::iddObjectType() {
  IddObjectType result(IddObjectType::OS_OtherEquipment_Definition);
  return result;
}

std::vector<std::string> OtherEquipmentDefinition::validDesignLevelCalculationMethodValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_OtherEquipment_DefinitionFields::DesignLevelCalculationMethod);
}

std::string OtherEquipmentDefinition::designLevelCalculationMethod() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->designLevelCalculationMethod();
}

boost::optional<double> OtherEquipmentDefinition::designLevel() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->designLevel();
}

boost::optional<double> OtherEquipmentDefinition::wattsperSpaceFloorArea() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->wattsperSpaceFloorArea();
}

boost::optional<double> OtherEquipmentDefinition::wattsperPerson() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->wattsperPerson();
}

double OtherEquipmentDefinition::fractionLatent() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->fractionLatent();
}

bool OtherEquipmentDefinition::isFractionLatentDefaulted() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->isFractionLatentDefaulted();
}

double OtherEquipmentDefinition::fractionRadiant() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->fractionRadiant();
}

bool OtherEquipmentDefinition::isFractionRadiantDefaulted() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->isFractionRadiantDefaulted();
}

double OtherEquipmentDefinition::fractionLost() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->fractionLost();
}

bool OtherEquipmentDefinition::isFractionLostDefaulted() const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->isFractionLostDefaulted();
}

void OtherEquipmentDefinition::setDesignLevel(double designLevel) {
  getImpl<detail::OtherEquipmentDefinition_Impl>()->setDesignLevel(designLevel);
}

bool OtherEquipmentDefinition::setWattsperSpaceFloorArea(double wattsperSpaceFloorArea) {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->setWattsperSpaceFloorArea(wattsperSpaceFloorArea);
}

bool OtherEquipmentDefinition::setWattsperPerson(double wattsperPerson) {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->setWattsperPerson(wattsperPerson);
}

bool OtherEquipmentDefinition::setFractionLatent(double fractionLatent) {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->setFractionLatent(fractionLatent);
}

void OtherEquipmentDefinition::resetFractionLatent() {
  getImpl<detail::OtherEquipmentDefinition_Impl>()->resetFractionLatent();
}

bool OtherEquipmentDefinition::setFractionRadiant(double fractionRadiant) {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->setFractionRadiant(fractionRadiant);
}

void OtherEquipmentDefinition::resetFractionRadiant() {
  getImpl<detail::OtherEquipmentDefinition_Impl>()->resetFractionRadiant();
}

bool OtherEquipmentDefinition::setFractionLost(double fractionLost) {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->setFractionLost(fractionLost);
}

void OtherEquipmentDefinition::resetFractionLost() {
  getImpl<detail::OtherEquipmentDefinition_Impl>()->resetFractionLost();
}

double OtherEquipmentDefinition::getDesignLevel(double floorArea, double numPeople) const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->getDesignLevel(floorArea,numPeople);
}

double OtherEquipmentDefinition::getPowerPerFloorArea(double floorArea, double numPeople) const
{
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->getPowerPerFloorArea(floorArea,numPeople);
}

double OtherEquipmentDefinition::getPowerPerPerson(double floorArea, double numPeople) const {
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->getPowerPerPerson(floorArea,numPeople);
}

bool OtherEquipmentDefinition::setDesignLevelCalculationMethod(const std::string& method, 
                                     double floorArea, 
                                     double numPeople)
{
  return getImpl<detail::OtherEquipmentDefinition_Impl>()->setDesignLevelCalculationMethod(method,floorArea,numPeople);
}

/// @cond
OtherEquipmentDefinition::OtherEquipmentDefinition(boost::shared_ptr<detail::OtherEquipmentDefinition_Impl> impl)
  : SpaceLoadDefinition(impl)
{}
/// @endcond

} // model
} // openstudio

