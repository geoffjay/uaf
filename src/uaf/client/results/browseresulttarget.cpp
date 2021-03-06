/* This file is part of the UAF (Unified Architecture Framework) project.
 *
 * Copyright (C) 2012 Wim Pessemier (Institute of Astronomy, KULeuven)
 *
 * Project website: http://www.ster.kuleuven.be/uaf
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "uaf/client/results/browseresulttarget.h"


namespace uafc
{
    using namespace uaf;
    using namespace uafc;
    using std::string;
    using std::stringstream;
    using std::vector;
    using std::size_t;


    // Constructor
    // =============================================================================================
    BrowseResultTarget::BrowseResultTarget()
    : autoBrowsedNext(0)
    {}


    // Get a string representation
    // =============================================================================================
    string BrowseResultTarget::toString(const string& indent, size_t colon) const
    {
        stringstream ss;

        ss << indent << " - clientConnectionId";
        ss << fillToPos(ss, colon);
        ss << ": " << int(clientConnectionId) << "\n";

        ss << indent << " - status";
        ss << fillToPos(ss, colon);
        ss << ": " << status.toString() << "\n";

        ss << indent << " - continuationPoint";
        ss << fillToPos(ss, colon);
        ss << ": " << int(continuationPoint.length()) << " bytes\n";

        ss << indent << " - autoBrowsedNext";
        ss << fillToPos(ss, colon);
        ss << ": " << int(autoBrowsedNext) << "\n";

        // don't fully log all references because the resulting string could be huge!
        ss << indent << " - references[]";

        if (references.size() == 0)
        {
            ss << fillToPos(ss, colon);
            ss << ": []";
        }
        else
        {
            for (size_t i = 0; i < references.size(); i++)
            {
                ss << "\n" << indent << "   " << " - references[" << int(i) << "]\n";
                ss << references[i].toString(indent + "      ", colon);
            }
        }

        return ss.str();
    }


    // operator==
    // =============================================================================================
    bool operator==(const BrowseResultTarget& object1, const BrowseResultTarget& object2)
    {
        return    object1.clientConnectionId == object2.clientConnectionId
               && object1.status             == object2.status
               && object1.continuationPoint  == object2.continuationPoint
               && object1.autoBrowsedNext    == object2.autoBrowsedNext
               && object1.references         == object2.references;
    }


    // operator!=
    // =============================================================================================
    bool operator!=(const BrowseResultTarget& object1, const BrowseResultTarget& object2)
    {
        return !(object1 == object2);
    }


    // operator<
    // =============================================================================================
    bool operator<(const BrowseResultTarget& object1, const BrowseResultTarget& object2)
    {
        if (object1.status != object2.status)
            return object1.status < object2.status;
        else if (object1.continuationPoint != object2.continuationPoint)
            return object1.continuationPoint < object2.continuationPoint;
        else if (object1.autoBrowsedNext != object2.autoBrowsedNext)
            return object1.autoBrowsedNext < object2.autoBrowsedNext;
        else if (object1.clientConnectionId != object2.clientConnectionId)
            return object1.clientConnectionId < object2.clientConnectionId;
        else
            return object1.references < object2.references;
    }


}
