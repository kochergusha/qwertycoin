// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The Qwertycoin developers
//
// This file is part of Qwertycoin.
//
// Qwertycoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Qwertycoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Qwertycoin.  If not, see <http://www.gnu.org/licenses/>.

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "../Common/StringUtils.h"
#include "../CryptoNoteConfig.h"
#include "../version/version.h"

#pragma once

namespace CryptoNote
{

	namespace
	{	
		std::vector<std::string> versionSplit = Common::StringUtils::split(PROJECT_VERSION, ".");
		std::vector<std::string> uIdStringList = {GENESIS_COINBASE_TX_HEX, versionSplit[0], versionSplit[1]};
		std::string uID = Common::StringUtils::join(uIdStringList, ".");

		boost::uuids::uuid name;
		boost::uuids::name_generator gen(name);
		boost::uuids::uuid u = gen(uID);
	}
	const static boost::uuids::uuid QWERTYCOIN_NETWORK = u;
}

