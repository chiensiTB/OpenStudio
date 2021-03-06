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

#include <gtest/gtest.h>

#include <model/test/ModelFixture.hpp>
#include <model/Model_Impl.hpp>
#include <model/Space.hpp>
#include <model/InternalMass.hpp>
#include <model/InternalMass_Impl.hpp>
#include <model/InternalMassDefinition.hpp>
#include <model/InternalMassDefinition_Impl.hpp>

#include <boost/foreach.hpp>

using namespace openstudio;
using namespace openstudio::model;

TEST_F(ModelFixture, InternalMass)
{
  Model model;

  InternalMassDefinition definition(model);
  InternalMass internalMass(definition);
  EXPECT_EQ(2u, model.numObjects());
}
