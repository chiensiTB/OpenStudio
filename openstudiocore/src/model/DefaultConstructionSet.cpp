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

#include <model/DefaultConstructionSet.hpp>
#include <model/DefaultConstructionSet_Impl.hpp>

#include <model/Model.hpp>
#include <model/Model_Impl.hpp>
#include <model/PlanarSurface.hpp>
#include <model/PlanarSurface_Impl.hpp>
#include <model/ConstructionBase.hpp>
#include <model/ConstructionBase_Impl.hpp>
#include <model/DefaultSubSurfaceConstructions.hpp>
#include <model/DefaultSubSurfaceConstructions_Impl.hpp>
#include <model/DefaultSurfaceConstructions.hpp>
#include <model/DefaultSurfaceConstructions_Impl.hpp>
#include <model/Surface.hpp>
#include <model/Surface_Impl.hpp>
#include <model/SubSurface.hpp>
#include <model/SubSurface_Impl.hpp>
#include <model/InteriorPartitionSurface.hpp>
#include <model/InteriorPartitionSurface_Impl.hpp>
#include <model/InteriorPartitionSurfaceGroup.hpp>
#include <model/InteriorPartitionSurfaceGroup_Impl.hpp>
#include <model/ShadingSurface.hpp>
#include <model/ShadingSurface_Impl.hpp>
#include <model/ShadingSurfaceGroup.hpp>
#include <model/ShadingSurfaceGroup_Impl.hpp>

#include <utilities/idd/OS_DefaultConstructionSet_FieldEnums.hxx>

#include <utilities/core/Assert.hpp>

using openstudio::istringEqual;

namespace openstudio {
namespace model {

namespace detail {

  DefaultConstructionSet_Impl::DefaultConstructionSet_Impl(const IdfObject& idfObject, Model_Impl* model, bool keepHandle)
    : ResourceObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == DefaultConstructionSet::iddObjectType());
  }

  DefaultConstructionSet_Impl::DefaultConstructionSet_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                           Model_Impl* model,
                                                           bool keepHandle)
    : ResourceObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == DefaultConstructionSet::iddObjectType());
  }

  DefaultConstructionSet_Impl::DefaultConstructionSet_Impl(const DefaultConstructionSet_Impl& other,
                                                           Model_Impl* model,
                                                           bool keepHandle)
    : ResourceObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& DefaultConstructionSet_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType DefaultConstructionSet_Impl::iddObjectType() const {
    return DefaultConstructionSet::iddObjectType();
  }

  boost::optional<DefaultSurfaceConstructions> DefaultConstructionSet_Impl::defaultExteriorSurfaceConstructions() const
  {
    return getObject<ModelObject>().getModelObjectTarget<DefaultSurfaceConstructions>(OS_DefaultConstructionSetFields::DefaultExteriorSurfaceConstructionsName);
  }

  boost::optional<DefaultSurfaceConstructions> DefaultConstructionSet_Impl::defaultInteriorSurfaceConstructions() const
  {
    return getObject<ModelObject>().getModelObjectTarget<DefaultSurfaceConstructions>(OS_DefaultConstructionSetFields::DefaultInteriorSurfaceConstructionsName);
  }

  boost::optional<DefaultSurfaceConstructions> DefaultConstructionSet_Impl::defaultGroundContactSurfaceConstructions() const
  {
    return getObject<ModelObject>().getModelObjectTarget<DefaultSurfaceConstructions>(OS_DefaultConstructionSetFields::DefaultGroundContactSurfaceConstructionsName);
  }

  boost::optional<DefaultSubSurfaceConstructions> DefaultConstructionSet_Impl::defaultExteriorSubSurfaceConstructions() const
  {
    return getObject<ModelObject>().getModelObjectTarget<DefaultSubSurfaceConstructions>(OS_DefaultConstructionSetFields::DefaultExteriorSubSurfaceConstructionsName);
  }

  boost::optional<DefaultSubSurfaceConstructions> DefaultConstructionSet_Impl::defaultInteriorSubSurfaceConstructions() const
  {
    return getObject<ModelObject>().getModelObjectTarget<DefaultSubSurfaceConstructions>(OS_DefaultConstructionSetFields::DefaultInteriorSubSurfaceConstructionsName);
  }

  boost::optional<ConstructionBase> DefaultConstructionSet_Impl::interiorPartitionConstruction() const
  {
    return getObject<ModelObject>().getModelObjectTarget<ConstructionBase>(OS_DefaultConstructionSetFields::InteriorPartitionConstructionName);
  }

  boost::optional<ConstructionBase> DefaultConstructionSet_Impl::spaceShadingConstruction() const
  {
    return getObject<ModelObject>().getModelObjectTarget<ConstructionBase>(OS_DefaultConstructionSetFields::SpaceShadingConstructionName);
  }

  boost::optional<ConstructionBase> DefaultConstructionSet_Impl::buildingShadingConstruction() const
  {
    return getObject<ModelObject>().getModelObjectTarget<ConstructionBase>(OS_DefaultConstructionSetFields::BuildingShadingConstructionName);
  }

  boost::optional<ConstructionBase> DefaultConstructionSet_Impl::siteShadingConstruction() const
  {
    return getObject<ModelObject>().getModelObjectTarget<ConstructionBase>(OS_DefaultConstructionSetFields::SiteShadingConstructionName);
  }

  bool DefaultConstructionSet_Impl::setDefaultExteriorSurfaceConstructions(const DefaultSurfaceConstructions& defaultSurfaceConstructions)
  {
    return setPointer(OS_DefaultConstructionSetFields::DefaultExteriorSurfaceConstructionsName, defaultSurfaceConstructions.handle());
  }

  void DefaultConstructionSet_Impl::resetDefaultExteriorSurfaceConstructions()
  {
    setString(OS_DefaultConstructionSetFields::DefaultExteriorSurfaceConstructionsName, "");
  }

  bool DefaultConstructionSet_Impl::setDefaultInteriorSurfaceConstructions(const DefaultSurfaceConstructions& defaultSurfaceConstructions)
  {
    return setPointer(OS_DefaultConstructionSetFields::DefaultInteriorSurfaceConstructionsName, defaultSurfaceConstructions.handle());
  }

  void DefaultConstructionSet_Impl::resetDefaultInteriorSurfaceConstructions()
  {
    setString(OS_DefaultConstructionSetFields::DefaultInteriorSurfaceConstructionsName, "");
  }

  bool DefaultConstructionSet_Impl::setDefaultGroundContactSurfaceConstructions(const DefaultSurfaceConstructions& defaultSurfaceConstructions)
  {
    return setPointer(OS_DefaultConstructionSetFields::DefaultGroundContactSurfaceConstructionsName, defaultSurfaceConstructions.handle());
  }

  void DefaultConstructionSet_Impl::resetDefaultGroundContactSurfaceConstructions()
  {
    setString(OS_DefaultConstructionSetFields::DefaultGroundContactSurfaceConstructionsName, "");
  }

  bool DefaultConstructionSet_Impl::setDefaultExteriorSubSurfaceConstructions(const DefaultSubSurfaceConstructions& defaultSubSurfaceConstructions)
  {
    return setPointer(OS_DefaultConstructionSetFields::DefaultExteriorSubSurfaceConstructionsName, defaultSubSurfaceConstructions.handle());
  }

  void DefaultConstructionSet_Impl::resetDefaultExteriorSubSurfaceConstructions()
  {
    setString(OS_DefaultConstructionSetFields::DefaultExteriorSubSurfaceConstructionsName, "");
  }

  bool DefaultConstructionSet_Impl::setDefaultInteriorSubSurfaceConstructions(const DefaultSubSurfaceConstructions& defaultSubSurfaceConstructions)
  {
    return setPointer(OS_DefaultConstructionSetFields::DefaultInteriorSubSurfaceConstructionsName, defaultSubSurfaceConstructions.handle());
  }

  void DefaultConstructionSet_Impl::resetDefaultInteriorSubSurfaceConstructions()
  {
    setString(OS_DefaultConstructionSetFields::DefaultInteriorSubSurfaceConstructionsName, "");
  }

  bool DefaultConstructionSet_Impl::setInteriorPartitionConstruction(const ConstructionBase& construction)
  {
    return setPointer(OS_DefaultConstructionSetFields::InteriorPartitionConstructionName, construction.handle());
  }

  void DefaultConstructionSet_Impl::resetInteriorPartitionConstruction()
  {
    setString(OS_DefaultConstructionSetFields::InteriorPartitionConstructionName, "");
  }

  bool DefaultConstructionSet_Impl::setSpaceShadingConstruction(const ConstructionBase& construction)
  {
    return setPointer(OS_DefaultConstructionSetFields::SpaceShadingConstructionName, construction.handle());
  }

  void DefaultConstructionSet_Impl::resetSpaceShadingConstruction()
  {
    setString(OS_DefaultConstructionSetFields::SpaceShadingConstructionName, "");
  }

  bool DefaultConstructionSet_Impl::setBuildingShadingConstruction(const ConstructionBase& construction)
  {
    return setPointer(OS_DefaultConstructionSetFields::BuildingShadingConstructionName, construction.handle());
  }

  void DefaultConstructionSet_Impl::resetBuildingShadingConstruction()
  {
    setString(OS_DefaultConstructionSetFields::BuildingShadingConstructionName, "");
  }

  bool DefaultConstructionSet_Impl::setSiteShadingConstruction(const ConstructionBase& construction)
  {
    return setPointer(OS_DefaultConstructionSetFields::SiteShadingConstructionName, construction.handle());
  }

  void DefaultConstructionSet_Impl::resetSiteShadingConstruction()
  {
    setString(OS_DefaultConstructionSetFields::SiteShadingConstructionName, "");
  }

  boost::optional<ConstructionBase> DefaultConstructionSet_Impl::getDefaultConstruction(const PlanarSurface& planarSurface) const
  {
    boost::optional<ConstructionBase> result;
    if (planarSurface.optionalCast<Surface>()){

      boost::optional<DefaultSurfaceConstructions> defaultSurfaceConstructions;
      std::string outsideBoundaryCondition = planarSurface.cast<Surface>().outsideBoundaryCondition();
      if (istringEqual("Outdoors", outsideBoundaryCondition)){
        defaultSurfaceConstructions = this->defaultExteriorSurfaceConstructions();
      }else if (istringEqual("Ground", outsideBoundaryCondition)){
        // DLM: do we want to apply this for all ground surfaces?
        defaultSurfaceConstructions = this->defaultGroundContactSurfaceConstructions();
      }else if (istringEqual("Surface", outsideBoundaryCondition)){
        defaultSurfaceConstructions = this->defaultInteriorSurfaceConstructions();
      }
      
      if (defaultSurfaceConstructions){
        std::string surfaceType = planarSurface.cast<Surface>().surfaceType();
        if (istringEqual("Floor", surfaceType)){
          result = defaultSurfaceConstructions->floorConstruction();
        }else if (istringEqual("Wall", surfaceType)){
          result = defaultSurfaceConstructions->wallConstruction();
        }else if (istringEqual("RoofCeiling", surfaceType)){
          result = defaultSurfaceConstructions->roofCeilingConstruction();
        }
      }
      
    }else if (planarSurface.optionalCast<SubSurface>()){

      boost::optional<DefaultSubSurfaceConstructions> defaultSubSurfaceConstructions;
      boost::optional<Surface> surface = planarSurface.cast<SubSurface>().surface();
      if (surface){
        std::string outsideBoundaryCondition = surface->outsideBoundaryCondition();
        if (istringEqual("Outdoors", outsideBoundaryCondition)){
          defaultSubSurfaceConstructions = this->defaultExteriorSubSurfaceConstructions();
        }else if (istringEqual("Surface", outsideBoundaryCondition)){
          defaultSubSurfaceConstructions = this->defaultInteriorSubSurfaceConstructions();
        }
      }

      if (defaultSubSurfaceConstructions){

        std::string subSurfaceType = planarSurface.cast<SubSurface>().subSurfaceType();
        if (istringEqual("FixedWindow", subSurfaceType)){
          result = defaultSubSurfaceConstructions->fixedWindowConstruction();
        }else if (istringEqual("OperableWindow", subSurfaceType)){
          result = defaultSubSurfaceConstructions->operableWindowConstruction();
        }else if (istringEqual("Door", subSurfaceType)){
          result = defaultSubSurfaceConstructions->doorConstruction();
        }else if (istringEqual("GlassDoor", subSurfaceType)){
          result = defaultSubSurfaceConstructions->glassDoorConstruction();
        }else if (istringEqual("OverheadDoor", subSurfaceType)){
          result = defaultSubSurfaceConstructions->overheadDoorConstruction();
        }else if (istringEqual("Skylight", subSurfaceType)){
          result = defaultSubSurfaceConstructions->skylightConstruction();
        }else if (istringEqual("TubularDaylightDome", subSurfaceType)){
          result = defaultSubSurfaceConstructions->tubularDaylightDomeConstruction();
        }else if (istringEqual("TubularDaylightDiffuser", subSurfaceType)){
          result = defaultSubSurfaceConstructions->tubularDaylightDiffuserConstruction();
        }
      }

    }else if (planarSurface.optionalCast<InteriorPartitionSurface>()){

      result = this->interiorPartitionConstruction();

    }else if (planarSurface.optionalCast<ShadingSurface>()){
      
      boost::optional<ShadingSurfaceGroup> shadingSurfaceGroup = planarSurface.cast<ShadingSurface>().shadingSurfaceGroup();
      if (shadingSurfaceGroup){
        std::string shadingSurfaceType = shadingSurfaceGroup->shadingSurfaceType();
        if (istringEqual("Space", shadingSurfaceType)){
          result = this->spaceShadingConstruction();
        }else if (istringEqual("Building", shadingSurfaceType)){
          result = this->buildingShadingConstruction();
        }else if (istringEqual("Site", shadingSurfaceType)){
          result = this->siteShadingConstruction();
        }
      }

    }else{
      LOG_AND_THROW("Unknown planar surface: " << planarSurface.briefDescription());
    }

    return result;
  }

  
  void DefaultConstructionSet_Impl::merge(const DefaultConstructionSet& other)
  {
    boost::optional<DefaultSurfaceConstructions> thisSurfaceConstructions;
    boost::optional<DefaultSurfaceConstructions> otherSurfaceConstructions;
    boost::optional<DefaultSubSurfaceConstructions> thisSubSurfaceConstructions;
    boost::optional<DefaultSubSurfaceConstructions> otherSubSurfaceConstructions;

    otherSurfaceConstructions = other.defaultExteriorSurfaceConstructions();
    if (otherSurfaceConstructions){
      thisSurfaceConstructions = this->defaultExteriorSurfaceConstructions();
      if (!thisSurfaceConstructions){
        this->setDefaultExteriorSurfaceConstructions(*otherSurfaceConstructions);
      }else{
        if (thisSurfaceConstructions->handle() == otherSurfaceConstructions->handle()){
          // no op
        }else {
          if (thisSurfaceConstructions->numSources() > 1){
            thisSurfaceConstructions = thisSurfaceConstructions->clone(this->model()).cast<DefaultSurfaceConstructions>();
            this->setDefaultExteriorSurfaceConstructions(*thisSurfaceConstructions);
          }
          thisSurfaceConstructions->merge(*otherSurfaceConstructions);
        }
      }
    }

    otherSurfaceConstructions = other.defaultInteriorSurfaceConstructions();
    if (otherSurfaceConstructions){
      thisSurfaceConstructions = this->defaultInteriorSurfaceConstructions();
      if (!thisSurfaceConstructions){
        this->setDefaultInteriorSurfaceConstructions(*otherSurfaceConstructions);
      }else{
        if (thisSurfaceConstructions->handle() == otherSurfaceConstructions->handle()){
          // no op
        }else {
          if (thisSurfaceConstructions->numSources() > 1){
            thisSurfaceConstructions = thisSurfaceConstructions->clone(this->model()).cast<DefaultSurfaceConstructions>();
            this->setDefaultInteriorSurfaceConstructions(*thisSurfaceConstructions);
          }
          thisSurfaceConstructions->merge(*otherSurfaceConstructions);
        }
      }
    }

    otherSurfaceConstructions = other.defaultGroundContactSurfaceConstructions();
    if (otherSurfaceConstructions){
      thisSurfaceConstructions = this->defaultGroundContactSurfaceConstructions();
      if (!thisSurfaceConstructions){
        this->setDefaultGroundContactSurfaceConstructions(*otherSurfaceConstructions);
      }else{
        if (thisSurfaceConstructions->handle() == otherSurfaceConstructions->handle()){
          // no op
        }else {
          if (thisSurfaceConstructions->numSources() > 1){
            thisSurfaceConstructions = thisSurfaceConstructions->clone(this->model()).cast<DefaultSurfaceConstructions>();
            this->setDefaultGroundContactSurfaceConstructions(*thisSurfaceConstructions);
          }
          thisSurfaceConstructions->merge(*otherSurfaceConstructions);
        }
      }
    }

    otherSubSurfaceConstructions = other.defaultExteriorSubSurfaceConstructions();
    if (otherSubSurfaceConstructions){
      thisSubSurfaceConstructions = this->defaultExteriorSubSurfaceConstructions();
      if (!thisSubSurfaceConstructions){
        this->setDefaultExteriorSubSurfaceConstructions(*otherSubSurfaceConstructions);
      }else{
        if (thisSubSurfaceConstructions->handle() == otherSubSurfaceConstructions->handle()){
          // no op
        }else {
          if (thisSubSurfaceConstructions->numSources() > 1){
            thisSubSurfaceConstructions = thisSubSurfaceConstructions->clone(this->model()).cast<DefaultSubSurfaceConstructions>();
            this->setDefaultExteriorSubSurfaceConstructions(*thisSubSurfaceConstructions);
          }
          thisSubSurfaceConstructions->merge(*otherSubSurfaceConstructions);
        }
      }
    }

    otherSubSurfaceConstructions = other.defaultInteriorSubSurfaceConstructions();
    if (otherSubSurfaceConstructions){
      thisSubSurfaceConstructions = this->defaultInteriorSubSurfaceConstructions();
      if (!thisSubSurfaceConstructions){
        this->setDefaultInteriorSubSurfaceConstructions(*otherSubSurfaceConstructions);
      }else{
        if (thisSubSurfaceConstructions->handle() == otherSubSurfaceConstructions->handle()){
          // no op
        }else {
          if (thisSubSurfaceConstructions->numSources() > 1){
            thisSubSurfaceConstructions = thisSubSurfaceConstructions->clone(this->model()).cast<DefaultSubSurfaceConstructions>();
            this->setDefaultInteriorSubSurfaceConstructions(*thisSubSurfaceConstructions);
          }
          thisSubSurfaceConstructions->merge(*otherSubSurfaceConstructions);
        }
      }
    }

    boost::optional<ConstructionBase> construction;
    
    if (!(this->interiorPartitionConstruction())){
      construction = other.interiorPartitionConstruction();
      if (construction){
        this->setInteriorPartitionConstruction(*construction);
      }
    }

    if (!(this->spaceShadingConstruction())){
      construction = other.spaceShadingConstruction();
      if (construction){
        this->setSpaceShadingConstruction(*construction);
      }
    }

    if (!(this->buildingShadingConstruction())){
      construction = other.buildingShadingConstruction();
      if (construction){
        this->setBuildingShadingConstruction(*construction);
      }
    }

    if (!(this->siteShadingConstruction())){
      construction = other.siteShadingConstruction();
      if (construction){
        this->setSiteShadingConstruction(*construction);
      }
    }

  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::defaultExteriorSurfaceConstructionsAsModelObject() const {
    OptionalModelObject result;
    OptionalDefaultSurfaceConstructions intermediate = defaultExteriorSurfaceConstructions();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::defaultInteriorSurfaceConstructionsAsModelObject() const {
    OptionalModelObject result;
    OptionalDefaultSurfaceConstructions intermediate = defaultInteriorSurfaceConstructions();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::defaultGroundContactSurfaceConstructionsAsModelObject() const {
    OptionalModelObject result;
    OptionalDefaultSurfaceConstructions intermediate = defaultGroundContactSurfaceConstructions();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::defaultExteriorSubSurfaceConstructionsAsModelObject() const {
    OptionalModelObject result;
    OptionalDefaultSubSurfaceConstructions intermediate = defaultExteriorSubSurfaceConstructions();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::defaultInteriorSubSurfaceConstructionsAsModelObject() const {
    OptionalModelObject result;
    OptionalDefaultSubSurfaceConstructions intermediate = defaultInteriorSubSurfaceConstructions();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::interiorPartitionConstructionAsModelObject() const {
    OptionalModelObject result;
    OptionalConstructionBase intermediate = interiorPartitionConstruction();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::spaceShadingConstructionAsModelObject() const {
    OptionalModelObject result;
    OptionalConstructionBase intermediate = spaceShadingConstruction();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::buildingShadingConstructionAsModelObject() const {
    OptionalModelObject result;
    OptionalConstructionBase intermediate = buildingShadingConstruction();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  boost::optional<ModelObject> DefaultConstructionSet_Impl::siteShadingConstructionAsModelObject() const {
    OptionalModelObject result;
    OptionalConstructionBase intermediate = siteShadingConstruction();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  bool DefaultConstructionSet_Impl::setDefaultExteriorSurfaceConstructionsAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalDefaultSurfaceConstructions intermediate = modelObject->optionalCast<DefaultSurfaceConstructions>();
      if (intermediate) {
        return setDefaultExteriorSurfaceConstructions(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetDefaultExteriorSurfaceConstructions();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setDefaultInteriorSurfaceConstructionsAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalDefaultSurfaceConstructions intermediate = modelObject->optionalCast<DefaultSurfaceConstructions>();
      if (intermediate) {
        return setDefaultInteriorSurfaceConstructions(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetDefaultInteriorSurfaceConstructions();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setDefaultGroundContactSurfaceConstructionsAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalDefaultSurfaceConstructions intermediate = modelObject->optionalCast<DefaultSurfaceConstructions>();
      if (intermediate) {
        return setDefaultGroundContactSurfaceConstructions(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetDefaultGroundContactSurfaceConstructions();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setDefaultExteriorSubSurfaceConstructionsAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalDefaultSubSurfaceConstructions intermediate = modelObject->optionalCast<DefaultSubSurfaceConstructions>();
      if (intermediate) {
        return setDefaultExteriorSubSurfaceConstructions(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetDefaultExteriorSubSurfaceConstructions();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setDefaultInteriorSubSurfaceConstructionsAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalDefaultSubSurfaceConstructions intermediate = modelObject->optionalCast<DefaultSubSurfaceConstructions>();
      if (intermediate) {
        return setDefaultInteriorSubSurfaceConstructions(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetDefaultInteriorSubSurfaceConstructions();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setInteriorPartitionConstructionAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalConstructionBase intermediate = modelObject->optionalCast<ConstructionBase>();
      if (intermediate) {
        return setInteriorPartitionConstruction(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetInteriorPartitionConstruction();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setSpaceShadingConstructionAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalConstructionBase intermediate = modelObject->optionalCast<ConstructionBase>();
      if (intermediate) {
        return setSpaceShadingConstruction(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetSpaceShadingConstruction();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setBuildingShadingConstructionAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalConstructionBase intermediate = modelObject->optionalCast<ConstructionBase>();
      if (intermediate) {
        return setBuildingShadingConstruction(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetBuildingShadingConstruction();
    }
    return true;
  }

  bool DefaultConstructionSet_Impl::setSiteShadingConstructionAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalConstructionBase intermediate = modelObject->optionalCast<ConstructionBase>();
      if (intermediate) {
        return setSiteShadingConstruction(*intermediate);
      }
      else {
        return false;
      }
    }
    else {
      resetSiteShadingConstruction();
    }
    return true;
  }

} // detail

DefaultConstructionSet::DefaultConstructionSet(const Model& model)
  : ResourceObject(DefaultConstructionSet::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::DefaultConstructionSet_Impl>());
}

IddObjectType DefaultConstructionSet::iddObjectType() {
  IddObjectType result(IddObjectType::OS_DefaultConstructionSet);
  return result;
}

boost::optional<DefaultSurfaceConstructions> DefaultConstructionSet::defaultExteriorSurfaceConstructions() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->defaultExteriorSurfaceConstructions();
}

boost::optional<DefaultSurfaceConstructions> DefaultConstructionSet::defaultInteriorSurfaceConstructions() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->defaultInteriorSurfaceConstructions();
}

boost::optional<DefaultSurfaceConstructions> DefaultConstructionSet::defaultGroundContactSurfaceConstructions() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->defaultGroundContactSurfaceConstructions();
}

boost::optional<DefaultSubSurfaceConstructions> DefaultConstructionSet::defaultExteriorSubSurfaceConstructions() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->defaultExteriorSubSurfaceConstructions();
}

boost::optional<DefaultSubSurfaceConstructions> DefaultConstructionSet::defaultInteriorSubSurfaceConstructions() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->defaultInteriorSubSurfaceConstructions();
}

boost::optional<ConstructionBase> DefaultConstructionSet::interiorPartitionConstruction() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->interiorPartitionConstruction();
}

boost::optional<ConstructionBase> DefaultConstructionSet::spaceShadingConstruction() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->spaceShadingConstruction();
}

boost::optional<ConstructionBase> DefaultConstructionSet::buildingShadingConstruction() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->buildingShadingConstruction();
}

boost::optional<ConstructionBase> DefaultConstructionSet::siteShadingConstruction() const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->siteShadingConstruction();
}

bool DefaultConstructionSet::setDefaultExteriorSurfaceConstructions(const DefaultSurfaceConstructions& defaultSurfaceConstructions){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setDefaultExteriorSurfaceConstructions(defaultSurfaceConstructions);
}

void DefaultConstructionSet::resetDefaultExteriorSurfaceConstructions(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetDefaultExteriorSurfaceConstructions();
}

bool DefaultConstructionSet::setDefaultInteriorSurfaceConstructions(const DefaultSurfaceConstructions& defaultSurfaceConstructions){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setDefaultInteriorSurfaceConstructions(defaultSurfaceConstructions);
}

void DefaultConstructionSet::resetDefaultInteriorSurfaceConstructions(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetDefaultInteriorSurfaceConstructions();
}

bool DefaultConstructionSet::setDefaultGroundContactSurfaceConstructions(const DefaultSurfaceConstructions& defaultSurfaceConstructions){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setDefaultGroundContactSurfaceConstructions(defaultSurfaceConstructions);
}

void DefaultConstructionSet::resetDefaultGroundContactSurfaceConstructions(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetDefaultGroundContactSurfaceConstructions();
}

bool DefaultConstructionSet::setDefaultExteriorSubSurfaceConstructions(const DefaultSubSurfaceConstructions& defaultSubSurfaceConstructions){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setDefaultExteriorSubSurfaceConstructions(defaultSubSurfaceConstructions);
}

void DefaultConstructionSet::resetDefaultExteriorSubSurfaceConstructions(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetDefaultExteriorSubSurfaceConstructions();
}

bool DefaultConstructionSet::setDefaultInteriorSubSurfaceConstructions(const DefaultSubSurfaceConstructions& defaultSubSurfaceConstructions){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setDefaultInteriorSubSurfaceConstructions(defaultSubSurfaceConstructions);
}

void DefaultConstructionSet::resetDefaultInteriorSubSurfaceConstructions(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetDefaultInteriorSubSurfaceConstructions();
}

bool DefaultConstructionSet::setInteriorPartitionConstruction(const ConstructionBase& construction){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setInteriorPartitionConstruction(construction);
}

void DefaultConstructionSet::resetInteriorPartitionConstruction(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetInteriorPartitionConstruction();
}

bool DefaultConstructionSet::setSpaceShadingConstruction(const ConstructionBase& construction){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setSpaceShadingConstruction(construction);
}

void DefaultConstructionSet::resetSpaceShadingConstruction(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetSpaceShadingConstruction();
}

bool DefaultConstructionSet::setBuildingShadingConstruction(const ConstructionBase& construction){
  return getImpl<detail::DefaultConstructionSet_Impl>()->setBuildingShadingConstruction(construction);
}

void DefaultConstructionSet::resetBuildingShadingConstruction(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetBuildingShadingConstruction();
}

bool DefaultConstructionSet::setSiteShadingConstruction(const ConstructionBase& construction){
 return getImpl<detail::DefaultConstructionSet_Impl>()->setSiteShadingConstruction(construction);
}

void DefaultConstructionSet::resetSiteShadingConstruction(){
  getImpl<detail::DefaultConstructionSet_Impl>()->resetSiteShadingConstruction();
}

boost::optional<ConstructionBase> DefaultConstructionSet::getDefaultConstruction(const PlanarSurface& planarSurface) const{
  return getImpl<detail::DefaultConstructionSet_Impl>()->getDefaultConstruction(planarSurface);
}
  
void DefaultConstructionSet::merge(const DefaultConstructionSet& other){
  getImpl<detail::DefaultConstructionSet_Impl>()->merge(other);
}

/// @cond
DefaultConstructionSet::DefaultConstructionSet(boost::shared_ptr<detail::DefaultConstructionSet_Impl> impl)
  : ResourceObject(impl)
{}
/// @endcond


} // model
} // openstudio

